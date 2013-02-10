#include "qmlextension_plugin.h"
#include "calendarmodel.h"
#include <QtQml/qqml.h>

void QMLExtensionPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<CalendarModel>(uri, 1, 0, "CalendarModel");
}


