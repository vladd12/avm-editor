project(avm-editor-tests LANGUAGES CXX)

find_package(Qt${QT_VERSION_MAJOR}
  COMPONENTS Core Test
  REQUIRED)

add_executable(${PROJECT_NAME}
    testmodule.h
    testmodule.cpp
)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Test
    avm-editor)
