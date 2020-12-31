set(COMMON_FILES 
    deps/glad/glad.h
    deps/KHR/khrplatform.h
    deps/glad.c
    include/GLFW/glfw3.h
    include/GLFW/glfw3native.h
    src/internal.h
    src/glfw_config.h
    src/context.c 
    src/init.c 
    src/input.c 
    src/monitor.c 
    src/vulkan.c 
    src/window.c
)    
if(MSVC)
    set(SOURCE_FILES ${COMMON_FILES} 
        src/win32_platform.h 
        src/win32_joystick.h
        src/wgl_context.h 
        src/egl_context.h
        src/win32_init.c 
        src/win32_joystick.c
        src/win32_monitor.c 
        src/win32_time.c 
        src/win32_tls.c 
        src/win32_window.c
        src/wgl_context.c 
        src/egl_context.c
    )
endif(MSVC)

source_group_by_dir(SOURCE_FILES)

add_library(glfw3 STATIC ${SOURCE_FILES})

target_include_directories(glfw3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/deps)

target_compile_definitions(glfw3 PRIVATE -D_GLFW_USE_CONFIG_H)