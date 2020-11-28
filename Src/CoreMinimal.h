#pragma once

#include <string>
#include <fstream>
#include <filesystem>

#include "glm/glm.hpp"

#include "nlohmann/json.hpp"

typedef int32_t MInt32;
typedef int64_t MInt64;

typedef std::string MString;
typedef std::ofstream MFileWriter;
typedef std::ifstream MFileReader;

namespace MFileSystem = std::filesystem;

typedef glm::vec2 MVector2;
typedef glm::vec3 MVector3;
typedef glm::mat3 MMatrix3;
typedef glm::mat4 MMatrix4;

typedef nlohmann::json MJson;

#define GET_MEMBER_NAME_CHECKED(ClassName, MemberName) \
     ((void)sizeof(((ClassName*)0)->MemberName), #MemberName)