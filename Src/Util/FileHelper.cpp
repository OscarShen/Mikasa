#include "FileHelper.h"

MString MFileHelper::GetResourcePath()
{
    return MFileSystem::current_path().string();
}
