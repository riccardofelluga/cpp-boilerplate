#include <gtest/gtest.h>

#include "obj/object.h"

TEST(TestObject, NewObjTest) {
  Object* o_ptr = Object(1, 1);
  EXPECT_TRUE(o_ptr != nullptr);
}
