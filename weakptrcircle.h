#pragma once

// example modified from
// https://www.learncpp.com/cpp-tutorial/15-7-circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/

#include <iostream>
#include <memory>
#include <string>

namespace weakptrcircle {

	class Person {

		std::string m_name;
		std::weak_ptr<Person> m_partner; // note: This is now a std::weak_ptr

	public:

		Person(const std::string& name) : m_name(name) {
			std::cout << m_name << " created" << std::endl;
		}
		~Person() {
			std::cout << m_name << " destroyed" << std::endl;
		}

		friend bool partnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2) {
			if (!p1 || !p2)
				return false;

			p1->m_partner = p2;
			p2->m_partner = p1;

			std::cout << p1->m_name << " is now partnered with " << p2->m_name << std::endl;

			return true;
		}
	};

	void weakptrcircle() {
		auto lucy = std::make_shared<Person>("Lucy"); // create a Person named "Lucy"
		auto ricky = std::make_shared<Person>("Ricky"); // create a Person named "Ricky"

		partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa
	}

}