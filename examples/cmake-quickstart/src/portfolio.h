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

#ifndef INCLUDED_PORTFOLIO
#define INCLUDED_PORTFOLIO

#include <string>
#include <vector>

/// The result of valuing a portfolio: its total worth and the instant the
/// prices were taken at.
struct Valuation {
    double totalUsd;
    long long asOfUtcSeconds;
};

/// A set of equity holdings that can be valued against the live price feed.
class Portfolio {
public:
    /// Add `shares` shares of `ticker`. `shares` may be negative (a short
    /// position). The same ticker may be added more than once.
    void addHolding(std::string ticker, int shares);

    /// Return the total USD value of every holding, priced with
    /// `fetchLatestPrice` and stamped with `Clock::nowUtcSeconds`. Each
    /// distinct ticker is priced at most once, so every holding of a symbol
    /// is valued at the same price.
    Valuation value() const;

private:
    struct Holding {
        std::string ticker;
        int shares;
    };

    std::vector<Holding> d_holdings;
};

#endif
