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

#ifndef INCLUDED_PRICEFEED
#define INCLUDED_PRICEFEED

/// Return the latest traded price of `ticker` in USD, or 0.0 if the symbol is
/// unknown. `ticker` must be a non-null, NUL-terminated symbol.
///
/// A real implementation reaches a live price feed over the network: slow,
/// non-deterministic, and unavailable in a unit test. It is a free function,
/// so there is no interface to substitute and no seam to inject through.
double fetchLatestPrice(const char* ticker);

#endif
