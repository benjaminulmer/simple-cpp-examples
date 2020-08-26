#pragma once

#include <iostream>
#include <memory>
#include <vector>

namespace sharedptr {

	struct Child {
		~Child() {
			std::cout << "child destroyed" << std::endl;
		}
	};

	struct Parent {
		~Parent() {
			std::cout << "parent destroyed" << std::endl;
		}
		std::vector<std::shared_ptr<Child>> children;

		friend std::shared_ptr<Child> procreate(Parent& father, Parent& mother) {
			std::shared_ptr<Child> child = std::make_shared<Child>();
			father.children.push_back(child);
			mother.children.push_back(child);
			return child;
		}
	};

	void sharedptr() {
		{
			Parent mom;
			Parent dad;

			std::shared_ptr<Child> child = procreate(dad, mom);
			std::cout << child.use_count() << std::endl;
		}
	}
}