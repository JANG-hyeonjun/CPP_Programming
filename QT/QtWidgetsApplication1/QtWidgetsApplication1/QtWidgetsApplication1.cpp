#include "QtWidgetsApplication1.h"

#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <qdebug.h>

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
    m_button = new QPushButton("press me", this);

    m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
    connect(m_button, &QPushButton::released, this, &QtWidgetsApplication1::HandleButton);

}

void QtWidgetsApplication1::HandleButton()
{
    m_button->setText("clicked");
    qDebug() << "clicked!";
    m_button->resize(100, 100);
}