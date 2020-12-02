#include "ModuleUtil.h"

#ifdef WIN32
#include <Windows.h>
#endif // WIN32


std::string FModuleUtil::GetDllName(const std::string& DllPrefix)
{
#ifdef NDEBUG
    return DllPrefix + ".dll";
#else
    return DllPrefix + "_d.dll";
#endif
}

bool FModuleUtil::LoadDynamicLibrary(const std::string& DllPrefix)
{
    auto Result = LoadLibrary(GetDllName(DllPrefix).c_str());
    return Result != NULL;
}
