#pragma once

#include <array>
#include <iostream>
#include <vector>

namespace containers {

	struct Foo {
		~Foo() {
			std::cout << "foo destroyed" << std::endl;
		}
	};

	// c style array on the stack
	// Safe
	struct StackArray {
		Foo ary[1];
	};

	// Array on the stack using stl
	// Just as memory efficient as above
	// Safe
	struct StdArray {
		std::array<Foo, 1> ary;
	};

	// c style array on the heap
	// Not safe; need to cleanup
	// Avoid use
	struct HeapArray {
		HeapArray(int size) {
			ary = new Foo[size];
		}
		Foo* ary;
	};

	// Dynamic array on heap using stl
	// Allows resizing as needed
	// Safe; use instead of c style array on heap
	struct StdVector {
		StdVector(int size) : ary(size) {}
		std::vector<Foo> ary;
	};

	void containers() {

		{
			std::cout << "c style stack" << std::endl;
			StackArray foo;
		}
		std::cout << std::endl;
		// no memory leak

		{
			std::cout << "std::array" << std::endl;
			StdArray foo;
		}
		std::cout << std::endl;
		// no memory leak

		{
			std::cout << "c style heap" << std::endl;
			HeapArray foo(1);
		}
		std::cout << std::endl;
		// memory leak!!!

		{
			std::cout << "std::vector" << std::endl;
			StdVector foo(1);
		}
		std::cout << std::endl;
		// no memory leak
	}
}