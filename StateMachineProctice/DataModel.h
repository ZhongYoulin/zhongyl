/** *******************************************************
    @brief		:
    @author		:zhongyl
    @date		:2019-08-19
    @version	:v1.0
    @copyright	:Copyright (C) 2019 - All Rights Reserved
    @warning	:
    @note		:

******************************************************** **/
#ifndef DATAMODEL_H
#define DATAMODEL_H

//#include <QScxmlCppDataModel>
#include "qscxmlcppdatamodel.h"
#include <QScxmlEvent>

class DataModel :public QScxmlCppDataModel
{
    Q_OBJECT
    Q_SCXML_DATAMODEL

public:
//    DataModel();

    bool isMoreThan50() const;
    bool isLessThan50() const ;

    int m_power;
    QString m_Descript;
    QVariant m_var;


};

#endif // DATAMODEL_H
