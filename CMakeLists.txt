cmake_minimum_required(VERSION 3.14) #mandatory
project(cpp_boilerplate) #mandatory

set(CMAKE_CXX_STANDARD 20) #use c++20

# Set build type if not set.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    message(STATUS "Build flags: ${CMAKE_CXX_FLAGS_DEBUG}")
else()
    message(STATUS "Build flags: ${CMAKE_CXX_FLAGS_RELEASE}")
endif()

message(STATUS "Using compiler: ${CMAKE_CXX_COMPILER_ID}")

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
    #set to see all warnings
    set(CMAKE_CXX_FLAGS "-Wall -Wextra")
elseif(MSVC)
#set to see all warnings and if windows set exception handling mode to sc [https://docs.microsoft.com/en-us/cpp/build/reference/eh-exception-handling-model?view=msvc-170]
    set(CMAKE_CXX_FLAGS "-EHsc")
endif()

#tell cmake where to put output binaries
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message(STATUS "Output directory: ${EXECUTABLE_OUTPUT_PATH}")

#tell cmake where to put output libraries binaries
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# thell where to look for .h files 
include_directories(${PROJECT_SOURCE_DIR}/src)

# Outsource the actual processing to folders. separation of concerns
add_subdirectory(src)

#enable_testing command should be in the source directory root because ctest expects to find a test file in the build directory root.
enable_testing() 

# Outsorce test configuration in the test folder
add_subdirectory(tests)


