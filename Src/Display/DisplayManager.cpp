#include "DisplayManager.h"

MDisplayManager::MDisplayManager()
{

}

MDisplayManager& MDisplayManager::Get()
{
    static MDisplayManager DisplayManager;
    return DisplayManager;
}

void MDisplayManager::CreateDisplay()
{
}
