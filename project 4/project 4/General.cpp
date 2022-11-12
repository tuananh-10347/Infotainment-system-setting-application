#include "General.h"

General::General()
{
	timeZone = "(GMT+07:00) /  Bangkok, Hanoi, Jakarta";
	language = "Vietnamese";
}
General::General(string timeZone, string language)
{
	this->timeZone = timeZone;
	this->language = language;
}
General::~General()
{
}

void General::setTimeZone(string timeZone)
{
	this->timeZone = timeZone;
}
void General::setLanguage(string language)
{
	this->language = language;
}

string General::getTimeZone()
{
	return this->timeZone;
}
string General::getLanguage()
{
	return this->language;
}

void General::getFileLanguage(string f, int number, string& data) //Đọc dữ liệu từ TimeZone.txt
{
	checkFileLanguage(f);
	vector<string>vec; //vec lưu trừ language

	ifstream fileText(f);
	if (fileText.is_open())
	{
		while (!fileText.eof())
		{
			char temp[255];
			fileText.getline(temp, 255);
			vec.push_back(temp);
		}
	}
	sort(vec.begin(), vec.end());
	if (number == 0) //in danh sách các ngôn ngữ ra màn hình
	{
		for (size_t i = 0; i < vec.size(); i++)
		{
			cout << i + 1 << ". " << vec[i] << endl;
		}
		cout << "YOUR SELECTION: ";
	}
	else //in lựa chọn ra màn hình
	{
		data = vec[number - 1];
		cout << "---->YOUR SELECTION: " << vec[number - 1] << endl;
	}
	fileText.close();
}
void General::getFileTime(string f, int number, string& data) //Đọc dữ liệu từ file Language.txt
{
	checkFileTime(f);
	vector<string>vec;

	ifstream fileText(f);
	if (fileText.is_open())
	{
		while (!fileText.eof())
		{
			char temp[255];
			fileText.getline(temp, 255);
			vec.push_back(temp);
		}
	}
	if (number == 0)
	{
		for (size_t i = 0; i < vec.size(); i++)
		{
			cout << i + 1 << ". " << vec.at(i) << endl;//in ra bảng lựa chọn timezone
		};
		cout << "YOUR SELECTION: ";
	}
	else
	{
		data = vec[number - 1];
		cout << "---->YOUR SELECTION: " << vec.at(number - 1) << endl;//lựa chọn timezone
	};
	fileText.close();
}

void General::writeFileTime()
{
	ofstream fileText("TimeZone.txt");
	try {
		if (fileText.is_open())
		{
			fileText << "(GMT - 12:00) / International Date Line West" << endl << "(GMT - 11:00) / Midway Island, Samoa" << endl
				<< "(GMT - 10:00) / Hawaii" << endl << "(GMT - 09:00) / Alaska" << endl << "(GMT - 08:00) / Tijuana, Baja California" << endl
				<< "(GMT - 07:00) / Chihuahua, La Paz, Mazatlan - New" << endl << "(GMT - 06:00) / Guadalajara, Mexico City, Monterrey - New" << endl
				<< "(GMT - 05:00) / Eastern Time(US and Canada)" << endl << "(GMT - 04:00) / Atlantic Time(Canada)" << endl
				<< "(GMT - 03:30) / Newfoundland" << endl << "(GMT - 02:00) / Mid - Atlantic" << endl << "(GMT - 01:00) / Azores" << endl
				<< "(GMT - 00:00) / Monrovia, Reykjavik" << endl << "(GMT + 01:00) / Belgrade, Bratislava, Budapest, Ljubljana, Prague" << endl
				<< "(GMT + 02:00) / Minsk" << endl << "(GMT + 03:00) / Moscow, St.Petersburg, Volgograd" << endl
				<< "(GMT + 04:00) / Abu Dhabi, Muscat" << endl << "(GMT + 04:30) / Kabul" << endl << "(GMT + 05:00) / Tashkent" << endl
				<< "(GMT + 05:30) / Chennai, Kolkata, Mumbai, New Delhi" << endl << "(GMT + 05:45) / Kathmandu" << endl
				<< "(GMT + 06:00) / Astana, Dhaka" << endl << "(GMT + 06:30) / Yangon(Rangoon) /" << endl
				<< "(GMT + 07:00) / Bangkok, Hanoi, Jakarta" << endl << "(GMT + 08:00) / Beijing, Chongqing, Hong Kong, Urumqi" << endl
				<< "(GMT + 08:00) / Irkutsk, Ulaanbaatar" << endl << "(GMT + 09:00) / Seoul" << endl << "(GMT + 09:30) / Adelaide" << endl
				<< "(GMT + 10:00) / Canberra, Melbourne, Sydney" << endl << "(GMT + 11:00) / Magadan, Solomon Islands, New Caledonia" << endl
				<< "(GMT + 12:00) / Fiji, Kamchatka, Marshall Is." << endl << "(GMT + 13:00) / Nuku'alofa";
			fileText.close();
		}
		else
		{
			throw 909;
		}
	}
	catch (int)
	{
		cerr << "Can not write file TimeZone.txt" << endl;
	}
	catch (...)
	{
		cerr << "ERROR DIF" << endl;
	}
}
void General::writeFileLanguage()
{
	ofstream fileText("language.txt");
	try {
		if (fileText.is_open())
		{
			fileText << "Mandarin (entire branch)" << endl << "Spanish" << endl << "English" << endl << "Hindi" << endl
				<< "Arabic" << endl << "Portuguese" << endl << "Bengali" << endl << "Russian" << endl << "Japanese" << endl
				<< "Punjabi" << endl << "German" << endl << "Javanese" << endl << "Wu(inc.Shanghainese)" << endl << "Malay(inc.Indonesian and Malaysian)" << endl
				<< "Telugu" << endl << "Vietnamese" << endl << "Korean" << endl << "French" << endl << "Marathi" << endl
				<< "Tamil" << endl << "Urdu" << endl << "Turkish" << endl << "Italian" << endl << "Yue(inc.Cantonese)" << endl
				<< "Thai" << endl << "Gujarati" << endl << "Jin" << endl << "Southern Min" << endl << "Persian" << endl
				<< "Polish";
			fileText.close();
		}
		else
		{
			throw 909;
		}
	}
	catch (int)
	{
		cerr << "Can not Write File language.txt " << endl;
	}
	catch (...)
	{
		cout << "ERROR DIF! " << endl;
	}
}

