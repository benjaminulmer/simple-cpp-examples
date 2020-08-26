#pragma once

#include <iostream>

namespace initialization {

	struct Foo {
		Foo() {
			std::cout << "Foo()" << std::endl;
		}
		Foo(int arg) {
			std::cout << "Foo(int)" << std::endl;
		}
	};

	// Not using initialization list
	// Two calls to constructor for foo
	struct Bar1 {
		Bar1(int arg) {
			foo = Foo(arg);
		}

		Foo foo;
	};

	// Using initialization list
	// Only one constructor call for foo
	struct Bar2 {
		Bar2(int arg) : foo(arg) {}

		Foo foo;
	};

	void initialization() {

		std::cout << "creating a Bar1" << std::endl;
		Bar1 bar1(5);
		std::cout << std::endl;
		std::cout << "creating a Bar2" << std::endl;
		Bar2 bar2(5);
	}
}