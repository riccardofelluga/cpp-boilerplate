#ifndef OBJ_OBJECT_H_
#define OBJ_OBJECT_H_

#include <vector>

namespace obj {

class Object {
 public:
  Object(int data, int size);

 private:
  int data_;
  std::vector<int> vector_;
};

}  // namespace obj

#endif  // OBJ_OBJECT_H_
