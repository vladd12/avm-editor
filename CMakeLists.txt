# Project definition and settings
cmake_minimum_required(VERSION 3.15)
project(avm-editor VERSION 0.1 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Language settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Adding path for cmake scripts
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Library's options
option(AVM_EDITOR_STATIC_BUILD "Build avm-editor as static library" OFF)
option(AVM_EDITOR_BUILD_EXAMPLE "Build example application with using avm-editor" ON)
option(AVM_EDITOR_BUILD_TESTS "Build tests for avm-editor library" ON)

# Finding Qt
find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS Core Widgets
    REQUIRED)

# Dependencies settings
include(get_sqlitecpp)

# Include directory with project's public headers
set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
message(STATUS "${PROJECT_NAME} project include path: ${INCLUDE_PATH}")
include_directories(${INCLUDE_PATH})

# Collecting project's public headers
set(AVM_EDITOR_PUBLIC_HEADERS
    include/${PROJECT_NAME}/avm-editor.hpp
    include/${PROJECT_NAME}/core/config.hpp
    include/${PROJECT_NAME}/core/core.hpp
    include/${PROJECT_NAME}/database/assert.hpp
    include/${PROJECT_NAME}/database/database.hpp
    include/${PROJECT_NAME}/database/datatuple.hpp
    include/${PROJECT_NAME}/database/table.hpp
    include/${PROJECT_NAME}/database/detail/insert_impl.hpp
)

# Collecting project's priate headers
set(AVM_EDITOR_PRIVATE_HEADERS
    include/${PROJECT_NAME}/database/detail/file_ops.hpp
    include/${PROJECT_NAME}/database/detail/messages_printer.hpp
)

# Collecting project's sources
set(AVM_EDITOR_SOURCES
    src/core/core.cpp
    src/database/assert.cpp
    src/database/database.cpp
    src/database/datatuple.cpp
    src/database/table.cpp
    src/database/detail/file_ops.cpp
    src/database/detail/insert_impl.cpp
    src/database/detail/messages_printer.cpp
)

# Compilation static library
if (AVM_EDITOR_STATIC_BUILD)
    message(STATUS "${PROJECT_NAME} is static library")
    add_library(${PROJECT_NAME} STATIC
        ${AVM_EDITOR_PUBLIC_HEADERS}
        ${AVM_EDITOR_PRIVATE_HEADERS}
        ${AVM_EDITOR_SOURCES}
    )
    target_compile_definitions(${PROJECT_NAME} PUBLIC -DSTATIC_BUILD)
# Compilation dynamic library
else()
    message(STATUS "${PROJECT_NAME} is dynamic library")
    add_library(${PROJECT_NAME} SHARED
        ${AVM_EDITOR_PUBLIC_HEADERS}
        ${AVM_EDITOR_PRIVATE_HEADERS}
        ${AVM_EDITOR_SOURCES}
    )
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DLIB_EXPORT)
    target_compile_definitions(${PROJECT_NAME} INTERFACE -DLIB_IMPORT)
endif()

# Dependencies linking with library
# TODO: Maybe libraries should be private?
target_link_libraries(avm-editor PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    SQLiteCpp)

# Library compilation settings
target_compile_definitions(${PROJECT_NAME} PUBLIC -DCMAKE_CONFIG)
target_include_directories(${PROJECT_NAME} INTERFACE ${INCLUDE_PATH})

# If enabled building example
if(AVM_EDITOR_BUILD_EXAMPLE)
    message(STATUS "Example building is enabled")
    add_subdirectory(example)
endif()

# If enabled building tests for library
if(AVM_EDITOR_BUILD_TESTS)
    message(STATUS "Tests building is enabled")
    include(CTest)
    enable_testing(true)
    add_subdirectory(tests)
endif()

# Installation binaries for the library
install(TARGETS
    ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# Installation library's headers
install(FILES
    ${EXECSTD_HEADERS}
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}"
)
