# Project definition and settings
cmake_minimum_required(VERSION 3.15)
project(avm-editor VERSION 0.1 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Language settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Finding Qt
find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS Core Widgets
    REQUIRED)

# Collecting project's public headers
set(AVM_EDITOR_PUBLIC_HEADERS
    include/mainwindow.h)
# Include directory with project's public headers
set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
message(STATUS "${PROJECT_NAME} project include path: ${INCLUDE_PATH}")
include_directories(${INCLUDE_PATH})

# Collecting project sources
set(AVM_EDITOR_SOURCES
    src/main.cpp
    src/mainwindow.cpp)

# Building project
add_executable(${PROJECT_NAME}
    ${AVM_EDITOR_SOURCES}
    ${AVM_EDITOR_PUBLIC_HEADERS})

# Libraries linking with project executable file
target_link_libraries(avm-editor PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets)

# Finalize executable (Qt6 only)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(avm-editor)
endif()
