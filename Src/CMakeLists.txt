project ("Mikasa")

file(GLOB_RECURSE MIKASA_SOURCE_FILES *.h *.cpp)

set(MIKASA_SOURCE_DIR ${MIKASA_PROJECT_DIR}/Src)
set(MIKASA_LIB_DIR ${MIKASA_PROJECT_DIR}/Lib)
set(MIKASA_THIRD_PARTY_DIR ${MIKASA_PROJECT_DIR}/ThirdParty)

include_directories(${MIKASA_SOURCE_DIR})
include_directories(${MIKASA_THIRD_PARTY_DIR})
include_directories(${MIKASA_THIRD_PARTY_DIR}/glfw/include)
include_directories(${MIKASA_THIRD_PARTY_DIR}/glm)

link_directories(${MIKASA_LIB_DIR})

if (MSVC_VERSION GREATER_EQUAL "1900")
    set(MIKASA_MSVC_CPP_17 /std:c++17)
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG(${MIKASA_MSVC_CPP_17} CPP_LATEST_FLAG_SUPPORTED)
    if (${CPP_LATEST_FLAG_SUPPORTED})
        add_compile_options(${MIKASA_MSVC_CPP_17})
    endif()
endif()

add_executable(Mikasa ${MIKASA_SOURCE_FILES})
set_target_properties(Mikasa PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_link_libraries(Mikasa debug glfw_d optimized glfw)

set_target_properties(Mikasa PROPERTIES 
                        VS_DEBUGGER_WORKING_DIRECTORY ${MIKASA_PROJECT_DIR}/Bin)
                        #VS_DEBUGGER_COMMAND           ${MIKASA_PROJECT_DIR}/Bin)

foreach(MIKASA_SOURCE_FILE IN ITEMS ${MIKASA_SOURCE_FILES})
    get_filename_component(MIKASA_FILE_SOURCE_DIR ${MIKASA_SOURCE_FILE} PATH)
    file(RELATIVE_PATH MIKASA_SOURCE_RELATIVE_DIR "${MIKASA_SOURCE_DIR}" "${MIKASA_FILE_SOURCE_DIR}")
    string(REPLACE "/" "\\" MIKASA_GROUP_DIR "${MIKASA_SOURCE_RELATIVE_DIR}")
    source_group("${MIKASA_GROUP_DIR}" FILES "${MIKASA_SOURCE_FILE}")
endforeach()