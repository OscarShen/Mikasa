project ("Core")

file(GLOB_RECURSE MIKASA_CORE_SOURCE_FILES *.h *.cpp)

include_directories(${MIKASA_SOURCE_DIR})
include_directories(${MIKASA_CORE_DIR})
include_directories(${MIKASA_THIRD_PARTY_DIR})
include_directories(${MIKASA_THIRD_PARTY_DIR}/glfw/include)
include_directories(${MIKASA_THIRD_PARTY_DIR}/glm)
include_directories(${MIKASA_THIRD_PARTY_DIR}/glad/include)

link_directories(${MIKASA_LIB_DIR})

add_library(Core SHARED ${MIKASA_CORE_SOURCE_FILES})
set_target_properties(Core PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(Core PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${MIKASA_PROJECT_DIR}/Bin)
target_link_libraries(Core debug glfw_d optimized glfw)
target_link_libraries(Core debug glad_d optimized glad)

foreach(MIKASA_CORE_SOURCE_FILE IN ITEMS ${MIKASA_CORE_SOURCE_FILES})
    get_filename_component(MIKASA_CORE_FILE_SOURCE_DIR ${MIKASA_CORE_SOURCE_FILE} PATH)
    file(RELATIVE_PATH MIKASA_CORE_SOURCE_RELATIVE_DIR "${MIKASA_CORE_DIR}" "${MIKASA_CORE_FILE_SOURCE_DIR}")
    string(REPLACE "/" "\\" MIKASA_CORE_GROUP_DIR "${MIKASA_CORE_SOURCE_RELATIVE_DIR}")
    source_group("${MIKASA_CORE_GROUP_DIR}" FILES "${MIKASA_CORE_SOURCE_FILE}")
endforeach()