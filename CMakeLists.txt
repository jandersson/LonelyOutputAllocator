cmake_minimum_required(VERSION 2.8.4)

project(LonelyOutputAllocator)
set(LonelyOutputAllocator_BINARY_DIR ${LonelyOutputAllocator_SOURCE_DIR})
set(CMAKE_BUILD_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES
    main.cpp)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_executable(LonelyOutputAllocator ${SOURCE_FILES})