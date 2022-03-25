#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_boost_qt.h"

class boost_qt : public QMainWindow
{
    Q_OBJECT

public:
    boost_qt(QWidget *parent = Q_NULLPTR);

private:
    Ui::boost_qtClass ui;
};
