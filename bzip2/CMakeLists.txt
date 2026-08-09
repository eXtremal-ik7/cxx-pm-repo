# bzip2 is distributed with plain makefiles only (Makefile for unix, makefile.msc
# for msvc); this file is copied into the source tree by the build script and
# builds the same libbz2 static library the upstream 'make libbz2.a' target does.
cmake_minimum_required(VERSION 3.12)

project(bzip2 LANGUAGES C VERSION 1.0.8)

include(GNUInstallDirs)

add_library(bz2 STATIC
  blocksort.c
  huffman.c
  crctable.c
  randtable.c
  compress.c
  decompress.c
  bzlib.c
)

set_target_properties(bz2 PROPERTIES POSITION_INDEPENDENT_CODE ON)

# BIGFILES from the upstream Makefile
target_compile_definitions(bz2 PRIVATE _FILE_OFFSET_BITS=64)

if (MSVC)
  target_compile_definitions(bz2 PRIVATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE)
endif()

install(TARGETS bz2
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(FILES bzlib.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
