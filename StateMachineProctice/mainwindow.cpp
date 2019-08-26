/** *******************************************************
    @brief		:
    @author		:zhongyl
    @date		:2019-08-19
    @version	:v1.0
    @copyright	:Copyright (C) 2019 - All Rights Reserved
    @warning	:
    @note		:

******************************************************** **/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



//    PowerStateMachine stateMachine;


    m_stateMachine = QScxmlStateMachine::fromFile(":/powerStateMachine.scxml");
    for(QScxmlError& error:m_stateMachine->parseErrors())
    {
        qDebug()<<error.description();
    }
    m_stateMachine->connectToEvent("powerLoss", this, &MainWindow::onPowerLossEvent);
    m_stateMachine->connectToEvent("pwoerUp", this, &MainWindow::onPowerUpEvent);

    m_stateMachine->connectToState("low", this, &MainWindow::onLowState);
    m_stateMachine->connectToState("nomal", this, &MainWindow::onNomalState);
    m_stateMachine->connectToState("danger", this, &MainWindow::onDangerState);
    m_stateMachine->connectToState("full", this, &MainWindow::onFullState);
    DataModel *dataModel = new DataModel;
    m_stateMachine->setDataModel(dataModel);
    m_stateMachine->init();

    m_stateMachine->start();


//    m_stateMachine->connectToState("nomal", [this](bool active) {
//        QScxmlDataModel* dataModel = m_stateMachine->dataModel(); //Returns anull pointer
//        QScxmlCppDataModel* cppDataModel = static_cast<QScxmlCppDataModel*>(dataModel);
//        if(cppDataModel == nullptr)
//        {
//            return ;
//        }

//        QScxmlEvent event = cppDataModel->scxmlEvent();
//        QVariant data = event.data();
//        qDebug() << "event.data()" << data.toInt();
//        qDebug()<<"进入正常电量状态, current power: ";
//    });

    m_pwoer = 50;


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPowerLossEvent(const QScxmlEvent &event)
{

    qDebug()<<"onPowerLossEvent current power: "<<event.data().toInt()<< " event:"<<event.name();
}

void MainWindow::onPowerUpEvent(const QScxmlEvent &event)
{
    qDebug()<<"onPowerLossEvent current power: "<<event.data().toInt()<< " event:"<<event.name();
}

void MainWindow::onLowState(bool isActive)
{
    if(isActive)
    {
        qDebug()<<"enter low power state , current power: "<< m_pwoer;
    }else{
        qDebug()<<"leave low power state, current power: "<< m_pwoer;
    }
}

void MainWindow::onFullState(bool isActive)
{
    if(isActive)
    {
//        QVariant data(m_pwoer);
//        QScxmlEvent
        qDebug()<<"enter full power state, current power: "<< m_pwoer;
    }else{
        qDebug()<<"leave low power state, current power: "<< m_pwoer;
    }
}

void MainWindow::onDangerState(bool isActive)
{
    if(isActive)
    {
        qDebug()<<"enter critical power state, current power: "<< m_pwoer;
    }else{
        qDebug()<<"leave critical power state, current power: "<< m_pwoer;
    }
}

void MainWindow::onNomalState(bool isActive)
{
    if(isActive)
    {

        qDebug()<<"enter nomal power state, current power: "<< m_pwoer;
    }else{
        qDebug()<<"leave nomal power state, current power: "<< m_pwoer;
    }
}

void MainWindow::on_pushButton_powerUp_clicked()
{
    qDebug()<<"power -1";
    m_pwoer --;
    QVariant var(m_pwoer);
    m_stateMachine->submitEvent("powerLoss", var);
}

void MainWindow::on_pushButton_powerLoss_clicked()
{
    qDebug()<<"power +1";
    m_pwoer ++;
    QVariant var(m_pwoer);
//    qDebug()<<var.toInt();
    m_stateMachine->submitEvent("pwoerUp", var);
}

//bool dataModel::evaluateToBool(QScxmlExecutableContent::EvaluatorId id, bool *ok)
//{

//}

//QString dataModel::evaluateToString(QScxmlExecutableContent::EvaluatorId id, bool *ok)
//{

//}

//QVariant dataModel::evaluateToVariant(QScxmlExecutableContent::EvaluatorId id, bool *ok)
//{

//}

//void dataModel::evaluateToVoid(QScxmlExecutableContent::EvaluatorId id, bool *ok)
//{

//}
