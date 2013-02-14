import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {
    width: 500
    height: 500
    //color: "#4e4d4e"

    FileSystemModel{
        id:fsModel
        rootPath:"/"
        delegate:Item{
            height: view.cellHeight
            width: view.cellWidth

            Column{
                anchors.centerIn: parent
                width: parent.width


                Image {

                    id: icon
                    source: "image://filesystem/"+filePath
                    smooth: true
                }

                Text{
                    anchors.horizontalCenter: icon.horizontalCenter
                    text:fileName
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode:Text.WordWrap
                    width: parent.width

                    font.family: "Verdana"
                    //color: "white"
                }

            }

            MouseArea{
                anchors.fill: parent
                onDoubleClicked: {
                    fsModel.cd(filePath)
                }
            }
        }


    }

    GridView{
        id:view
        width: parent.width
        height: parent.height
        anchors.fill: parent
        model: fsModel
        cellHeight : 128
        cellWidth : 128
    }
}
