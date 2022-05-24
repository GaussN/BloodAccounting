#include <Windows.h>
#include "MainForm.h"

//#define DEBUG

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
		MessageBox::Show("������ ������ � ����");
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
		MessageBox::Show("������ ������ � ����");
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
		MessageBox::Show("������ ������ �����");
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("������ ������ �����");
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
		MessageBox::Show("������ ������ �����");
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
				if (!donorName->EndsWith("(�� ���������������)")) 
					donor->setName(donorName + "(�� ���������������)");
				//����� ������
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
		MessageBox::Show("������ ������ �����");
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
		MessageBox::Show("������ ������ �����");
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
		MessageBox::Show("������ ������ � ����");
		Application::Exit();
#endif
	}
	finally {
		writer->Close();
	}
}

//������ ������� ������� � 
//������ � �������� ����� ����� ��������
//����:
//Age   Int32
//Group List<Int32>
ref struct AgeStatisic {
	Int32^ Age;
	List<Int32> Group;
};

Void CreateReport1(System::Windows::Forms::DataVisualization::Charting::Chart^ chart, List<Blood^>% blood) {
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
		chart->Series->Clear();

		chart->Series->Add("������������� \nrh ������");
		chart->Series[0]->Points->Clear();
		chart->Series[0]->Points->AddXY("0", Op);
		chart->Series[0]->Points->AddXY("A", Ap);
		chart->Series[0]->Points->AddXY("B", Bp);
		chart->Series[0]->Points->AddXY("AB", ABp);

		chart->Series->Add("������������� \nrh ������");
		chart->Series[1]->Points->Clear();
		chart->Series[1]->Points->AddXY("0", On);
		chart->Series[1]->Points->AddXY("A", An);
		chart->Series[1]->Points->AddXY("B", Bn);
		chart->Series[1]->Points->AddXY("AB", ABn);

	}
	catch (Exception^ exc) {
#ifdef DEBUG 
		MessageBox::Show(exc->Message);
		throw;
#else
		MessageBox::Show("������ ��� ���������� �������");
		Application::Exit();
#endif
	}
}

Void CreateReport2(System::Windows::Forms::DataVisualization::Charting::Chart^ chart, List<Blood^>% blood, List<Donor^>% donors) {
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

	try {
		chart->Series->Clear();

		chart->Series->Add("���");
		chart->Series[0]->Points->Clear();
		chart->Series[0]->Points->AddXY("0", Om);
		chart->Series[0]->Points->AddXY("A", Am);
		chart->Series[0]->Points->AddXY("B", Bm);
		chart->Series[0]->Points->AddXY("AB", ABm);

		chart->Series->Add("���");
		chart->Series[1]->Points->Clear();
		chart->Series[1]->Points->AddXY("0", Ow);
		chart->Series[1]->Points->AddXY("A", Aw);
		chart->Series[1]->Points->AddXY("B", Bw);
		chart->Series[1]->Points->AddXY("AB", ABw);

	}
	catch (Exception^ exc) {
#ifdef DEBUG 
		MessageBox::Show(exc->Message);
		throw;
#else
		MessageBox::Show("������ ��� ���������� �������");
		Application::Exit();
#endif
	}
}

Void CreateReport3(System::Windows::Forms::DataVisualization::Charting::Chart^ chart, List<Blood^>% blood, List<Donor^>% donors) {
	if (blood.Count == 0)
		return;

	List<AgeStatisic^> groupByAge;

	for (int i = 0; i < blood.Count; i++) {

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

		chart->Series->Clear();
		for (int i = 0; i < groupByAge.Count; i++) {
			chart->Series->Add(groupByAge[i]->Age + " ���");
			chart->Series[i]->Points->AddXY("O", groupByAge[i]->Group[0]);
			chart->Series[i]->Points->AddXY("A", groupByAge[i]->Group[1]);
			chart->Series[i]->Points->AddXY("B", groupByAge[i]->Group[2]);
			chart->Series[i]->Points->AddXY("AB", groupByAge[i]->Group[3]);
		}
	}
	catch (Exception^ exc) {
#ifdef DEBUG 
		MessageBox::Show(exc->Message);
		throw;
#else
		MessageBox::Show("������ ��� ���������� �������");
		Application::Exit();
#endif

	}
}


Void MainForm::CreateReport11() {
	CreateReport1(this->chart1, blood);
}

Void MainForm::CreateReport21() {
	CreateReport2(this->chart1, this->blood, this->donors);
}

Void MainForm::CreateReport31() {
	CreateReport3(this->chart1, this->blood, this->donors);
}

