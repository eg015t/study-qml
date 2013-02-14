#include "qmlextension_plugin.h"
#include "calendarmodel.h"
#include "FileSystemModel.h"
#include "FileSystemIconProvider.h"
#include <QtQml/qqml.h>

void QMLExtensionPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<CalendarModel>(uri, 1, 0, "CalendarModel");
    qmlRegisterType<FileSystemModel>(uri, 1, 0, "FileSystemModelBinding");
}


void QMLExtensionPlugin::initializeEngine(QQmlEngine * engine, const char * uri)
{
  engine->addImageProvider("filesystem", new FileSystemIconProvider());
}
