/** *******************************************************
    @brief		:
    @author		:zhongyl
    @date		:2019-08-19
    @version	:v1.0
    @copyright	:Copyright (C) 2019 - All Rights Reserved
    @warning	:
    @note		:

******************************************************** **/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QScxmlStateMachine>
#include <QScxmlCppDataModel>

#include "DataModel.h"
#include "PowerStateMachine.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void onPowerLossEvent(const QScxmlEvent &event);
    void onPowerUpEvent(const QScxmlEvent &event);

    void onLowState(bool isActive);
    void onFullState(bool isActive);
    void onDangerState(bool isActive);
    void onNomalState(bool isActive);
private slots:
    void on_pushButton_powerUp_clicked();

    void on_pushButton_powerLoss_clicked();

private:
    Ui::MainWindow *ui;

    QScxmlStateMachine *m_stateMachine;

    int m_pwoer  = 50;
};

#endif // MAINWINDOW_H
