cmake_minimum_required(VERSION 3.5)

project(SFML_Game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR "C:\\SFML-2.6.1\\lib\\cmake\\SFML")

find_package(SFML COMPONENTS graphics window system REQUIRED)

file(GLOB SOURCES "src/*.cpp" "src/*.h" "src/*.hpp")

add_executable(SFML_Game ${SOURCES})

target_link_libraries(SFML_Game PRIVATE sfml-graphics sfml-window sfml-system)

# #MinGw Build

# # MinGW Build
# # Specify the MinGW generator
# set(CMAKE_GENERATOR "MinGW Makefiles")

# # Specify the MinGW C++ compiler
# set(CMAKE_CXX_COMPILER "g++")

# # Set the path to the MinGW bin directory
# set(CMAKE_MAKE_PROGRAM "/mingw64/bin/mingw32-make.exe")

# # Specify the output directory for the executable
# set_target_properties(SFML_Game PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/build"
#     )

# # Install target
# include(GNUInstallDirs)
# install(TARGETS SFML_Game
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#     )

include(GNUInstallDirs)
install(TARGETS SFML_Game
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
