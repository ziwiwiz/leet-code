add_test( test_Solution.twoSum /home/ubuntu/code/leetcode/1.two-sum/buid/test_func [==[--gtest_filter=test_Solution.twoSum]==] --gtest_also_run_disabled_tests)
set_tests_properties( test_Solution.twoSum PROPERTIES WORKING_DIRECTORY /home/ubuntu/code/leetcode/1.two-sum/buid SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==] LABELS unit)
set( test_func_TESTS test_Solution.twoSum)
