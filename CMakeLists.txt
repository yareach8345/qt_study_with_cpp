cmake_minimum_required(VERSION 4.2)
project(cpp_qt_study)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(cpp_qt_study main.cpp)
target_link_libraries(cpp_qt_study
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

