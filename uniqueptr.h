#pragma once

#include <iostream>

namespace uniqueptr {

	struct Foo {
		~Foo() {
			std::cout << "foo destroyed" << std::endl;
		}
	};

	// Raw pointer
	// Do not use for ownership
	struct RawPtr {
		RawPtr() : foo(new Foo()) {}
		Foo* foo;
	};

	// Smart pointer
	// Has ownership
	struct UniquePtr {
		UniquePtr() : foo(new Foo()) {}
		std::unique_ptr<Foo> foo;
	};

	void uniqueptr() {

		{
			std::cout << "raw pointer" << std::endl;
			RawPtr foo;
		}
		std::cout << std::endl;
		// memory leak!!!

		{
			std::cout << "smart pointer" << std::endl;
			UniquePtr foo;
		}
		std::cout << std::endl;
		// no memory leak
	}
}