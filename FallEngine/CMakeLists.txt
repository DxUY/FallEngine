# FallEngine/CMakeLists.txt

file(GLOB_RECURSE FALLENGINE_SRC CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")

# Build FallEngine as a shared (DLL) library
add_library(FallEngine SHARED ${FALLENGINE_SRC} "src/FallEngine/EntryPoint.h" "src/FallEngine.h" "src/FallEngine/Log.h" "src/FallEngine/Log.cpp")

# Set preprocessor definitions for platform and DLL export
target_compile_definitions(FallEngine PRIVATE F_PLATFORM_WINDOWS F_BUILD_DLL)

# Include path for engine headers
target_include_directories(FallEngine PUBLIC src)

# Find and link spdlog from vcpkg
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(FallEngine PUBLIC spdlog::spdlog)

add_custom_command(TARGET FallEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:FallEngine>
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>
    COMMENT "Copying FallEngine DLL to output directory"
)