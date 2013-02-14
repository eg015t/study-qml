set(PROJECT qmlextension)
project(${PROJECT} C CXX)
cmake_minimum_required(VERSION 2.8.3)

find_package(Qt5Core)
find_package(Qt5Quick)
find_package(Qt5Widgets)
find_package(Qt5Qml)

include_directories(${Qt5Widgets_INCLUDE_DIRS}
                    ${Qt5Core_INCLUDE_DIRS}
                    ${Qt5Quick_INCLUDE_DIRS}
                    ${Qt5Qml_INCLUDES_DIRS}
)

add_definitions(${Qt5Widgets_DEFINITIONS}
                ${Qt5Core_DEFINITIONS}
                ${Qt5Quick_DEFINITIONS}
                ${Qt5Qml_DEFINITIONS}
)

add_subdirectory(src)
add_subdirectory(qml)