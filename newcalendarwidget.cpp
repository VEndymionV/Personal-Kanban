#include <QPainter>
#include "newcalendarwidget.h"

NewCalendarWidget::NewCalendarWidget(QWidget *parent)
   : QCalendarWidget(parent)
{

   m_outlinePen.setColor(Qt::red);
   m_transparentBrush.setColor(Qt::transparent);
   getDates();
}

NewCalendarWidget::~NewCalendarWidget()
{

}

void NewCalendarWidget::setColor(QColor& color)
{
   m_outlinePen.setColor(color);
}

QColor NewCalendarWidget::getColor() const
{
   return (m_outlinePen.color());
}


void NewCalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{


          QCalendarWidget::paintCell(painter, rect, date);
          if ( m_dates.contains(date) )
          {

              painter->setPen(m_outlinePen);
              painter->setBrush(m_transparentBrush);
              painter->drawRect(rect.adjusted(0, 0, -1, -1));
          }
       }


void NewCalendarWidget::getDates()
{

QFile file("daty.csv");
 //QDate Date = QDate::fromString(line,"ddd MMM d yyyy");
file.open(QFile::ReadOnly);



   QDate date;


while (!file.atEnd())
   {
      QString line = file.readLine(); //read one line at a time
      line=line.simplified();
      date = QDate::fromString(line,"ddd MMM d yyyy");



      m_dates.append(date);


    }
file.close();
}

