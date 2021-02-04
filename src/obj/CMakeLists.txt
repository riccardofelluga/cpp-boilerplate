# add objects as lib, can fit multiple objects under the same lib name
add_library(objects_lib_name OBJECT object.cc)

# link libraries together to use them from one another lib.
# target_link_libraries(utils another_lib)