Void MainForm::CreateReport12() {
	List<Blood^> usedBlood;
	//log : num;group;factor;donorName;recipientName;age;gender;
	StreamReader^ reader;
	try {
		reader = gcnew StreamReader(LogsFile);
		String^ line;
		while (line = reader->ReadLine()) {
			line = line->Trim();
			if (line != String::Empty) {
				auto buffer = line->Split(';');
				Int32^ num = Convert::ToInt32(buffer[0]);
				Int32^ group = Convert::ToInt32(buffer[1]);
				Boolean^ factor = Convert::ToBoolean(buffer[2]);
				usedBlood.Add(gcnew Blood(num, group, factor, gcnew Donor()));
			}
		}
	}
	catch (Exception^ ex) {
#ifdef DEBUG 
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("������ ������ �����");
		Application::Exit();
#endif
	}
	finally {
		reader->Close();
	}

	CreateReport1(this->chart2, usedBlood);
}

Void MainForm::CreateReport22() {
	List<Donor^> recipients;//� ������� � ����������� ���������� ����
	List<Blood^> usedBlood;

	//��������� �����������
	StreamReader^ reader;
	try {
		reader = gcnew StreamReader(LogsFile);
		String^ line;
		while (line = reader->ReadLine()) {
			line = line->Trim();
			if (line != String::Empty) {
				auto buffer = line->Split(';');
				auto name = buffer[4];
				auto age = Convert::ToInt32(buffer[5]);
				auto gender = Convert::ToBoolean(buffer[6]);
				recipients.Add(gcnew Donor(name, age, gender));
			}
		}
	}
	catch (Exception^ ex) {
#ifdef DEBUG 
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("������ ������ �����");
		Application::Exit();
#endif
	}
	finally {
		reader->Close();
	}

	//��������� ������������� �����
	try {
		blood.Clear();
		reader = gcnew StreamReader(LogsFile);
		String^ line;
		while (line = reader->ReadLine()) {
			line = line->Trim();
			if (line != String::Empty) {
				auto buffer = line->Split(';');
				auto num = Convert::ToInt32(buffer[0]);
				auto group = Convert::ToInt32(buffer[1]);
				auto factor = Convert::ToBoolean(buffer[2]);
				auto recipientName = buffer[4];
				auto recipient = gcnew Donor();
				recipient->setName(recipientName);
				//����� ����������
				for (int i = 0; i < recipients.Count; i++) {
					if (recipients[i]->getName() == recipientName) {
						recipient = recipients[i];
						break;
					}
				}

				usedBlood.Add(gcnew Blood(num, group, factor, recipient));
			}
		}
	}
	catch (Exception^ ex) {
#ifdef DEBUG 
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("������ ������ �����");
		Application::Exit();
#endif
	}
	finally {
		reader->Close();
	}

	CreateReport2(this->chart2, usedBlood, recipients);
}

Void MainForm::CreateReport32() {
	List<Donor^> recipients;//� ������� � ����������� ���������� ����
	List<Blood^> usedBlood;

	//��������� �����������
	StreamReader^ reader;
	try {
		reader = gcnew StreamReader(LogsFile);
		String^ line;
		while (line = reader->ReadLine()) {
			line = line->Trim();
			if (line != String::Empty) {
				auto buffer = line->Split(';');
				auto name = buffer[4];
				auto age = Convert::ToInt32(buffer[5]);
				auto gender = Convert::ToBoolean(buffer[6]);
				recipients.Add(gcnew Donor(name, age, gender));
			}
		}
	}
	catch (Exception^ ex) {
#ifdef DEBUG 
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("������ ������ �����");
		Application::Exit();
#endif
	}
	finally {
		reader->Close();
	}

	//��������� ������������� �����
	try {
		blood.Clear();
		reader = gcnew StreamReader(LogsFile);
		String^ line;
		while (line = reader->ReadLine()) {
			line = line->Trim();
			if (line != String::Empty) {
				auto buffer = line->Split(';');
				auto num = Convert::ToInt32(buffer[0]);
				auto group = Convert::ToInt32(buffer[1]);
				auto factor = Convert::ToBoolean(buffer[2]);
				auto recipientName = buffer[4];
				auto recipient = gcnew Donor();
				recipient->setName(recipientName);
				//����� ����������
				for (int i = 0; i < recipients.Count; i++) {
					if (recipients[i]->getName() == recipientName) {
						recipient = recipients[i];
						break;
					}
				}

				usedBlood.Add(gcnew Blood(num, group, factor, recipient));
			}
		}
	}
	catch (Exception^ ex) {
#ifdef DEBUG 
		MessageBox::Show(ex->Message);
		throw;
#else
		MessageBox::Show("������ ������ �����");
		Application::Exit();
#endif
	}
	finally {
		reader->Close();
	}

	CreateReport3(this->chart2, usedBlood, recipients);
}

//��������� ���������� � ������� � ������ �����(Krocze - ������� � ���������)
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

