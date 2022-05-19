#pragma once
#include "donor.h"


namespace BloodAccounting {
	using namespace System;

	ref class Blood {
	private:
		Int32^ _num;
		Int32^ _group;
		Boolean^ _rh;
		Donor^ _donor;

	public:
#pragma region constructors
		Blood(Int32^ Num, Int32^ Group, Boolean^ RhFactor, Donor^ Donor) {
			this->_num = Num;
			this->setGroup(Group);
			this->setRhFactor(RhFactor);
			this->setDonor(Donor);
		}
#pragma endregion
#pragma region get/set
		//set
		Void setGroup(Int32^ value) {
			if (!((int)value >= 0 && (int)value <= 4))
				throw gcnew Exception("Blood type must be in the range from 0 to 4");
			this->_group = value;
		}
		Void setRhFactor(Boolean^ value) {
			this->_rh = value;
		}
		Void setDonor(Donor^ value) {
			this->_donor = gcnew Donor();
			this->_donor->setName(value->getName());
			this->_donor->setAge(value->getAge());
			this->_donor->setGender(value->getGender());
		}
		//get
		Int32^ getNum() {
			return this->_num;
		}
		Int32^ getGroup() {
			return this->_group;
		}
		Boolean^ getRhFactor() {
			return this->_rh;
		}
		Donor^ getDonor() {
			return this->_donor;
		}
#pragma endregion
		String^ ToString() override {
			return getNum() + ";" + getGroup() + ";" + getRhFactor() + ";" + getDonor()->getName();
		}
	};

};