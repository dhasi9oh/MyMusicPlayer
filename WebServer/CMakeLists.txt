# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("WebServer")

# 包含子项目。

set (CXX_STANDARD 14)

file (GLOB_RECURSE include_file "./*.h")

file (GLOB_RECURSE src_file "./*.cpp" "./*.cc")

include_directories (
	Tool
	Mysql
	Redis
	Server
	Message
	Service
	LogicSystem
	HttpConnection
	jsoncpp/include
)

add_executable (WebServer ${src_file} ${include_file})

target_link_libraries (WebServer PUBLIC spdlog)

target_link_libraries (WebServer PUBLIC jsoncpp)

