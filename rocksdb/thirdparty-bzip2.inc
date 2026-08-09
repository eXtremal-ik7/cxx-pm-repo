
# ================================================== BZIP2 ==================================================
# Appended to thirdparty.inc by the cxx-pm build script: rocksdb msvc builds take
# all third party library paths from thirdparty.inc, but upstream has no bzip2
# section there (bzip2 is handled by find_package for non-msvc builds only)

# For compatibilty
if (BZIP2)
  set(WITH_BZ2 ON)
endif ()

if (WITH_BZ2)
  message(STATUS "BZIP2 library is enabled")

  if(DEFINED ENV{BZIP2_INCLUDE})
    set(BZIP2_INCLUDE $ENV{BZIP2_INCLUDE})
  endif()

  if(DEFINED ENV{BZIP2_LIB_DEBUG})
    set(BZIP2_LIB_DEBUG $ENV{BZIP2_LIB_DEBUG})
  endif()

  if(DEFINED ENV{BZIP2_LIB_RELEASE})
    set(BZIP2_LIB_RELEASE $ENV{BZIP2_LIB_RELEASE})
  endif()

  set(BZIP2_CXX_FLAGS -DBZIP2)
  set(BZIP2_LIBS debug ${BZIP2_LIB_DEBUG} optimized ${BZIP2_LIB_RELEASE})

  add_definitions(${BZIP2_CXX_FLAGS})
  include_directories(${BZIP2_INCLUDE})
  set (THIRDPARTY_LIBS ${THIRDPARTY_LIBS} ${BZIP2_LIBS})
else ()
  message(STATUS "BZIP2 library is disabled")
endif ()
