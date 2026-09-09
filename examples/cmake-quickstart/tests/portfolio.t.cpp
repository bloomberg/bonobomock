// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2026 Bloomberg Finance LP
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <clock.h>
#include <portfolio.h>
#include <pricefeed.h>

#include <bonobomock_api.h>
#include <bsl_memory.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Return;
using ::testing::StrEq;

namespace {

// 2025-01-01T00:00:00Z. Any fixed instant will do -- the point is that the test
// picks it rather than the machine's clock.
const long long k_FIXED_NOW = 1735689600LL;

} // namespace

// `Portfolio::value()` reaches a live price feed and the system clock, neither
// of which is injected: they are a free function and a static member function
// called directly. BonoboMock replaces both at their entry points, so the test
// is fast, deterministic, and offline -- with no change to the library.
TEST(PortfolioTest, ValuesEveryHoldingAtTheLatestPrice)
{
    // The template parameter is the signature of the function being mocked.
    // A static member function has a plain free-function signature.
    bsl::shared_ptr<GMock<double(const char*)> > feed = BONOBO_MOCK(&fetchLatestPrice);
    bsl::shared_ptr<GMock<long long()> > clock = BONOBO_MOCK(&Clock::nowUtcSeconds);

    // Matching the ticker rather than `_` is what makes the test catch a wrong
    // symbol being forwarded to the feed.
    EXPECT_CALL(*feed, BONOBO_MOCK_FUNCTION(StrEq("IBM"))).WillOnce(Return(100.0));
    EXPECT_CALL(*feed, BONOBO_MOCK_FUNCTION(StrEq("MSFT"))).WillOnce(Return(50.0));
    EXPECT_CALL(*clock, BONOBO_MOCK_FUNCTION()).WillOnce(Return(k_FIXED_NOW));

    Portfolio portfolio;
    portfolio.addHolding("IBM", 10);
    portfolio.addHolding("MSFT", 4);

    const Valuation valuation = portfolio.value();

    EXPECT_DOUBLE_EQ(1200.0, valuation.totalUsd);
    EXPECT_EQ(k_FIXED_NOW, valuation.asOfUtcSeconds);
}

// The price cache is an implementation detail with no observable output --
// counting calls on the mock is the only way to pin it down.
TEST(PortfolioTest, PricesEachTickerOncePerValuation)
{
    bsl::shared_ptr<GMock<double(const char*)> > feed = BONOBO_MOCK(&fetchLatestPrice);
    bsl::shared_ptr<GMock<long long()> > clock = BONOBO_MOCK(&Clock::nowUtcSeconds);

    EXPECT_CALL(*feed, BONOBO_MOCK_FUNCTION(StrEq("IBM"))).Times(1).WillOnce(Return(100.0));
    EXPECT_CALL(*clock, BONOBO_MOCK_FUNCTION()).WillOnce(Return(k_FIXED_NOW));

    Portfolio portfolio;
    portfolio.addHolding("IBM", 10);
    portfolio.addHolding("IBM", -4); // a short leg against the same symbol

    const Valuation valuation = portfolio.value();

    EXPECT_DOUBLE_EQ(600.0, valuation.totalUsd);
    EXPECT_EQ(k_FIXED_NOW, valuation.asOfUtcSeconds);
}

// Mocking is scoped, not a permanent seam: once the handles die the real
// entry points are back, so an unmocked test sees the production code path.
TEST(PortfolioTest, RestoresTheRealFunctionsWhenTheMocksExpire)
{
    {
        bsl::shared_ptr<GMock<double(const char*)> > feed = BONOBO_MOCK(&fetchLatestPrice);
        EXPECT_CALL(*feed, BONOBO_MOCK_FUNCTION(StrEq("IBM"))).WillOnce(Return(100.0));

        EXPECT_DOUBLE_EQ(100.0, fetchLatestPrice("IBM"));
    }

    EXPECT_DOUBLE_EQ(0.0, fetchLatestPrice("IBM"));
}
