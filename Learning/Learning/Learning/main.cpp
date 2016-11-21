//
//  main.cpp
//  Learning
//
//  Created by Elena Ispas on 02/11/16.
//  Copyright © 2016 ElenaI. All rights reserved.
//

#include <iostream>

#include "gtest/gtest.h"

#include "Vector.hpp"
#include "TestClass.cpp"

TEST(blahTest, blah1) {
   EXPECT_EQ(1, 1);
}
std::set<const A*> A::sObjects;

int main (int argc, char** argv)
{
    Vector<A> v;
    A a;
    A b;

    
    v.PushBack(a);
    v.PushBack(b);

   return 0;
}
