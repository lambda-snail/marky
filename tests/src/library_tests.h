#pragma once

#include <marky/library.h>

#include <gtest/gtest.h>

TEST(LibraryTest, LibraryStartsEmpty)
{
    Library l;
    EXPECT_EQ(0, l.x);
}