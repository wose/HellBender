// Copyright (c) 2016 The HellBender Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gmock/gmock.h"
#include "MetaObject.h"

using namespace ::testing;
using namespace hellbender;

class Base {
public:
    virtual std::string getName()
    {
        return "Base";
    }
};

class Derivate : public Base {
public:
    virtual std::string getName() override
    {
        return "Derivate";
    }
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

TEST_F(AMetaObject, HasTheNameOfTheBaseClass) {
    ASSERT_THAT(metaObject_.baseClassName(), Eq(theBaseClassName));
}

TEST_F(AMetaObject, ConstructsADerivedObjectAndReturnsBasePointer) {
    ASSERT_THAT(metaObject_.create()->getName(), Eq("Derivate"));
}

TEST_F(AMetaObject, HasNoAssociatedClassLoaderAfterConstruction) {
    ASSERT_THAT(metaObject_.isOwnedByAnybody(), Eq(false));
}

TEST_F(AMetaObject, HasUnknownLibraryPathAfterConstruction) {
    ASSERT_THAT(metaObject_.libraryPath(), StrEq("Unknown"));
}
