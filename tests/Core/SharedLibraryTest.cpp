// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gmock/gmock.h"
#include "SharedLibrary.h"

using namespace ::testing;
using namespace hellbender;

class ASharedLibrary : public Test {
public:
    SharedLibrary sharedlibrary_;
    const std::string anInvalidPath = "foobar.so";
    const std::string anInvalidSymbol = "foo";
};

TEST_F(ASharedLibrary, HasNoLibLoadedWhenDefaultConstructed) {
    ASSERT_THAT(sharedlibrary_.isLoaded(), Eq(false));
}

#ifdef _WIN32
TEST_F(ASharedLibrary, HasNoSuffixDLLOnWin32) {
    ASSERT_THAT(sharedlibrary_.suffic(), Eq(".dll"));
}
#else
TEST_F(ASharedLibrary, HasSuffixsoOnUnix) {
    ASSERT_THAT(sharedlibrary_.suffix(), Eq(".so"));
}
#endif

TEST_F(ASharedLibrary, ThrowsWhenLoadingInvalidPath) {
    ASSERT_THROW(sharedlibrary_.load(anInvalidPath), std::runtime_error);
}

TEST_F(ASharedLibrary, ThrowsWhenSymbolNotFound) {
    ASSERT_THROW(sharedlibrary_.getSymbol(anInvalidSymbol), std::runtime_error);
}
