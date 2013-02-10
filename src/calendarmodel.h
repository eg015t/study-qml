#ifndef CALENDARMODEL_H
#define CALENDARMODEL_H

#include <QtCore/QHash>
#include <QtCore/QVector>
#include <QtCore/QAbstractListModel>

/*!
 * \brief CalendarModel класс
 *
 * Модель календаря
 */
class CalendarModel : public QAbstractListModel
{
    Q_OBJECT

    /*!
     * \brief Роли модели
     */
    enum Roles
    {
        Date = Qt::UserRole + 1, //!< день
        Month                    //!< месяц

    };

    /*! свойство месяц */
    Q_PROPERTY(int month READ month WRITE setMonth NOTIFY monthChanged)

    /*! свойство гов */
    Q_PROPERTY(int year READ year WRITE setYear NOTIFY yearChanged)

    /*!
     * \brief запись хранимая в модели
     */
    struct Record
    {
        int day;   //!< день
        int month; //!< месяц
    };

public:
    explicit CalendarModel(QObject *parent = 0);

    /*!
     * \brief month получить месяц
     */
    int month()const;

    /*!
     * \brief setMonth установить месяц
     * \param month от 1 до 12
     */
    void setMonth(int month);

    /*!
     * \brief year получить год
     */
    int year()const;

    /*!
     * \brief setYear установить год
     * \param year
     */
    void setYear(int year);

    /*!
     * \brief получить короткое имя дня недели
     * \param day день недели от 1 до 7
     * Получение короткого названия дня недели.
     * 1 = "Mon"
     */
    Q_INVOKABLE QString shortDayName(int day)const;

    /*!
     * \brief получить длинное имя месяца
     * \param month месяц от 1 до 12
     */
    Q_INVOKABLE QString longMonthName(int month)const;

    virtual int	rowCount(const QModelIndex & parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    virtual QHash<int, QByteArray> roleNames() const;

signals:

    /*!
     * \brief monthChanged
     * Оповещение изменения месяца
     */
    void monthChanged();

    /*!
     * \brief yearChanged
     * Оповещение изменения года
     */
    void yearChanged();

public slots:

    /*!
     * \brief updateModel обновление модели
     */
    void updateModel();
private:

    int month_; //!< месяц
    int year_;  //!< год
    QVector<Record> data_;//!< хранимые данные
    QHash<int, QByteArray> roles_;
    
};

#endif // CALENDARMODEL_H
