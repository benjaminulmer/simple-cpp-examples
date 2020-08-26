#include "consts.h"
#include "containers.h"
#include "enums.h"
#include "destructors.h"
#include "inheritance.h"
#include "initialization.h"
#include "operatoroverload.h"
#include "sharedptr.h"
#include "sharedptrcircle.h"
#include "ptrcopyassign.h"
#include "uniqueptr.h"
#include "weakptrcircle.h"

struct Foo {
	void someMethod() {}
};

int main() {

	{
		int x = 2;
		int* num1 = new int(5);
		int* num2 = &x;
		int y = *num1;

		Foo foo;
		Foo* foo1 = new Foo();
		Foo* foo2 = &foo;
		Foo foofoo = *foo1;

		foo.someMethod();
		foo1->someMethod();
	}
	{
		int x = 2;
		int& num = x;

		Foo foo;
		Foo& foo1 = foo;

		foo.someMethod();
	}

	//containers::containers();
	// consts
	//uniqueptr::uniqueptr();
	// ptr copy assign
	sharedptr::sharedptr();
	//sharedptrcircle::sharedptrcircle();
	//std::cout << std::endl;
	//weakptrcircle::weakptrcircle();
	//initialization::initialization();
	//enums::enums();
	//inheritance::inheritance();
	//destructors::destructors();
	//operatoroverload::operatoroverload();
	
	return 0;
}