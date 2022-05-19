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
			if (static_cast<int>(value) < 17)
				throw gcnew Exception("Age must be over or equal to 18");
			this->_age = value;
		}
		void setGender(Boolean^ value) {
			this->_gender = value;
		}

#pragma endregion 

		String^ ToString() override {
			return getName() + ";" + getAge() + ";" + getGender();
		}
		/*Boolean^ Equals(Donor^ other) override {
			return (other->getName() == this->getName() && other->getAge() == this->getAge() && other->getGender() == this->getGender());
		}*/
	};

};