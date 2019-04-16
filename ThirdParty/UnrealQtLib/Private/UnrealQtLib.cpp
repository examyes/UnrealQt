#include "UnrealQtLib.h"

#include <QCoreApplication>

namespace UnrealQt {

static QCoreApplication *qtApp = nullptr;

void Init()
{
    if (QCoreApplication::instance() == nullptr)
    {
        int argc = 1;
        char *argv[1];
        argv[0] = const_cast<char *>("UnrealQt");
        qtApp = new QCoreApplication(argc, argv);
    }
}

void ProcessEvent()
{
    if (qtApp != nullptr)
    {
        qtApp->processEvents();
    }
}


}



