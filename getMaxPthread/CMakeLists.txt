cmake_minimum_required(VERSION 2.8)
project (maxP)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
include_directories(
    ./
)
link_directories(
    ${PREFIX}/lib
)

set(srcdirs
  ${CMAKE_CURRENT_SOURCE_DIR}/
)

foreach(srcdir ${srcdirs})
  include_directories(${srcdir})
  aux_source_directory(${srcdir} source_files)
endforeach()
add_executable(${PROJECT_NAME}  ${source_files})
target_link_libraries(${PROJECT_NAME} pthread)