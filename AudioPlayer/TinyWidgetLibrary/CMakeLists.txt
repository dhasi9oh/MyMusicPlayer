cmake_minimum_required(VERSION 3.5)
project(TinyWidgetLibrary VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core StateMachine)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core StateMachine)

qt_standard_project_setup()
qt6_add_resources(RESOURCE_FILES resource.qrc)

file(GLOB_RECURSE SRC_FILES "./src/*.cpp")
file(GLOB_RECURSE INCLUDE_FILES "./MyWidget/*.h")

set(PROJECT_SOURCES
        ${SRC_FILES}
        ${INCLUDE_FILES}
)

qt6_add_library(TinyWidgetLibrary STATIC
        resource.qrc
        ${PROJECT_SOURCES}
        ${RESOURCE_FILES}
)

target_include_directories(TinyWidgetLibrary PUBLIC
        "${PROJECT_SOURCE_DIR}/MyWidget"
)

target_link_libraries(TinyWidgetLibrary PUBLIC
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::StateMachine
)

qt6_add_executable(test MANUAL_FINALIZATION main.cpp)

target_link_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/MyWidget)

target_link_libraries(test PRIVATE TinyWidgetLibrary)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(test)
endif()

