## If you are on Ubuntu, install gtest sources with:
##
##     sudo apt install libgtest-dev
##
# add_subdirectory(/usr/src/gtest
                #  ${PROJECT_BINARY_DIR}/gtest)
## If you are not on Ubuntu, you will need to download the source of the
## googletest framework manually and provide the folder to which you have
## - installed it.
include_directories(/usr/local/include)

# link the libraries to test
link_directories(/usr/local/lib)

# Include testing cmake package.
include(CTest)

# Set binary name for convenience.
set(TEST_BINARY ${PROJECT_NAME}_test)

# This is an executable that runs the tests.
add_executable(${TEST_BINARY} 
test_utils.cc
test_object.cc)

# Link the executable to needed libraries.
target_link_libraries(${TEST_BINARY} 
utils 
objects_lib_name
gtest gtest_main # GTest libraries
)

# Add gtest to be able to run ctest
add_test(
    NAME ${TEST_BINARY}
    COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY}
)