Void MainForm::WordReport1() {
	SaveFileDialog^ fileDialog = gcnew SaveFileDialog();
	fileDialog->DefaultExt = "docx";
	fileDialog->CreatePrompt = true;
	fileDialog->OverwritePrompt = true;
	fileDialog->Title = "�������� ���� ������";

	using namespace System::Reflection;

	if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		try {
			String^ fileName = fileDialog->FileName;

			auto wordApp = gcnew Microsoft::Office::Interop::Word::Application();
			wordApp->Visible = false;
			auto t = Type::Missing;
			auto Document = wordApp->Documents->Add(t, t, t, t);
			//
			this->chart1->SaveImage(fileName + ".png", System::Drawing::Imaging::ImageFormat::Png);
			Microsoft::Office::Interop::Word::Range^ docRange = Document->Range(t, t);
			Microsoft::Office::Interop::Word::InlineShape^ autoScaledInlineShape = docRange->InlineShapes->AddPicture(String::Concat(fileName, ".png"), t, t, t);
			float scaledWidth = autoScaledInlineShape->Width;
			float scaledHeight = autoScaledInlineShape->Height;
			autoScaledInlineShape->Delete();
			Microsoft::Office::Interop::Word::Shape^ newShape = Document->Shapes->AddShape(1, 0, blood.Count + 3, scaledWidth, scaledHeight, t);
			newShape->Fill->UserPicture(fileName + ".png");
			Microsoft::Office::Interop::Word::InlineShape^ finalInlineShape = newShape->ConvertToInlineShape();
			finalInlineShape->Range->Cut();
			docRange->Paste();

			//
			wordApp->Selection->TypeText(DateTime::Now.ToString("Report\n"));
			wordApp->Selection->TypeText(DateTime::Now.ToString("dd.MM.yyyy"));


			System::Object^ t1 = Microsoft::Office::Interop::Word::WdDefaultTableBehavior::wdWord9TableBehavior;
			System::Object^ t2 = Microsoft::Office::Interop::Word::WdAutoFitBehavior::wdAutoFitContent;
			wordApp->ActiveDocument->Tables->Add(wordApp->Selection->Range, blood.Count + 1, 6, t1, t2);

			wordApp->ActiveDocument->Tables[1]->Cell(1, 1)->Range->InsertAfter("�����");
			wordApp->ActiveDocument->Tables[1]->Cell(1, 2)->Range->InsertAfter("������ �����");
			wordApp->ActiveDocument->Tables[1]->Cell(1, 3)->Range->InsertAfter("����� ������");
			wordApp->ActiveDocument->Tables[1]->Cell(1, 4)->Range->InsertAfter("��� ������");
			wordApp->ActiveDocument->Tables[1]->Cell(1, 5)->Range->InsertAfter("������� ������");
			wordApp->ActiveDocument->Tables[1]->Cell(1, 6)->Range->InsertAfter("��� ������");

			for (int i = 2; i <= blood.Count + 1; i++) {
				wordApp->ActiveDocument->Tables[1]->Cell(i, 1)->Range->InsertAfter(blood[i - 2]->getNum()->ToString());
				wordApp->ActiveDocument->Tables[1]->Cell(i, 2)->Range->InsertAfter(blood[i - 2]->getGroup()->ToString());
				wordApp->ActiveDocument->Tables[1]->Cell(i, 3)->Range->InsertAfter(blood[i - 2]->getRhFactor()?"+":"-");
				wordApp->ActiveDocument->Tables[1]->Cell(i, 4)->Range->InsertAfter(blood[i - 2]->getDonor()->getName()->ToString());
				wordApp->ActiveDocument->Tables[1]->Cell(i, 5)->Range->InsertAfter(blood[i - 2]->getDonor()->getAge()->ToString());
				wordApp->ActiveDocument->Tables[1]->Cell(i, 6)->Range->InsertAfter(blood[i - 2]->getDonor()->getGender()?"���":"���");
			}
			wordApp->Selection->TypeText("\n\n");
			wordApp->ActiveDocument->SaveAs(fileName, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t);
			wordApp->Quit(t, t, t);

			File::Delete(fileName + ".png");
		}
		catch (Exception^ exception) {
			MessageBox::Show("������ ��� ������ ����� Word");
			MessageBox::Show(exception->Message);
		}
	}
}

