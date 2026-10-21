#ifndef TEST_H
#define TEST_H

#include <stddef.h>

#define MAX_TESTS 1000

#define Test(test_ident) \
    void test_ident(void); \
    __attribute__((constructor)) \
    void register_##test_ident() { \
        test_registry[tests_registered++] = (TestData) { \
            .test_fn = test_ident, \
            .name = #test_ident, \
        }; \
    } \
    void test_ident(void)

typedef struct {
    const char *name;
    void (*test_fn) (void);
} TestData;

extern size_t tests_registered;
extern TestData test_registry[MAX_TESTS];

#ifdef TEST_MAIN

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include "tests.h"

size_t tests_registered = 0;
TestData test_registry[MAX_TESTS];

int main(void) {
    printf("Running %zu Tests...\n", tests_registered);

    size_t tests_failed = 0;

    for (size_t i = 0; i < tests_registered; i++) {
        TestData test = test_registry[i];
        printf("Running %s...\n", test.name);

        pid_t child_pid = fork();
        switch (child_pid) {
            case -1: // Fork Error
                return 1;
            case 0: // Child
                test.test_fn();
                return 0;
            default: // Parent
                int child_rc = 0;
                waitpid(child_pid, &child_rc, 0);
                if (child_rc != 0) {
                    tests_failed++;
                }
        }
    }

    printf("Tests Failed: %zu\n", tests_failed);
    return 0;
}

#endif
#endif
