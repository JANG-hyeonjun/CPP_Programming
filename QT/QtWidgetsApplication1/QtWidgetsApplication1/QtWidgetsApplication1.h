#pragma once



#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include <QPushButton>


class QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
   explicit QtWidgetsApplication1(QWidget *parent = Q_NULLPTR);

private slots:
    void HandleButton();

private:
    Ui::QtWidgetsApplication1Class ui;
    QPushButton* m_button;
};
