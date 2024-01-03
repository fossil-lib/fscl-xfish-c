/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

#include <fossil/module.h> // library under test

//
// XUNIT-DATA: test data for use in current project test cases
//
XTEST_DATA(ProjectTestData) {
    char *one;
    char *two;
}project_data;

//
// XUNIT-FIXTURE: test fixture for setup/teardown and other tesk
//
XTEST_FIXTURE(project_tests);
XTEST_SETUP(project_tests) {
    project_data.one = "Something";
    project_data.two = "Coffe Cup";
}

XTEST_TEARDOWN(project_tests) {
    // empty
}

//
// XUNIT-CASES: list of test cases testing project features
//
XTEST_CASE_FIXTURE(project_tests, basic_run_of_string) {
    TEST_ASSERT_EQUAL_CSTRING(project_data.one, project_data.one);
    TEST_ASSERT_NOT_EQUAL_CSTRING(project_data.one, project_data.two);
}

XTEST_CASE_FIXTURE(project_tests, basic_run_of_pointer) {
    TEST_ASSERT_NOT_CNULLPTR("Coffee Cup");
    TEST_ASSERT_CNULLPTR(NULL);
}

XTEST_CASE_FIXTURE(project_tests, basic_run_of_boolean) {
    TEST_ASSERT_TRUE(true);
    TEST_ASSERT_FALSE(false);
}

XTEST_CASE_FIXTURE(project_tests, basic_run_of_subtract) {
    TEST_ASSERT_TRUE(subtract(4, 2) == 2);
    TEST_ASSERT_FALSE(subtract(2, 55) == 2);
}

XTEST_CASE_FIXTURE(project_tests, basic_run_of_adding) {
    TEST_ASSERT_TRUE(add(2, 2) == 4);
    TEST_ASSERT_FALSE(add(2, 3) == 42);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(basic_group) {
    XTEST_RUN_FIXTURE(basic_run_of_string,   project_tests);
    XTEST_RUN_FIXTURE(basic_run_of_pointer,  project_tests);
    XTEST_RUN_FIXTURE(basic_run_of_boolean,  project_tests);
    XTEST_RUN_FIXTURE(basic_run_of_subtract, project_tests);
    XTEST_RUN_FIXTURE(basic_run_of_adding,   project_tests);
} // end of fixture
