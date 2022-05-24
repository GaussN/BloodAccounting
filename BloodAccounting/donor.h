#pragma once

#define MAN true
#define WOMEN false

namespace BloodAccounting {
	using namespace System;

	ref class Donor {
	private:
		String^ _name;
		Int32^ _age;
		Boolean^ _gender;
	public:
#pragma region constructors
		Donor(String^ Name, Int32^ Age, Boolean^ Gender) {
			this->setName(Name);
			this->setAge(Age);
			this->setGender(Gender);
		}
		Donor(Donor^ other) : Donor(other->getName(), other->getAge(), other->getGender()) {}
		Donor() : Donor(String::Empty, 18, true) {}
#pragma endregion
#pragma region get/set
		//get
		String^ getName() {
			return this->_name;
		}
		Int32^ getAge() {
			return this->_age;
		}
		Boolean^ getGender() {
			return this->_gender;
		}

		//set
		void setName(String^ value) {
			this->_name = value;
		}
		void setAge(Int32^ value) {
			this->_age = value;
		}
		void setGender(Boolean^ value) {
			this->_gender = value;
		}

#pragma endregion 

		String^ ToString(int notused) {
			return getName() + ";" + getAge() + ";" + getGender();
		}
		String^ ToString() override {
			return getName();
		}
	};

};