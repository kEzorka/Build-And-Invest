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
    app/main.cpp
    app/pocket_economic.ui
    frontend/main_window.h
    frontend/main_window.cpp
    app/Pocket-Economic.rc

    backend/includes/realty/house.h
    backend/includes/realty/land_plot.h
    backend/includes/realty/realty.h
    backend/includes/realty/real_estate_agency.h
    backend/includes/realty/supermarket.h
    backend/includes/player.h

    backend/source/realty/house.cpp
    backend/source/realty/land_plot.cpp
    backend/source/realty/real_estate_agency.cpp
    backend/source/realty/supermarket.cpp
    backend/source/player.cpp
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
