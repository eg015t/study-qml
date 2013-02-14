set(SRC calendarmodel.cpp
        FileSystemModel.cpp 
        FileSystemIconProvider.cpp
        qmlextension_plugin.cpp
)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(WIN32)
    set(CMAKE_SHARED_MODULE_PREFIX "")  
endif(WIN32)

add_library(${PROJECT} MODULE ${SRC}  )
qt5_use_modules(${PROJECT} Core Qml Quick Widgets)

install(TARGETS ${PROJECT} DESTINATION QmlExtension)