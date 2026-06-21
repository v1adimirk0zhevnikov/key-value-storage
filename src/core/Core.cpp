#include "Core.hpp"
#include <iostream>

void Core::foo() const {
	std::cout << "[Core] - foo was called" << std::endl;
}
