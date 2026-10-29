function(add_sources TARGET)
  add_executable(${TARGET}
    ${ARGN})

  target_include_directories(${TARGET}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

  target_link_libraries(${TARGET}
    contrib_catch_main)
endfunction()
