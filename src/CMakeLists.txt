OPTION(ENABLE_MAIN "Main Process" ON)
if(ENABLE_MAIN)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    file(GLOB UTILS_CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/Utils/*.cpp)

    message( STATUS "UTILS_CPP_FILES is as following: ${UTILS_CPP_FILES} ")

    option(ENABLE_ADDRESS_SANITIZER "Enable Address Sanitizer on Linux" OFF)

    # 检查是否为 Linux 系统且选项开启
    if(UNIX AND NOT APPLE AND ENABLE_ADDRESS_SANITIZER)
        add_definitions(-D_DISABLE_VECTOR_ANNOTATION)
        add_definitions(-D_DISABLE_STRING_ANNOTATION)
        # 设置 C 和 C++ 编译选项
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
        # 设置可执行文件和共享库的链接选项
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fsanitize=address")
    endif()
    add_library(TestTool ${UTILS_CPP_FILES})

    target_include_directories(TestTool PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Utils/)

    add_executable(${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    )

    target_link_libraries (${PROJECT_NAME}
        TestTool
    )

    message( STATUS "Enable main process.")
else()
    message( STATUS "No main process.")
endif()