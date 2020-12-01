project ("Main")

file(GLOB_RECURSE MIKASA_MAIN_SOURCE_FILES *.h *.cpp)

include_directories(${MIKASA_SOURCE_DIR})
include_directories(${MIKASA_CORE_DIR})
include_directories(${MIKASA_THIRD_PARTY_DIR})
include_directories(${MIKASA_THIRD_PARTY_DIR}/glfw/include)
include_directories(${MIKASA_THIRD_PARTY_DIR}/glm)
include_directories(${MIKASA_THIRD_PARTY_DIR}/glad/include)

link_directories(${MIKASA_LIB_DIR})

add_executable(Main ${MIKASA_MAIN_SOURCE_FILES})
set_target_properties(Main PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(Main PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${MIKASA_PROJECT_DIR}/Bin)
target_link_libraries(Main debug Core_d optimized Core)
target_link_libraries(Main debug glfw_d optimized glfw)
target_link_libraries(Main debug glad_d optimized glad)