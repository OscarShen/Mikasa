#include "FileHelper.h"
#include <filesystem>

std::string FFileHelper::GetResourcePath()
{
    return std::filesystem::current_path().string();
}
