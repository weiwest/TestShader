cmake_minimum_required(VERSION 3.10)

project(TestShader)


#设置变量
set(PROJECT_ROOT_PATH   ${CMAKE_CURRENT_SOURCE_DIR})

# cmake 全局设置 
## show detail info
set(CMAKE_VERBOSE_MAKEFILE ON)
## open use folder
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
## 设置编译模式 只保留 Debug Release
set(CMAKE_CONFIGURATION_TYPES Debug Release)

# cmake 工具函数
function(source_group_by_dir source_files)
    if(WIN32)
        set(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
        foreach(sgbd_file ${${source_files}})
            string(REGEX REPLACE ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_file})
            string(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
            string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
            string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
            if(sgbd_nogroup)
                set(sgbd_group_name "\\")
            endif(sgbd_nogroup)
            source_group(${sgbd_group_name} FILES ${sgbd_file})
        endforeach(sgbd_file)
    endif()
endfunction()
    
# 添加各个平台宏定义 WIN32 ANDROID IOS 是cmake内置宏定义
if(WIN32)
    set(PLATFORM_FOLDER_NAME win32)

    # 设置输出目录
    set(RUNTIME_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/runtime/${PLATFORM_FOLDER_NAME})
    set(ARCHIVE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/${PLATFORM_FOLDER_NAME})

    #添加c++编译选项
    set(CMAKE_CXX_FLAGS "/MP /Z7 /W3 /Od /EHsc /RTC1 /D_WIN32 /D_CONSOLE /D_UNICODE")
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd /D_DEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "")

    #添加c编译选项
    set(CMAKE_C_FLAGS "/fp:fast")
    set(CMAKE_C_FLAGS_DEBUG "")
    set(CMAKE_C_FLAGS_RELEASE "")

    #设置输出目录
    # 静态库目录
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ARCHIVE_OUTPUT_PATH})
    # 动态库目录
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${RUNTIME_OUTPUT_PATH})
    # exe目录
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${RUNTIME_OUTPUT_PATH})

    #添加链接目录
    link_directories(
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} 
        ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
    )
    
    # 添加编译选项
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

add_subdirectory("glfw3")
add_subdirectory("src")

# 设置启动项目, 必须在最外层的CMAKELists.txt中设置
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "TestShader")