Void MainForm::WordReport2() {
	
	SaveFileDialog^ fileDialog = gcnew SaveFileDialog();
	fileDialog->DefaultExt = "docx";
	fileDialog->CreatePrompt = true;
	fileDialog->OverwritePrompt = true;
	fileDialog->Title = "�������� ���� ������";

	using namespace System::Reflection;

	if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		try {
			List<String^> logs;
			StreamReader^ reader;
			try {
				String^ line;
				reader = gcnew StreamReader(LogsFile);
				while (line = reader->ReadLine()) {
					line = line->Trim();
					if (line != String::Empty) {
						logs.Add(line);
					}
				}
			}
			catch (Exception^ ex) {
#ifdef DEBUG 
				MessageBox::Show(ex->Message);
				throw;
#else
				MessageBox::Show("������ ������ ����� �����");
				Application::Exit();
#endif
			}
			finally {
				reader->Close();
			}


			String^ fileName = fileDialog->FileName;

			auto wordApp = gcnew Microsoft::Office::Interop::Word::Application();
			wordApp->Visible = false;
			auto t = Type::Missing;
			auto Document = wordApp->Documents->Add(t, t, t, t);
			//
			this->chart2->SaveImage(fileName + ".png", System::Drawing::Imaging::ImageFormat::Png);
			Microsoft::Office::Interop::Word::Range^ docRange = Document->Range(t, t);
			Microsoft::Office::Interop::Word::InlineShape^ autoScaledInlineShape = docRange->InlineShapes->AddPicture(String::Concat(fileName, ".png"), t, t, t);
			float scaledWidth = autoScaledInlineShape->Width;
			float scaledHeight = autoScaledInlineShape->Height;
			autoScaledInlineShape->Delete();
			Microsoft::Office::Interop::Word::Shape^ newShape = Document->Shapes->AddShape(1, 0, logs.Count + 3, scaledWidth, scaledHeight, t);
			newShape->Fill->UserPicture(fileName + ".png");
			Microsoft::Office::Interop::Word::InlineShape^ finalInlineShape = newShape->ConvertToInlineShape();
			finalInlineShape->Range->Cut();
			docRange->Paste();

			//
			wordApp->Selection->TypeText(DateTime::Now.ToString("Report\n"));
			wordApp->Selection->TypeText(DateTime::Now.ToString("dd.MM.yyyy"));


			System::Object^ t1 = Microsoft::Office::Interop::Word::WdDefaultTableBehavior::wdWord9TableBehavior;
			System::Object^ t2 = Microsoft::Office::Interop::Word::WdAutoFitBehavior::wdAutoFitContent;
			wordApp->ActiveDocument->Tables->Add(wordApp->Selection->Range, logs.Count + 1, 7, t1, t2);

			wordApp->ActiveDocument->Tables[1]->Cell(1, 1)->Range->InsertAfter("�����");
			wordApp->ActiveDocument->Tables[1]->Cell(1, 2)->Range->InsertAfter("������ �����");
			wordApp->ActiveDocument->Tables[1]->Cell(1, 3)->Range->InsertAfter("����� ������");
			wordApp->ActiveDocument->Tables[1]->Cell(1, 4)->Range->InsertAfter("��� ������");
			wordApp->ActiveDocument->Tables[1]->Cell(1, 5)->Range->InsertAfter("��� ����������");
			wordApp->ActiveDocument->Tables[1]->Cell(1, 6)->Range->InsertAfter("������� ����������");
			wordApp->ActiveDocument->Tables[1]->Cell(1, 7)->Range->InsertAfter("��� ����������");

			for (int i = 2; i <= logs.Count + 1; i++) {
				wordApp->ActiveDocument->Tables[1]->Cell(i, 1)->Range->InsertAfter(logs[i - 2]->Split(';')[0]);
				wordApp->ActiveDocument->Tables[1]->Cell(i, 2)->Range->InsertAfter(logs[i - 2]->Split(';')[1]);
				wordApp->ActiveDocument->Tables[1]->Cell(i, 3)->Range->InsertAfter(logs[i - 2]->Split(';')[2]?"+":"-");
				wordApp->ActiveDocument->Tables[1]->Cell(i, 4)->Range->InsertAfter(logs[i - 2]->Split(';')[3]);
				wordApp->ActiveDocument->Tables[1]->Cell(i, 5)->Range->InsertAfter(logs[i - 2]->Split(';')[4]);
				wordApp->ActiveDocument->Tables[1]->Cell(i, 6)->Range->InsertAfter(logs[i - 2]->Split(';')[5]);
				wordApp->ActiveDocument->Tables[1]->Cell(i, 7)->Range->InsertAfter(logs[i - 2]->Split(';')[6]?"���":"���");
			}
			wordApp->Selection->TypeText("\n\n");
			wordApp->ActiveDocument->SaveAs(fileName, t, t, t, t, t, t, t, t, t, t, t, t, t, t, t);
			wordApp->Quit(t, t, t);

			File::Delete(fileName + ".png");
		}
		catch (Exception^ exception) {
			MessageBox::Show("������ ��� ������ ����� Word");
			MessageBox::Show(exception->Message);
		}
	}
}