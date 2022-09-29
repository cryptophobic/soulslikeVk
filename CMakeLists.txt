cmake_minimum_required(VERSION 3.23)
project(soulslikeVk)

function(add_shader TARGET SHADER)
    find_program(GLSLC glslc)

    set(current-shader-path ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER})
    set(current-output-path ${CMAKE_CURRENT_SOURCE_DIR}/${SHADER}.spv)

    # Add a custom command to compile GLSL to SPIR-V.
    get_filename_component(current-output-dir ${current-output-path} DIRECTORY)
    file(MAKE_DIRECTORY ${current-output-dir})

    add_custom_command(
            OUTPUT ${current-output-path}
            COMMAND ${GLSLC} -o ${current-output-path} ${current-shader-path}
            DEPENDS ${current-shader-path}
            IMPLICIT_DEPENDS CXX ${current-shader-path}
            VERBATIM)

    # Make sure our build depends on this output.
    set_source_files_properties(${current-output-path} PROPERTIES GENERATED TRUE)
    target_sources(${TARGET} PRIVATE ${current-output-path})
endfunction(add_shader)

find_package(Vulkan REQUIRED)

if (WIN32)
    include_directories(c:/VulkanSDK/1.3.224.1/Include/)
    set(ALL_LIBS glfw3 Vulkan::Vulkan)
endif (WIN32)


set(CMAKE_CXX_STANDARD 23)

add_executable(soulslikeVk
        main.cpp LveWindow.hpp LveWindow.cpp FirstApp.hpp FirstApp.cpp LvePipeline.cpp
        LvePipeline.hpp utils/FileSystemHelper.cpp utils/FileSystemHelper.hpp LveDevice.cpp
        LveDevice.hpp LveSwapChain.cpp LveSwapChain.hpp)
target_link_libraries(soulslikeVk ${ALL_LIBS})

add_shader(soulslikeVk shaders/SimpleShader.vert)
add_shader(soulslikeVk shaders/SimpleShader.frag)
