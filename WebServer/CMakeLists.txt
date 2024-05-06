# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("MusicServer")

# 包含子项目。

set (CXX_STANDARD 17)

file (GLOB_RECURSE include_file "./*.h")

file (GLOB_RECURSE src_file "./*.cpp" "./*.cc")

include_directories (
	Tool
	Mysql
	Redis
	Server/GateServer
	Server/VarifyServer
	Message
	Service
	LogicSystem
	HttpConnection
)

add_executable (MusicServer ${src_file} ${include_file} main.cpp)
target_link_libraries(MusicServer PRIVATE -Wl,--wrap=memcpy)


target_link_libraries (MusicServer PUBLIC fmt)
target_link_libraries (MusicServer PUBLIC spdlog)
target_link_libraries (MusicServer PUBLIC jsoncpp)
target_link_libraries (MusicServer PUBLIC protobuf)
target_link_libraries (MusicServer PUBLIC hiredis)
target_link_libraries (MusicServer PUBLIC grpc++)
target_link_libraries (MusicServer PUBLIC grpc)
target_link_libraries (MusicServer PUBLIC mysqlcppconn)
target_link_libraries (MusicServer PUBLIC boost_filesystem)
target_link_libraries (MusicServer PUBLIC boost_system)
#target_link_libraries (WebServer PUBLIC glibc)