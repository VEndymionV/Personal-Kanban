#ifndef NEWCALENDARWIDGET_H
#define NEWCALENDARWIDGET_H

#include <QCalendarWidget>
#include <QStringList>
#include <QBrush>
#include <QColor>
#include <QFile>
#include <QList>
#include <QDate>
#include <QPen>

class NewCalendarWidget : public QCalendarWidget
{
Q_OBJECT

Q_PROPERTY(QColor color READ getColor WRITE setColor)

public:
   NewCalendarWidget(QWidget *parent = 0);
   ~NewCalendarWidget();

   void setColor(QColor& color);
   QColor getColor() const;

protected:
   virtual void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;

private:

   QDate date;
   QString name;

   QList<QDate> m_dates;
   QPen m_outlinePen;
   QBrush m_transparentBrush;

   void getDates();

};

#endif // NEWCALENDARWIDGET_H
