// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gmock/gmock.h"
#include "MetaObject.h"

using namespace ::testing;
using namespace hellbender;

class Base {
};

class Derivate : public Base {
};

class AMetaObject : public Test
{
public:
    const std::string theDerivedClassName = "DerivateName";
    const std::string theBaseClassName = "BaseName";
    MetaObject<Derivate, Base> metaObject_{theDerivedClassName, theBaseClassName};
};

TEST_F(AMetaObject, HasTheNameOfTheDerivedClass) {
    ASSERT_THAT(metaObject_.className(), Eq(theDerivedClassName));
}
