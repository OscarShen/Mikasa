#pragma once

#include <string>
#include <memory>
#include <functional>
#include <map>
#include <vector>

#include "glm/glm.hpp"

#ifdef Core_EXPORTS
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif // MIKASA_CORE_EXPORT

#pragma warning(disable:4251)    

#define GET_MEMBER_NAME_CHECKED(ClassName, MemberName) ((void)sizeof(((ClassName*)0)->MemberName), #MemberName)
#define GET_ENUM_NAME_CHECKED(ClassName, EnumName) ((void)sizeof(ClassName::EnumName), #EnumName)

class FDisplay;
typedef std::shared_ptr<FDisplay> FDisplayPtr;
