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
			writer->WriteLine(donors[i]->ToString());
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

Void MainForm::CheckFiles() {
	CheckDirectory();
	CheckBloodFile();
	CheckDonorsFile();
	CheckLogsFile();
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

Void MainForm::FillFormDonorsList() {

}

Void MainForm::FillFormDonorsComboBox() {
	this->cbDonor->Items->Clear();
	for (int i = 0; i < donors.Count; i++)
		this->cbDonor->Items->Add(donors[i]->getName());
}

Void MainForm::UpdateBloodList() {}

Void MainForm::UpdateDonorsList() {}