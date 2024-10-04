cmake_minimum_required(VERSION 3.16)
project(Pocket-Economic LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    main.cpp
    pocket_economic.ui
    main_window.h
    main_window.cpp
    Pocket-Economic.rc
)

qt_add_executable(Pocket-Economic ${PROJECT_SOURCES})

set_target_properties(Pocket-Economic
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(Pocket-Economic
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
