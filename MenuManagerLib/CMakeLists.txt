cmake_minimum_required(VERSION 3.15)
project(MenuManagerLib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(HEADER_PATH ${PROJECT_SOURCE_DIR}/header)
set(SOURCE_PATH ${PROJECT_SOURCE_DIR}/src)

# include files
set(HEADER_FILES
${HEADER_PATH}/GeneralItem.h
${HEADER_PATH}/MenuItem.h
${HEADER_PATH}/OperationItem.h
${HEADER_PATH}/StateSelectionItem.h
${HEADER_PATH}/Menu.h
${HEADER_PATH}/MenuManager.h
${HEADER_PATH}/Navigation.h
${HEADER_PATH}/MenuBuilder.h
${HEADER_PATH}/ScreenStub.h
${HEADER_PATH}/KeyBoardStub.h
)

# interface files
set(INTERFACE_FILES
${HEADER_PATH}/IStateSelection.h
${HEADER_PATH}/IExternalMemory.h
${HEADER_PATH}/IOperationItem.h
${HEADER_PATH}/IMenuUpdater.h
${HEADER_PATH}/IMenuNavigation.h
${HEADER_PATH}/IKeyBoard.h
${HEADER_PATH}/IScreen.h
${HEADER_PATH}/IExternalDevice.h
${HEADER_PATH}/INavigationCmdBuilder.h
${HEADER_PATH}/IMenuBuilder.h
)

# source files
set(SOURCE_FILES
${SOURCE_PATH}/GeneralItem.cpp
${SOURCE_PATH}/MenuItem.cpp
${SOURCE_PATH}/OperationItem.cpp
${SOURCE_PATH}/StateSelectionItem.cpp
${SOURCE_PATH}/Menu.cpp
${SOURCE_PATH}/MenuManager.cpp
${SOURCE_PATH}/Navigation.cpp
${SOURCE_PATH}/MenuBuilder.cpp
)

include_directories(${HEADER_PATH})

add_library(${PROJECT_NAME} 
${HEADER_FILES} 
${SOURCE_FILES}
${INTERFACE_FILES}
)