void General::checkFileTime(string f)
{
	ifstream fileText(f);
	try {
		if (fileText.fail())
		{
			throw 909; //file không tồn tại
		}
		else if (checkEmptyFile(fileText))
		{
			throw "FILE TimeZone.txt is not Data and then Written to file";
		}
	}
	catch (int)
	{
		cout << "File TimeZone.txt dose not Exits! ---->This is new File.." << endl;
		writeFileTime();
	}
	catch (const char* exception)
	{
		cerr << exception << endl << endl;
		writeFileTime();
	}
	catch (...)
	{
		cerr << "ERROR DIF!" << endl;
	}
}
void General::checkFileLanguage(string f)
{
	ifstream fileText(f);
	try {
		if (fileText.fail())
		{
			throw 909; //file không tồn tại
		}
		else if (checkEmptyFile(fileText))
		{
			throw "FILE language.txt is not Data and then Written to file";
		}
	}
	catch (int)
	{
		cout << "File language.txt dose not Exits! ---->This is new File.." << endl;
		writeFileLanguage();
	}
	catch (const char* exception)
	{
		cerr << exception << endl << endl;
		writeFileLanguage();
	}
	catch (...)
	{
		cerr << "ERROR DIF!" << endl;
	}
}

bool General::checkEmptyFile(ifstream& pFile)
{
	if (pFile.peek() == ifstream::traits_type::eof())
	{
		return true;
	}
	else return false;
}
void General::nhapThongTin()
{
	string numTime = "[1-9]|1[0-9]|2[0-9]|3[0-2]";
	string numLanguage = "[1-9]|1[0-9]|2[0-9]|30";

	string data; //dữ liệu time tham tham chiếu zone hoặc language	
	string number1, number2; //các số nhập vào(kiểu string) để chọn danh sách language và timezone	
	int num1 = 0, num2 = 0; //số (kiểu int) để lấy thông tin từ file timezone hoặc language theo hàng

	cout << "--- SELECT TIME ZONE ---" << endl;

	getFileTime("TimeZone.txt", num1, data);;
	num1 = stoi(checkDataString(numTime));
	getFileTime("TimeZone.txt", num1, data);

	setTimeZone(data);
	system("pause");
	system("cls");

	cout << "--- SELECT LANGUAGE ---" << endl;

	getFileLanguage("Language.txt", num2, data);
	num2 = stoi(checkDataString(numLanguage));
	getFileLanguage("Language.txt", num2, data);

	setLanguage(data);
	//system("pause");
	//system("cls");

}
void General::xuatThongTin()
{
	cout << setw(15) << getTimeZone() << setw(52) << getLanguage() << endl << endl;
}

void General::strTok(char data[100], string time[100], string zone[100], int& dem) //cắt chuỗi
{
	char* p = strtok(data, "/");
	while (p != NULL)
	{
		// lưu lần lần cắt thứ nhất vào time
		time[dem] = p;
		p = strtok(NULL, "/");
		// lưu lần lần cắt thứ hai vào zone
		zone[dem] = p;
		break;
	}
	dem++;
}


