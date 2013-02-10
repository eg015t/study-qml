import QtQuick 2.0
import QmlExtension 1.0

Flickable{
     contentWidth: calendarGrid.width;
     contentHeight: calendarGrid.height
     width: 900
     height: 500

     Grid{

         id: calendarGrid
         columns : 3
         rows: 4
         spacing:20

         Repeater{
             model:12


             Calendar{
                 month: index+1

             }
         }
     }
}
