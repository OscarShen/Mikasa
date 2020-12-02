#pragma once

#include <string>
#include <fstream>
#include <filesystem>
#include <memory>
#include <functional>

#include "glm/glm.hpp"

#include "nlohmann/json.hpp"

#ifdef Core_EXPORTS
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif // MIKASA_CORE_EXPORT

#pragma warning(disable:4251)    

typedef int32_t int32;
typedef int64_t int64;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef std::string MString;
typedef std::ofstream MFileWriter;
typedef std::ifstream MFileReader;

namespace MFileSystem = std::filesystem;

template <typename T>
using TSharedPtr = std::shared_ptr<T>;

template <typename K, typename V>
using TMap = std::map<K, V>;

template <typename T>
using TArray = std::vector<T>;

template <typename T>
using TFunction = std::function<T>;

typedef glm::vec2 MVector2;
typedef glm::vec3 MVector;
typedef glm::vec4 MVector4;
typedef glm::mat3 MMatrix3;
typedef glm::mat4 MMatrix4;

typedef nlohmann::json MJson;

#define GET_MEMBER_NAME_CHECKED(ClassName, MemberName) ((void)sizeof(((ClassName*)0)->MemberName), #MemberName)

#define DEFINE_FACTORY(FactoryName, ReturnType)\
class FactoryName\
{\
public:\
    static TSharedPtr<ReturnType> CreateInstance(const MString& TypeName);\
    \
private:\
    TMap<MString, TFunction<TSharedPtr<MDisplay>>> InitFuncs;\
};