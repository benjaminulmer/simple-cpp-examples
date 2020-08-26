#pragma once

#include <iostream>

namespace destructors {

	struct Foo {
		~Foo() {
			std::cout << "foo destroyed" << std::endl;
		}
	};

	struct Bar : public Foo {
		~Bar() {
			std::cout << "bar destroyed" << std::endl;
		}
	};

	struct vFoo {
		virtual ~vFoo() {
			std::cout << "vfoo destroyed" << std::endl;
		}
	};

	struct vBar : public vFoo {
		virtual ~vBar() {
			std::cout << "vbar destroyed" << std::endl;
		}
	};

	void destructors() {

		{
			Foo foo;
			Bar bar;
		}
		std::cout << std::endl;
		// no memory leak

		{
			std::unique_ptr<Foo> foo = std::make_unique<Foo>();
			std::unique_ptr<Foo> bar = std::make_unique<Bar>();
		}
		std::cout << std::endl;
		// memory leak!!!

		{
			std::unique_ptr<vFoo> foo = std::make_unique<vFoo>();
			std::unique_ptr<vFoo> bar = std::make_unique<vBar>();
		}
		std::cout << std::endl;
		// no memory leak
	}
}