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

add_executable(cpp_qt_study
        src/main.cpp
        resources.qrc
        src/widgets/RoundButton.cpp
        src/widgets/RoundButton.h
        src/widgets/CustomProgressBar.cpp
        src/widgets/CustomProgressBar.h
        src/data/Range.h
        src/widgets/CustomLabel.cpp
        src/widgets/CustomLabel.h
        src/widgets/ColorInput.cpp
        src/widgets/ColorInput.h
        src/widgets/ColorViewer.cpp
        src/widgets/ColorViewer.h
        src/MyApp.cpp
        src/MyApp.h
        src/print/PrintInfoStatusBar.cpp
        src/print/PrintInfoStatusBar.h
        src/print/PaintingArea.cpp
        src/print/PaintingArea.h
        src/print/PointInfo.h
        src/print/ColorOption.cpp
        src/print/ColorOption.h
        src/print/ColorSelector.cpp
        src/print/ColorSelector.h
        src/print/BrushSizeLabel.cpp
        src/print/BrushSizeLabel.h
)

target_link_libraries(cpp_qt_study
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

