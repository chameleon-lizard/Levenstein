#include "levenshtein.h"
#include <cstdio>
#include <cassert>


bool run_test(int (*function)(char*, char*), char* s1, char* s2, int expected, int n_test) {
	bool res = (function(s1, s2) == expected);
	if (res) {
		printf("Test %d passed.\n", n_test);
	} else {
		printf("Test %d failed.\n", n_test);
	}
	return res;
}

bool run_tests(int (*function)(char*, char*), char** a, char** b, int* expected, std::size_t n) {
	std::size_t passed = 0;
	std::size_t failed = 0;
	for (std::size_t i = 0; i < n; i++) {
		if (run_test(levenshtein_recursive, a[i], b[i], expected[i], i)) {
			passed++;
		} else {
			failed++;
		}
	}
	printf("Total run of %zu tests: %zu passed, %zu failed\n", n, passed, failed);
}

int main() {
	char* a[] = {"abc", "xxx", "", "123", "aaaa", ""};
	char* b[] = {"abc", "yyy", "1123123", "", "asdfiuh", ""};
	int expected[] ={0, 3, 7, 3, 6, 0};
	printf("TEST SUITE WAGNER_FISHER:\n");
	run_tests(levenshtein_wagner_fisher, a, b, expected, 5);
	printf("============================\n");
	printf("TEST SUITE_RECURSIVE:\n");
	run_tests(levenshtein_recursive, a, b, expected, 5);
	printf("============================\n");
}

