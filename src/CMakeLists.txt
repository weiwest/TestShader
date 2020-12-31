
FILE(GLOB SOURCE_FILES 
	${CMAKE_CURRENT_SOURCE_DIR}/*.h 
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/../shader/*.frag 
    ${CMAKE_CURRENT_SOURCE_DIR}/../shader/*.vert

    ${CMAKE_CURRENT_SOURCE_DIR}/../res/*.png
    ${CMAKE_CURRENT_SOURCE_DIR}/../res/*.jpg
)
source_group_by_dir(SOURCE_FILES)

set(target_name "TestShader")

add_executable(${target_name} WIN32 ${SOURCE_FILES})

target_include_directories(${target_name} PRIVATE 
    ${PROJECT_ROOT_PATH}
    ${PROJECT_ROOT_PATH}/src
    ${PROJECT_ROOT_PATH}/glfw3/deps
    ${PROJECT_ROOT_PATH}/glfw3/include
)

set_target_properties(${target_name} PROPERTIES
    LINK_FLAGS /SUBSYSTEM:CONSOLE
)

target_link_libraries (${target_name}
    glfw3
)
