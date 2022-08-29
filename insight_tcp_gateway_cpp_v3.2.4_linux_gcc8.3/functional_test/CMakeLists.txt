# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.5)

# 项目信息
project (functional_test)

# 版本信息
set (Demo_VERSION_MAJOR 1)
set (Demo_VERSION_MINOR 0)

# 编译参数
set (CMAKE_BUILE_TYPE DEBUG) 
add_definitions(-DDEBUG)
add_definitions("-Wall -g")

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)
aux_source_directory(protobuf DIR_LIB_SRCS)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
     message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# 添加子目录
#add_subdirectory(protobuf)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../build)

# 链接库目录
link_directories ("${PROJECT_SOURCE_DIR}/../build/")

# 添加包含目录
include_directories("${PROJECT_SOURCE_DIR}"
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/protobuf"
	"${PROJECT_SOURCE_DIR}/../include/mdc_gateway_client/include"
	"${PROJECT_SOURCE_DIR}/../include/protobuf-3.1.0/include")
	
# 生成可执行对象
add_executable (functional_test ${DIR_LIB_SRCS})

# 添加链接库
target_link_libraries(functional_test ACE.so)
target_link_libraries(functional_test ACE_SSL.so)
target_link_libraries(functional_test protobuf.so)
target_link_libraries(functional_test mdc_gateway_client.so)

