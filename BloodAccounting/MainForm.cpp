#include <Windows.h>
#include "MainForm.h"

#define DEBUG

using namespace BloodAccounting;
using namespace System;
using namespace System::IO;

Void MainForm::WriteBloodFile() {
	StreamWriter^ writer;
	try {
		writer = gcnew StreamWriter(this->BloodFile);
		for (int i = 0; i < blood.Count; i++) {
			writer->WriteLine(blood[i]->ToString());
		}
	}
	catch (Exception^ ex) {
#ifdef DEBUG 
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("Ошибка записи в файл");
		Application::Exit();
#endif
	}
	finally {
		writer->Close();
	}
}

Void MainForm::WriteDonorsFile() {
	StreamWriter^ writer;
	try {
		writer = gcnew StreamWriter(this->DonorsFile);
		for (int i = 0; i < donors.Count; i++) {
			writer->WriteLine(donors[i]->ToString(0));
		}
	}
	catch (Exception^ ex) {
#ifdef DEBUG 
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("Ошибка записи в файл");
		Application::Exit();
#endif
	}
	finally {
		writer->Close();
	}
}

Void MainForm::WriteLog(String^ log) {
	StreamWriter^ writer;
	try {
		writer = gcnew StreamWriter(LogsFile, true);
		writer->WriteLine(log);
	}
	catch (Exception^ ex) {
#ifdef DEBUG 
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("Ошибка записи логов");
		Application::Exit();
#endif
	} 
	finally {
		writer->Close();
	}
}

Void CheckFile(String^ fileName) {
	if (!File::Exists(fileName)) {
		File::Create(fileName);
	}
}

Void MainForm::CheckBloodFile() {
	CheckFile(BloodFile);
}

Void MainForm::CheckDonorsFile() {
	CheckFile(DonorsFile);
}

Void MainForm::CheckLogsFile() {
	CheckFile(LogsFile);
}

Void MainForm::CheckDirectory() {
	if (!Directory::Exists("./data")) {
		Directory::CreateDirectory("./data");
	}
}

Void MainForm::CheckIncrementFile() {
	CheckFile(IncrementFile);
}

Void MainForm::CheckFiles() {
	CheckDirectory();
	CheckBloodFile();
	CheckDonorsFile();
	CheckLogsFile();
	CheckIncrementFile();
}

Void MainForm::FillDonorsList() {
	StreamReader^ reader;
	try {
		reader = gcnew StreamReader(DonorsFile);
		String^ line;
		while (line = reader->ReadLine()) {
			line = line->Trim();
			if (line != String::Empty) {
				auto buffer = line->Split(';');
				auto name = buffer[0];
				auto age = Convert::ToInt32(buffer[1]);
				auto gender = Convert::ToBoolean(buffer[2]);
				donors.Add(gcnew Donor(name, age, gender));
			}
		}
	}
	catch (Exception^ ex) {
#ifdef DEBUG 
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("Ошибка чтения файла");
		Application::Exit();
#endif
	}
	finally {
		reader->Close();
	}
}

Void MainForm::FillBloodList() {
	StreamReader^ reader;
	try {
		blood.Clear();
		reader = gcnew StreamReader(BloodFile);
		String^ line;
		while (line = reader->ReadLine()) {
			line = line->Trim();
			if (line != String::Empty) {
				auto buffer = line->Split(';');
				auto num = Convert::ToInt32(buffer[0]);
				auto group = Convert::ToInt32(buffer[1]);
				auto factor = Convert::ToBoolean(buffer[2]);
				auto donorName = buffer[3];
				auto donor = gcnew Donor();
				donor->setName(donorName);
				if (!donorName->EndsWith("(не зарегестрирован)")) 
					donor->setName(donorName + "(не зарегестрирован)");
				//поиск донора
				for (int i = 0; i < donors.Count; i++) {
					if (donors[i]->getName() == donorName) {
						donor = donors[i];
						break;
					}
				}

				blood.Add(gcnew Blood(num, group, factor, donor));
			}
		}
	}
	catch (Exception^ ex) {
#ifdef DEBUG 
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("Ошибка чтения файла");
		Application::Exit();
#endif
	}
	finally {
		reader->Close();
	}
}

Void MainForm::FillData() {
	FillDonorsList();
	FillBloodList();
}

Void MainForm::FillFormBloodList() {
	lbBlood->ClearSelected();
	lbBlood->Items->Clear();
	for (int i = 0; i < blood.Count; i++) {
		lbBlood->Items->Add(blood[i]);
	}
}

Void MainForm::FillFormBloodList(String^ donorName) {
	lbBlood->ClearSelected();
	lbBlood->Items->Clear();
	for (int i = 0; i < blood.Count; i++) {
		if (blood[i]->getDonor()->getName() == donorName)
			lbBlood->Items->Add(blood[i]);
	}
}

