cmake_minimum_required(VERSION 3.16)
project(Admin)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Add this line to point to your Qt6 install
set(CMAKE_PREFIX_PATH "/Users/boody/Qt/6.9.0/macos/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(Admin
        test.cpp
        admin.cpp
        properties.cpp
)

target_link_libraries(Admin
        Qt::Core
        Qt::Gui
        Qt::Widgets
)