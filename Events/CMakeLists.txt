cmake_minimum_required(VERSION 3.14.1)

add_library(Events
	EventHandler.cpp	
	Event.cpp
)
message("AAAAAA ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}")
# target_include_directories(Events PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Events PUBLIC ./)