Void MainForm::FillFormBloodList(bool O, bool A, bool B, bool AB) {
	lbBlood->ClearSelected();
	lbBlood->Items->Clear();

	for (int i = 0; i < blood.Count; i++) {
		if (O && (int)blood[i]->getGroup() == 1) {
			lbBlood->Items->Add(blood[i]);
			continue;
		}
		if (A && (int)blood[i]->getGroup() == 2) {
			lbBlood->Items->Add(blood[i]);
			continue;
		}
		if (B && (int)blood[i]->getGroup() == 3) {
			lbBlood->Items->Add(blood[i]);
			continue;
		}
		if (AB && (int)blood[i]->getGroup() == 4) {
			lbBlood->Items->Add(blood[i]);
			continue;
		}
	}

}

Void MainForm::FillFormDonorsList() {
	lbDonors->ClearSelected();
	lbDonors->Items->Clear();
	for (int i = 0; i < donors.Count; i++) {
		lbDonors->Items->Add(donors[i]);
	}
}

Void MainForm::FillFormDonorsComboBox() {
	this->cbDonor->Items->Clear();
	this->cbDonorS->Items->Clear();
	for (int i = 0; i < donors.Count; i++) {
		this->cbDonor->Items->Add(donors[i]->getName());
		this->cbDonorS->Items->Add(donors[i]->getName());
	}
}

Void MainForm::UpdateBloodList(List<Blood^> bloodList, Blood^ newBlood) {}

Void MainForm::UpdateDonorsList(List<Donor^> donorsList, Donor^ newDonor) {}

Void MainForm::SetIncrement() {
	StreamReader^ reader;
	try {
		reader = gcnew StreamReader(IncrementFile);
		String^ line = reader->ReadLine();
		increment = (int)Convert::ToInt32(line);
	}
	catch (Exception^ ex) {
#ifdef DEBUG 
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("Ошибка чтения файла");
		Application::Exit();
#endif
	}
	finally {
		reader->Close();
	}
}

Void MainForm::UpdateIncrement() {
	increment++;
	StreamWriter^ writer;
	try {
		writer = gcnew StreamWriter(this->IncrementFile);
		writer->WriteLine(increment);
	}
	catch (Exception^ ex) {
#ifdef DEBUG 
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("Ошибка записи в файл");
		Application::Exit();
#endif
	}
	finally {
		writer->Close();
	}
}

Void MainForm::CreateReport1() {
	int Op(0), Ap(0), Bp(0), ABp(0);
	int On(0), An(0), Bn(0), ABn(0);
	for (int i = 0; i < blood.Count; i++) {
		switch ((int)blood[i]->getGroup()) {
		case 1:
			(bool)blood[i]->getRhFactor() ? Op++ : On++;
			break;
		case 2:
			(bool)blood[i]->getRhFactor() ? Ap++ : An++;
			break;
		case 3:
			(bool)blood[i]->getRhFactor() ? Bp++ : Bn++;
			break;
		case 4:
			(bool)blood[i]->getRhFactor() ? ABp++ : ABn++;
			break;
		}
	}

	try {
		this->chart1->Series->Clear();

		this->chart1->Series->Add("положительный \nrh фактор");
		this->chart1->Series[0]->Points->Clear();
		this->chart1->Series[0]->Points->AddXY("0", Op);
		this->chart1->Series[0]->Points->AddXY("A", Ap);
		this->chart1->Series[0]->Points->AddXY("B", Bp);
		this->chart1->Series[0]->Points->AddXY("AB", ABp);

		this->chart1->Series->Add("отрицательный \nrh фактор");
		this->chart1->Series[1]->Points->Clear();
		this->chart1->Series[1]->Points->AddXY("0", On);
		this->chart1->Series[1]->Points->AddXY("A", An);
		this->chart1->Series[1]->Points->AddXY("B", Bn);
		this->chart1->Series[1]->Points->AddXY("AB", ABn);

	}
	catch (Exception^ exc) {
#ifdef DEBUG 
		MessageBox::Show(exc->Message);
		throw;
#else
		MessageBox::Show("Ошибка при построении графика");
		Application::Exit();
#endif
	}
}

