#pragma once

#include <iostream>

namespace enums {

	enum DrinkSize {
		SMALL,
		MEDIUM,
		LARGE
	};

	enum Steaks {
		RARE,
		MEDIUM_RARE,
		// compiler error; clashes with above
		// MEDIUM,
		MEDIUM_WELL,
		WELL_DONE
	};

	void enums() {
		Steaks steak = RARE;
		DrinkSize size = SMALL;

		if (steak == size) {
			std::cout << "these are equal" << std::endl;
		}
	}
};

namespace enumclasses {

	enum class DrinkSize {
		SMALL,
		MEDIUM,
		LARGE
	};

	enum class Steaks {
		RARE,
		MEDIUM_RARE,
		MEDIUM,
		MEDIUM_WELL,
		WELL_DONE
	};
	
	enum class Num {
		ONE = 1,
		TWO,
		THREE
	};

	void enumclasses() {
		Steaks steak = Steaks::RARE;
		DrinkSize size = DrinkSize::SMALL;

		// compiler error
		// if (steak == size)

		Num num = Num::ONE;
		int x = (int)num + 5;

		std::cout << x << std::endl;
	}
}