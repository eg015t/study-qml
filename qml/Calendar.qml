import QtQuick 2.0
import QmlExtension 1.0

Rectangle {
    width: 300
    height: 200

    border.width: 1
    border.color: "gray"

    property int headerHeight: 40
    property alias year: calModel.year
    property alias month: calModel.month

    CalendarModel{
        id: calModel
    }

    GridView{
        id:view
        anchors.left: parent.left
        anchors.right: parent.right
        height: parent.height
        width: parent.width
        model:calModel

        cellWidth: width / 7
        cellHeight: (height-headerHeight)/(count/7)

        interactive: false

        header:Item {
            height: headerHeight
            width: parent.width
            Text {
                width: parent.width
                horizontalAlignment:  Text.AlignHCenter

                text: calModel.longMonthName(calModel.month);
                font.family: "Verdana"
                font.bold: true
                font.pointSize: 13
            }
            Row{
                height: parent.height/2

                anchors.left: parent.left;
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                Repeater{
                    model:7
                    Text {
                        width: view.cellWidth
                        height: parent.height

                        horizontalAlignment:  Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter

                        text: calModel.shortDayName(index+1)
                        font.family: "Verdana"
                        font.bold: true
                    }
                }
            }
        }



        delegate: Rectangle{
            height:view.cellHeight
            width: view.cellWidth
            border.width: 1
            border.color: "gray"

            Rectangle{
                height: parent.height
                width: parent.width
                color: calModel.month != month ? "lightgray":"white"
                opacity: 0.5
            }


            Text{
                anchors.centerIn: parent
                text:date

                font.family: "Verdana"
                font.bold: true

            }
        }
    }
}
