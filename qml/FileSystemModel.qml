import QtQuick 2.0
import QmlExtension 1.0

VisualDataModel{
    id: fsModel

    property alias rootPath:fsBinding.rootPath

    function cdUp(){
        rootIndex = fsBinding.parentIndex(fsModel.rootIndex);
    }

    function isDir(path){
        return fsBinding.isDir(path);
    }

    function cd(path){
        rootIndex=fsBinding.indexFromPath(path)
    }

    model:FileSystemModelBinding{
        id: fsBinding

        }
}
