function(add_test_executable NAME)
  set(MULTI_VALUE_ARGS PRIVATE_TESTS SOLUTION_SRCS)
  cmake_parse_arguments(TEST_LIBRARY "" "" "${MULTI_VALUE_ARGS}" ${ARGN})

  # get_filename_component(TASK_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

  add_executable(${NAME}
    ${TEST_LIBRARY_UNPARSED_ARGUMENTS})

  target_include_directories(${NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
endfunction()

add_custom_target(test-all)

function(add_catch TARGET)
  add_test_executable(${TARGET}
    ${ARGN})

  target_link_libraries(${TARGET}
    contrib_catch_main)
endfunction()
