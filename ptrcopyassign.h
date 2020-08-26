#pragma once

#include <iostream>
#include <memory>

namespace ptrcopyassign {

	// Class with raw pointer member
	struct Bar {
		Bar() {
			ptr = new int(5);
		}
		int* ptr;
	};

	// Class with smart unique pointer member
	struct Foo {
		Foo() {
			ptr = std::make_unique<int>(5);
		}
		std::unique_ptr<int> ptr;
	};

	void ptrcopyassign() {

		Bar b1;
		// Copy assignement allowed for Bar
		Bar b2 = b1;

		Foo f1;
		// Compiler error; copy assignmenet not allowed for Foo
		//Foo f2 = f1;
	}
}