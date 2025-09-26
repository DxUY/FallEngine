file(GLOB_RECURSE EDITOR_SRC CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")

add_executable(Editor ${EDITOR_SRC})

# Link against FallEngine DLL
target_link_libraries(Editor PRIVATE FallEngine)

# Define platform-specific macros (no F_BUILD_DLL here!)
target_compile_definitions(Editor PRIVATE F_PLATFORM_WINDOWS)

# Include FallEngine headers
target_include_directories(Editor PRIVATE ${CMAKE_SOURCE_DIR}/FallEngine/src)
