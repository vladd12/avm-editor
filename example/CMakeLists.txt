project(avm-editor-example LANGUAGES CXX)

find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS Core Widgets
    REQUIRED)

# Collecting example's sources
set(AVM_EDITOR_EXAMPLE_SOURCES
   mainwindow.h
   main.cpp
   mainwindow.cpp)

# Building project
add_executable(${PROJECT_NAME} ${AVM_EDITOR_EXAMPLE_SOURCES})

# Libraries linking with project executable file
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    avm-editor)

# Finalize executable (Qt6 only)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
