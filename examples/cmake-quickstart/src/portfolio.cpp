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

#include <portfolio.h>

#include <clock.h>
#include <pricefeed.h>

#include <map>
#include <utility>

void Portfolio::addHolding(std::string ticker, int shares)
{
    Holding holding;
    holding.ticker = std::move(ticker);
    holding.shares = shares;
    d_holdings.push_back(std::move(holding));
}

Valuation Portfolio::value() const
{
    // Real money code would use a decimal type (e.g. bdldfp::Decimal64) rather
    // than double; kept simple here to keep the focus on mocking.
    std::map<std::string, double> prices;

    double totalUsd = 0.0;
    for (const Holding& holding : d_holdings) {
        std::map<std::string, double>::const_iterator price = prices.find(holding.ticker);
        if (price == prices.end()) {
            price = prices.insert(std::make_pair(holding.ticker,
                                      fetchLatestPrice(holding.ticker.c_str())))
                        .first;
        }
        totalUsd += price->second * holding.shares;
    }

    Valuation valuation;
    valuation.totalUsd = totalUsd;
    valuation.asOfUtcSeconds = Clock::nowUtcSeconds();
    return valuation;
}
