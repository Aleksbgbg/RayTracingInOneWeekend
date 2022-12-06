set(BINARY_NAME ${CMAKE_PROJECT_NAME})

set(SOURCE_FILES main.cc core/types.h core/math/vec3.h core/math/square.h core/math/color.h core/math/ray.h core/math/Range.h core/math/transform.h core/math/blend.h)

add_executable(${BINARY_NAME} ${SOURCE_FILES})
target_include_directories(${BINARY_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
