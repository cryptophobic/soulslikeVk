cmake_minimum_required(VERSION 3.23)
project(soulslikeVk)

find_package(Vulkan REQUIRED)

if (WIN32)
    include_directories(c:/VulkanSDK/1.3.224.1/Include/)
    set(ALL_LIBS glfw3 Vulkan::Vulkan)
endif (WIN32)


set(CMAKE_CXX_STANDARD 23)

add_executable(soulslikeVk main.cpp LveWindow.hpp LveWindow.cpp FirstApp.hpp FirstApp.cpp LvePipeline.cpp LvePipeline.hpp utils/FileSystemHelper.cpp utils/FileSystemHelper.hpp LveDevice.cpp LveDevice.hpp)
target_link_libraries(soulslikeVk ${ALL_LIBS})
