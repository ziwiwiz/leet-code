if(EXISTS "/home/ubuntu/code/leetcode/1.two-sum/buid/test_func[1]_tests.cmake")
  include("/home/ubuntu/code/leetcode/1.two-sum/buid/test_func[1]_tests.cmake")
else()
  add_test(test_func_NOT_BUILT test_func_NOT_BUILT)
endif()
