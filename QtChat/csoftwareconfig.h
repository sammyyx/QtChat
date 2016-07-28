#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif
#ifndef CSOFTWARECONFIG_H
#define CSOFTWARECONFIG_H
#include <QString>
struct FontStruct
{
    QString fontFamily;
    int fontPointSize;
    bool itatic;
    bool bold;
    int colorR;
    int colorB;
    int colorG;

};
class CSoftwareConfig
{
public:
    CSoftwareConfig();
    QString chatMsg;
    QString chatUsr;
    struct FontStruct fontConfig;
};

#endif // CSOFTWARECONFIG_H
