#include <iostream>
#include "test_print.h"

int close(float x) {
	if (x < 1) {
		std::cout << "working!" << std::endl;

		return 0;
	}
}