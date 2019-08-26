/** *******************************************************
    @brief		:
    @author		:zhongyl
    @date		:2019-08-21
    @version	:v1.0
    @copyright	:Copyright (C) 2019 - All Rights Reserved
    @warning	:
    @note		:

******************************************************** **/
#ifndef POWERSTATEMACHINE_H
#define POWERSTATEMACHINE_H

#include <QObject>
#include <QScxmlStateMachine>
#include <QString>
#include <QVariant>

#include "DataModel.h"

class PowerStateMachine : public QScxmlStateMachine
{
    Q_OBJECT
public:
    explicit PowerStateMachine();

signals:

public slots:

private:
    struct Data;
    friend struct Data;
    struct Data *data;

    DataModel m_dataMode;
};

Q_DECLARE_METATYPE(::PowerStateMachine*)
#endif // POWERSTATEMACHINE_H
