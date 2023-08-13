cmake_minimum_required(VERSION 3.14.1)

set(PROJECT_NAME Asterray)

project(${PROJECT_NAME})

# Events
# --link_directories(Events)
add_subdirectory(Events)
# /Events


find_library(lraylib raylib)

if(${lraylib})
	message("raylib not found")
else()
	message("raylib found")
endif()



add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${lraylib} PUBLIC Events)
