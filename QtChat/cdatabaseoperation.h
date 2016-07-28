#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif
#ifndef CDATABASEOPERATION_H
#define CDATABASEOPERATION_H
#include "csoftwareconfig.h"
#include <QtSql>

class CDatabaseOperation
{
public:
    CDatabaseOperation();
    static QSqlError initDb();
    static QSqlError addUser(QSqlQuery &q, const QString &username, const QString &userpwd);
    static bool isUserExistInTables(QSqlQuery &q, const QString &username, const QString &tableName);
    static QSqlError addUserConfig(QSqlQuery &q, const QString &username, const QString &fontFamily, const int fontPointSize, const int fontColorR, const int fontColorB, const int fontColorG, const bool itatic, const bool bold);
    static QString getUserPassword(QSqlQuery &q, const QString &username);
    static QSqlError getWidgetConfig(QSqlQuery &q, QString username, CSoftwareConfig *config);
};

#endif // CDATABASEOPERATION_H
