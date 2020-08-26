#pragma once

#include <iostream>

namespace operatoroverload {

	class MyVec {
	
	public:
		MyVec() : x(0.0), y(0.0), z(0.0) {}
		MyVec(float x, float y, float z) : x(x), y(y), z(z) {}

		MyVec& operator+=(const MyVec& rhs) {
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}

		friend MyVec operator+(MyVec lhs, const MyVec& rhs) {
			lhs += rhs;
			return lhs;
		}

		friend std::ostream& operator<<(std::ostream& os, const MyVec& rhs) {
			os << "[" << rhs.x << "," << rhs.y << "," << rhs.z << "]";
			return os;
		}

	private:
		float x;
		float y;
		float z;
	};

	void operatoroverload() {
		MyVec vec1(1, 1, 1);
		
		MyVec vec2 = vec1 + MyVec(1, 1, 1);
		std::cout << vec2 << std::endl;

		vec2 += vec2;
		std::cout << vec2 << std::endl;

		MyVec vec3 = vec2 + vec1 + vec1;
		std::cout << vec3 << std::endl;
	}
}