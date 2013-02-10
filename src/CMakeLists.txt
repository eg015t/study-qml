set(SRC calendarmodel.cpp
        qmlextension_plugin.cpp
)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(WIN32)
    set(CMAKE_SHARED_MODULE_PREFIX "")  
endif(WIN32)

  
add_library(${PROJECT} MODULE ${SRC})
qt5_use_modules(${PROJECT} Core Qml)

install(TARGETS ${PROJECT} DESTINATION QmlExtension)