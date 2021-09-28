cmake_minimum_required(VERSION 3.15)
project(ExampleMenuApp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MENU_LIB_NAME MenuManagerLib)

set(HEADER_APP_PATH ${PROJECT_SOURCE_DIR}/header)
set(SOURCE_APP_PATH ${PROJECT_SOURCE_DIR}/src)

# include files
set(HEADER_FILES
#${HEADER_APP_PATH}/test.h
)

# source files
set(SOURCE_FILES
${SOURCE_APP_PATH}/main.cpp
)

include_directories(
${HEADER_APP_PATH}
${PROJECT_SOURCE_DIR}/../${MENU_LIB_NAME}/header
)

add_executable(${PROJECT_NAME}
${HEADER_FILES}
${SOURCE_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${MENU_LIB_NAME})