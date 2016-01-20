// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gmock/gmock.h"
#include "SharedLibrary.h"

using namespace ::testing;
using namespace hellbender;

// typedef int (*TheAnswerFunc)();
using TheAnswerFunc = int(*)();

class ASharedLibrary : public Test {
public:
    SharedLibrary sharedlibrary_;

    const std::string anInvalidPath = "foobar.so";
    const std::string anInvalidSymbol = "foo";
    const std::string aValidSymbol = "theAnswer";
    const std::string pathToTestLib = "libTestLib.so";

    SharedLibrary testLib_{pathToTestLib};
};

TEST_F(ASharedLibrary, HasNoLibLoadedWhenDefaultConstructed) {
    ASSERT_THAT(sharedlibrary_.isLoaded(), Eq(false));
}

TEST_F(ASharedLibrary, CanBeConstructedWithPath) {
    SharedLibrary tLib(pathToTestLib);
    ASSERT_THAT(tLib.isLoaded(), Eq(true));
}

TEST_F(ASharedLibrary, CanBeUnloaded) {
    testLib_.unload();
    ASSERT_THAT(testLib_.isLoaded(), Eq(false));
}

#ifdef _WIN32
TEST_F(ASharedLibrary, HasNoSuffixDLLOnWin32) {
    ASSERT_THAT(sharedlibrary_.suffic(), StrEq(".dll"));
}
#else
TEST_F(ASharedLibrary, HasSuffixsoOnUnix) {
    ASSERT_THAT(sharedlibrary_.suffix(), StrEq(".so"));
}
#endif

TEST_F(ASharedLibrary, ThrowsWhenLoadingInvalidPath) {
    ASSERT_THROW(sharedlibrary_.load(anInvalidPath), std::runtime_error);
}

TEST_F(ASharedLibrary, ThrowsWhenSymbolNotFound) {
    ASSERT_THROW(sharedlibrary_.getSymbol(anInvalidSymbol), std::runtime_error);
}

TEST_F(ASharedLibrary, CanCheckIfSymbolExists) {
    ASSERT_THAT(testLib_.hasSymbol(anInvalidSymbol), Eq(false));
    ASSERT_THAT(testLib_.hasSymbol(aValidSymbol), Eq(true));
}

TEST_F(ASharedLibrary, LoadsSymbolByName) {
    TheAnswerFunc answerFunc = (TheAnswerFunc) testLib_.getSymbol(aValidSymbol);
    ASSERT_THAT(answerFunc(), Eq(42));
}