Void MainForm::CreateReport2() {
	int Om(0), Am(0), Bm(0), ABm(0);
	int Ow(0), Aw(0), Bw(0), ABw(0);
	for (int i = 0; i < blood.Count; i++) {
		switch ((int)blood[i]->getGroup()) {
		case 1:
			(bool)blood[i]->getDonor()->getGender() ? Om++ : Ow++;
			break;
		case 2:
			(bool)blood[i]->getDonor()->getGender() ? Am++ : Aw++;
			break;
		case 3:
			(bool)blood[i]->getDonor()->getGender() ? Bm++ : Bw++;
			break;
		case 4:
			(bool)blood[i]->getDonor()->getGender() ? ABm++ : ABw++;
			break;
		}
	}

	try{
		this->chart1->Series->Clear();

		this->chart1->Series->Add("муж");
		this->chart1->Series[0]->Points->Clear();
		this->chart1->Series[0]->Points->AddXY("0", Om);
		this->chart1->Series[0]->Points->AddXY("A", Am);
		this->chart1->Series[0]->Points->AddXY("B", Bm);
		this->chart1->Series[0]->Points->AddXY("AB", ABm);

		this->chart1->Series->Add("жен");
		this->chart1->Series[1]->Points->Clear();
		this->chart1->Series[1]->Points->AddXY("0", Ow);
		this->chart1->Series[1]->Points->AddXY("A", Aw);
		this->chart1->Series[1]->Points->AddXY("B", Bw);
		this->chart1->Series[1]->Points->AddXY("AB", ABw);

	}
	catch (Exception^ exc) {
#ifdef DEBUG 
		MessageBox::Show(exc->Message);
		throw;
#else
		MessageBox::Show("Ошибка при построении графика");
		Application::Exit();
#endif
	}
}

//хранит возраст доноров и 
//массив с группами крови этого возраста
//поля:
//Age   Int32
//Group List<Int32>
ref struct AgeStatisic {
	Int32^ Age;
	List<Int32> Group;
};

Void MainForm::CreateReport3() {
	List<AgeStatisic^> groupByAge;

	AgeStatisic^ st = gcnew AgeStatisic;
	st->Age = blood[0]->getDonor()->getAge();
	st->Group.Add(0);
	st->Group.Add(0);
	st->Group.Add(0);
	st->Group.Add(0);
	groupByAge.Add(st);

	for (int i = 1; i < blood.Count; i++) {

		for (int j = 0; j < groupByAge.Count; j++) {
			if ((int)groupByAge[j]->Age == (int)blood[i]->getDonor()->getAge()) {
				groupByAge[j]->Group[(int)blood[i]->getGroup() - 1]++;
				goto next;
			}
		}

		AgeStatisic^ nwSt = gcnew AgeStatisic;
		nwSt->Age = blood[i]->getDonor()->getAge();
		nwSt->Group.Add(0);
		nwSt->Group.Add(0);
		nwSt->Group.Add(0);
		nwSt->Group.Add(0);
		nwSt->Group[(int)blood[i]->getGroup() - 1]++;
		groupByAge.Add(nwSt);

	next:;
	}

	try {
		this->chart1->Series->Clear();
		
		this->chart1->Series->Add("O");
		this->chart1->Series->Add("A");
		this->chart1->Series->Add("B");
		this->chart1->Series->Add("AB");

		//это вариант, при котором для кождого возраста считается количество кождой группы крови
		for (int i = 0; i < groupByAge.Count; i++) {
			this->chart1->Series[0]->Points->AddXY(groupByAge[i]->Age, groupByAge[i]->Group[0]);
			this->chart1->Series[1]->Points->AddXY(groupByAge[i]->Age, groupByAge[i]->Group[1]);
			this->chart1->Series[2]->Points->AddXY(groupByAge[i]->Age, groupByAge[i]->Group[2]);
			this->chart1->Series[3]->Points->AddXY(groupByAge[i]->Age, groupByAge[i]->Group[3]);
		}
		
		//это вариант, при котором для каждой группы считается количество доноров каждого возраста
		/*for (int i = 0; i < groupByAge.Count; i++) {
			this->chart1->Series->Add(groupByAge[i]->Age + " лет");
			this->chart1->Series[i]->Points->AddXY("O", groupByAge[i]->Group[0]);
			this->chart1->Series[i]->Points->AddXY("A", groupByAge[i]->Group[1]);
			this->chart1->Series[i]->Points->AddXY("B", groupByAge[i]->Group[2]);
			this->chart1->Series[i]->Points->AddXY("AB", groupByAge[i]->Group[3]);
		}*/
	}
	catch (Exception^ exc) {
#ifdef DEBUG 
		MessageBox::Show(exc->Message);
		throw;
#else
		MessageBox::Show("Ошибка при построении графика");
		Application::Exit();
#endif

	}
}

//обновляет информацию о донорах в списке крови(Krocze - костыль с польского)
Void MainForm::Krocze() {
	for (int i = 0; i < blood.Count; i++) {
		String^ name = blood[i]->getDonor()->getName();
		for (int j = 0; j < donors.Count; j++) {
			if (donors[j]->getName() == name) {
				blood[i]->setDonor(donors[j]);
				break;
			}
		}
	}
}