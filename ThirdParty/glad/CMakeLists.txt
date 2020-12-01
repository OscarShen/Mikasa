project(glad)

file(GLOB_RECURSE GLAD_SOURCE_FILES *.h *.cpp *.c)

include_directories(${MIKASA_PROJECT_DIR}/ThirdParty/glad/include)
add_library(glad ${GLAD_SOURCE_FILES})
