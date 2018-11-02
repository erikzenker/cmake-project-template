#include "MyLibrary/lib_header.h"

#include <gtest/gtest.h>

TEST(MyLibrayTests, MyLibraryTest){
    ASSERT_EQ(42, MyLibrary::getFortyTwo());
}