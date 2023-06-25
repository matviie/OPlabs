cmake_minimum_required(VERSION 3.23)
project(op_7laba_da)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/home/Qt/6.5.1/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(op_7laba_da main.cpp MainWindow.cpp MainWindow.h File.cpp File.h)
target_link_libraries(op_7laba_da
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

