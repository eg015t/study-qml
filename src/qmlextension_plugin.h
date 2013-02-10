#ifndef QMLEXTENSION_PLUGIN_H
#define QMLEXTENSION_PLUGIN_H

#include <QtQml/QQmlExtensionPlugin>

class QMLExtensionPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
    
public:
    void registerTypes(const char *uri);
};

#endif // QMLEXTENSION_PLUGIN_H

