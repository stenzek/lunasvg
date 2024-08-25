cmake_minimum_required(VERSION 3.5)

project(lunasvg VERSION 2.4.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

option(BUILD_SHARED_LIBS "Build as a shared library" ON)
option(LUNASVG_BUILD_EXAMPLES "Build example(s)" OFF)

if(BUILD_SHARED_LIBS)
  add_library(lunasvg SHARED)
else()
  add_library(lunasvg STATIC)
endif()

add_subdirectory(include)
add_subdirectory(source)
add_subdirectory(3rdparty/plutovg)

target_compile_definitions(lunasvg PRIVATE LUNASVG_BUILD)
if(NOT BUILD_SHARED_LIBS)
    target_compile_definitions(lunasvg PRIVATE LUNASVG_BUILD_STATIC)
endif()

if(LUNASVG_BUILD_EXAMPLES)
    add_executable(svg2png svg2png.cpp)
    target_link_libraries(svg2png PRIVATE lunasvg)
    target_include_directories(svg2png PRIVATE 3rdparty/stb)
endif()

include(GNUInstallDirs)

if(NOT BUILD_SHARED_LIBS)
  install(FILES
      include/lunasvg.h
      DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )
endif()
install(FILES
    include/lunasvg_c.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(TARGETS lunasvg
    EXPORT      lunasvgTargets
    RUNTIME     DESTINATION    ${CMAKE_INSTALL_BINDIR}
    LIBRARY     DESTINATION    ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE     DESTINATION    ${CMAKE_INSTALL_LIBDIR}
    INCLUDES    DESTINATION    ${CMAKE_INSTALL_INCLUDEDIR}
)

include(CMakePackageConfigHelpers)
set(LUNASVG_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/lunasvg")
install(
  EXPORT lunasvgTargets
  FILE lunasvgTargets.cmake
  NAMESPACE lunasvg::
  DESTINATION "${LUNASVG_INSTALL_CMAKEDIR}"
)
configure_package_config_file(lunasvgConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/lunasvgConfig.cmake"
  INSTALL_DESTINATION "${LUNASVG_INSTALL_CMAKEDIR}"
)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/lunasvgConfigVersion.cmake"
  VERSION "${CMAKE_PROJECT_VERSION}"
  COMPATIBILITY SameMajorVersion
)
install(
  FILES
    "${CMAKE_CURRENT_BINARY_DIR}/lunasvgConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/lunasvgConfigVersion.cmake"
    DESTINATION "${LUNASVG_INSTALL_CMAKEDIR}"
)
