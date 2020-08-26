#pragma once

#include <iostream>

namespace consts {

	struct Foo {

		Foo() : var1(0), var2(5) {}

		void nonConstMethod() {
			var1++;
		}

		void print() const {
			std::cout << "var1: " << var1 << "var2: " << var2 << std::endl;
		}

		int constMethod() const {
			return var1;
		}

		void constMethod2() const {
			// Compiler error
			// var1++; 
			var2++;
		}

		int var1;
		mutable int var2;
	};

	void consts() {

		Foo foo1;
		foo1.nonConstMethod();
		foo1.print();

		const Foo foo2;
		// compiler error
		// foo2.nonConstMethod();
		foo2.constMethod2();
		foo2.print();

		const Foo& fooRef = foo1;
		// compiler error
		// fooRef = foo2
		fooRef.print();
	}
}