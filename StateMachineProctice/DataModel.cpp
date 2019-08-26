/** *******************************************************
    @brief		:
    @author		:zhongyl
    @date		:2019-08-19
    @version	:v1.0
    @copyright	:Copyright (C) 2019 - All Rights Reserved
    @warning	:
    @note		:

******************************************************** **/
#include "DataModel.h"

//DataModel::DataModel()
//{

//}

bool DataModel::isMoreThan50() const
{
    return m_power > 50;

}

bool DataModel::isLessThan50() const
{
    return m_power < 50;
}

//bool DataModel::evaluateToBool(QScxmlExecutableContent::EvaluatorId id, bool *ok) {
//    // ....
////        return [this]()->bool{ return isValidMedia(); }();
//    // ....
//    return [this]()->bool{ return isMoreThan50(); }();
//}

//QVariant DataModel::evaluateToVariant(QScxmlExecutableContent::EvaluatorId id, bool *ok) {
//    // ....
////        return [this]()->QVariant{ return media; }();
//    // ....
//    return [this]()->QVariant{ return m_var; }();
//}

//void DataModel::evaluateToVoid(QScxmlExecutableContent::EvaluatorId id, bool *ok) {
//    // ....
////        [this]()->void{ media = eventData().value(QStringLiteral("media")).toString(); }();
//    // ....


//    [this]()->void{ m_var = scxmlEvent().data().toString();}();
//}

//QString DataModel::evaluateToString(QScxmlExecutableContent::EvaluatorId id, bool *ok)
//{
//    [this]()->QString{ QString() ;}();
//}

//stateMachine->connectToState("state1", [this](bool active) {
//    QScxmlDataModel* dataModel = stateMachine->dataModel(); //Returns a
//null pointer
//    QScxmlCppDataModel* cppDataModel =
//static_cast<QScxmlCppDataModel*>(dataModel);
//    QScxmlEvent event = cppDataModel->scxmlEvent();
//    QVariant data = event.data();
//    qDebug() << "event.data()" << data;
//});
