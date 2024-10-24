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


    frontend/includes/main_window.h
    frontend/includes/qt_headers.h


    frontend/source/main_window.cpp

    

    backend/bots/includes/bot.h
    backend/bots/includes/first_bot.h

    backend/bots/source/bot.cpp
    backend/bots/source/first_bot.cpp

    backend/includes/agencies/advert_agency.h
    backend/includes/agencies/building_agency.h
    backend/includes/agencies/grocery_agency.h
    backend/includes/agencies/land_agency.h
    backend/includes/agencies/real_estate_agency.h

    backend/includes/game/calamity.h
    backend/includes/game/game.h
    backend/includes/game/main_game_window.h
    backend/includes/game/news_window.h

    backend/includes/land_plot/building_land.h
    backend/includes/land_plot/land_plot.h
    backend/includes/land_plot/resort.h

    backend/includes/realty/house.h
    backend/includes/realty/non_build_realty.h
    backend/includes/realty/realty.h
    backend/includes/realty/supermarket.h

    backend/includes/player.h
    backend/includes/standard_classes.h



    backend/source/agencies/advert_agency.cpp
    backend/source/agencies/building_agency.cpp
    backend/source/agencies/grocery_agency.cpp
    backend/source/agencies/land_agency.cpp
    backend/source/agencies/real_estate_agency.cpp

    backend/source/game/calamity.cpp
    backend/source/game/game.cpp
    backend/source/game/main_game_window.cpp
    backend/source/game/news_window.cpp
    backend/source/game/starting_window.cpp

    backend/source/land_plot/building_land.cpp
    backend/source/land_plot/land_plot.cpp
    backend/source/land_plot/resort.cpp

    backend/source/realty/house.cpp
    backend/source/realty/non_build_realty.cpp
    backend/source/realty/realty.cpp
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
