#pragma once

#include <iostream>
#include <memory>
#include <vector>

namespace inheritance {

	struct Animal {
		void speak() const {
			std::cout << "i am an animal" << std::endl;
		}
	};

	struct Pig : public Animal {
		void speak() const {
			std::cout << "oink" << std::endl;
		}
	};

	struct Cow : public Animal {
		void speak() const {
			std::cout << "moo" << std::endl;
		}
	};

	struct vAnimal {
		virtual void speak() const = 0;
	};

	struct vPig : public vAnimal {
		void speak() const {
			std::cout << "oink" << std::endl;
		}
	};

	struct vCow : public vAnimal {
		void speak() const {
			std::cout << "moo" << std::endl;
		}
	};

	void inheritance() {

		Pig pig;
		pig.speak();

		Cow cow;
		cow.speak();

		std::vector<std::unique_ptr<Animal>> barn;
		barn.push_back(std::make_unique<Pig>());
		barn.push_back(std::make_unique<Cow>());

		for (const auto& a : barn) {
			a->speak();
		}

		std::vector<std::unique_ptr<vAnimal>> vBarn;
		vBarn.push_back(std::make_unique<vPig>());
		vBarn.push_back(std::make_unique<vCow>());

		for (const auto& a : vBarn) {
			a->speak();
		}
	}
}