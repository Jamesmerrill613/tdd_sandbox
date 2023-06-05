cmake_minimum_required(VERSION 3.15)
project(custom_states LANGUAGES CXX)

set(CUSTOM_STATE_CLASSES
	State_1
)

foreach(CLASS ${CUSTOM_STATE_CLASSES})
    list(APPEND CUSTOM_STATE_SOURCES src/${CLASS}.cpp)
	list(APPEND CUSTOM_STATE_INCLUDES inc/custom_states/${CLASS}.h)
endforeach()

list(APPEND CUSTOM_STATE_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/../deps/state_machine/state_machine/include/state_machine/IState.h)

# create and export lib
add_library(${PROJECT_NAME} STATIC ${CUSTOM_STATE_SOURCES} ${CUSTOM_STATE_INCLUDES})
target_include_directories(${PROJECT_NAME} PUBLIC inc)