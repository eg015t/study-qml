#include <QtCore/QDate>
#include "calendarmodel.h"

CalendarModel::CalendarModel(QObject *parent) :
    QAbstractListModel(parent)
{

    roles_[Date] = "date";
    roles_[Month] = "month";

    QDate curentDate = QDate::currentDate();

    month_ = curentDate.month();
    year_  = curentDate.year();

    updateModel();
}

void CalendarModel::updateModel()
{
    beginResetModel();
    data_.clear();

    QDate date(year_, month_, 1);
    QDate beginDate(date);

    if(beginDate.dayOfWeek()!= 1)
        beginDate = beginDate.addDays(1-beginDate.dayOfWeek());

    QDate endDate(year_, month_, date.daysInMonth());

    if(endDate.dayOfWeek() != 7)
        endDate = endDate.addDays(7-endDate.dayOfWeek());


    while(beginDate<=endDate)
    {
        Record rc = {beginDate.day(), beginDate.month()};
        data_.push_back(rc);
        beginDate = beginDate.addDays(1);
    }

    endResetModel();
}
QHash<int, QByteArray> CalendarModel::roleNames() const
{
    return roles_;
}

int CalendarModel::month()const
{
    return month_;
}

void CalendarModel::setMonth(int month)
{
    month_ = month;
    updateModel();
    emit monthChanged();
}

int CalendarModel::year()const
{
    return year_;
}

void CalendarModel::setYear(int year)
{
   year_ = year;
   updateModel();
   emit yearChanged();
}

QString CalendarModel::shortDayName(int day)const
{
    return QDate::shortDayName(day);
}


QString CalendarModel::longMonthName(int month)const
{
    return QDate::longMonthName(month);
}


int	CalendarModel::rowCount(const QModelIndex & ) const
{
    return data_.size();
}
QVariant CalendarModel::data(const QModelIndex & index, int role ) const
{
    if(!index.isValid())
        return QVariant();

    switch (role)
    {
    case Date: return data_[index.row()].day;
    case Month: return data_[index.row()].month;
    default: return QVariant();
    }
}
