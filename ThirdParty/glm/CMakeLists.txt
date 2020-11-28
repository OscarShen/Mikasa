project(glm)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

set(GLM_STATIC_LIBRARY_ENABLE 1)

if(CMAKE_COMPILER_IS_GNUCXX)
	#add_definitions(-S)
	#add_definitions(-s)
	add_definitions(-O2)

	#add_definitions(-fprofile-arcs -ftest-coverage) gcov
	#ctest_enable_coverage()
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_definitions(/FAs)
endif()

include_directories("${PROJECT_SOURCE_DIR}")

add_subdirectory(glm)

export(PACKAGE glm)
