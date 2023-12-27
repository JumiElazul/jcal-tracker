cmake_minimum_required(VERSION 3.5)

project(jcal_tracker)

include(cmake/CPM.cmake)
CPMAddPackage(
  NAME GroupSourcesByFolder.cmake
  GITHUB_REPOSITORY TheLartians/GroupSourcesByFolder.cmake
  VERSION 1.0
)

if (WIN32)
    add_compile_options(/W4 /EHsc)
else()
    add_compile_options(-Wall -Wextra -Werror -fsanitize=address)
    add_link_options(-fsanitize=address)
    set(CMAKE_CXX_FLAGS_DEBUG -g)
    set(CMAKE_CXX_FLAGS_RELEASE -O3 -DNDEBUG)
endif()

add_subdirectory(jcal_core)
add_subdirectory(jcal_client)
