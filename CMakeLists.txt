cmake_minimum_required(VERSION 3.22.1)

project(udp-connection)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_library(udp_shared SHARED udp.c)
add_library(udp_static STATIC udp.c)

add_executable(sender sender.c)
target_link_libraries(sender udp_shared m)
add_executable(receiver receiver.c)
target_link_libraries(receiver udp_shared m)