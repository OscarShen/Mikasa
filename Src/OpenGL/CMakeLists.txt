project ("OpenGL")

file(GLOB_RECURSE MIKASA_OPENGL_SOURCE_FILES *.h *.cpp)

include_directories(${MIKASA_SOURCE_DIR})
include_directories(${MIKASA_CORE_DIR})
include_directories(${MIKASA_THIRD_PARTY_DIR})
include_directories(${MIKASA_THIRD_PARTY_DIR}/glfw/include)
include_directories(${MIKASA_THIRD_PARTY_DIR}/glm)
include_directories(${MIKASA_THIRD_PARTY_DIR}/glad/include)

link_directories(${MIKASA_LIB_DIR})

add_library(OpenGL SHARED ${MIKASA_OPENGL_SOURCE_FILES})
set_target_properties(OpenGL PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
set_target_properties(OpenGL PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${MIKASA_PROJECT_DIR}/Bin)
target_link_libraries(OpenGL debug Core_d optimized Core)
target_link_libraries(OpenGL debug glfw_d optimized glfw)
target_link_libraries(OpenGL debug glad_d optimized glad)

