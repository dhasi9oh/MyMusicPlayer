cmake_minimum_required(VERSION 3.26)
project(AudioPlayer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS  "./ui")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS
        Widgets Network Core Multimedia Sql Core5Compat StateMachine)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
        Widgets Network Core Multimedia Sql Core5Compat StateMachine)

qt_standard_project_setup()

add_subdirectory(./TinyWidgetLibrary)

file(GLOB_RECURSE UI_FILES "./ui/*.ui")
file(GLOB_RECURSE SRC_FILES "./src/*.cpp")
file(GLOB_RECURSE INCLUDE_FILES "./include/*.h" "./include/*.hpp")

link_directories(./lib)

include_directories(
        include
        include/Window
        TinyWidgetLibrary/MyWidget
)

set(PROJECT_SOURCES
        ${UI_FILES}
        ${SRC_FILES}
        ${INCLUDE_FILES}
)

qt6_add_resources(RESOURCE_FILES resource.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt6_add_executable(AudioPlayer
            MANUAL_FINALIZATION
            main.cpp
            ${RESOURCE_FILES}
            ${PROJECT_SOURCES}
    )
else()
    add_executable(AudioPlayer
            ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(AudioPlayer PRIVATE
        Qt${QT_VERSION_MAJOR}::Sql
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Network
        Qt${QT_VERSION_MAJOR}::Multimedia
        Qt${QT_VERSION_MAJOR}::Core5Compat
        Qt${QT_VERSION_MAJOR}::StateMachine
)

target_link_libraries(AudioPlayer PRIVATE TinyWidgetLibrary)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.AudioPlayer)
endif()

set_target_properties(AudioPlayer PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS AudioPlayer
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(AudioPlayer)
endif()

