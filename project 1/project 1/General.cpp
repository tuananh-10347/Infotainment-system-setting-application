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
	return timeZone;
}
string General::getLanguage()
{
	return language;
}


void General::getFileLanguage(string f, int number, string &data)//Đọc dữ liệu từ TimeZone.txt
{
	ifstream fileText(f, ios::in);
	//biến đếm số hàng của file
	int num = 0;
	//mảng sắp xếp theo anpha
	string arr[100];
	if (!fileText)
	{
		cout << "Can not Read File " << endl;
	}
	else
	{
		while (!fileText.eof())
		{
			char temp[255];
			fileText.getline(temp, 255);
			arr[num] = temp;
			num++;
		}
	}
	//sắp xếp language theo anpha
	for (size_t i = 0; i < num - 1; i++)
	{
		for (size_t j = i + 1; j < num; j++)
		{
			if (arr[i].compare(arr[j]) > 0)
			{
				swap(arr[j], arr[i]);
			}
		}
	}
	//in danh sách các ngôn ngữ ra màn hình
	if (number == 0)
	{
		for (size_t i = 0; i < num; i++)
		{
			cout << i + 1 << ". " << arr[i] << endl;
		}
		cout << "YOUR SELECTION: ";
	}
	//in lựa chọn ra màn hình
	else
	{
		data = arr[number - 1];
		cout << "---->YOUR SELECTION: " << arr[number - 1] << endl;
	}

}
void General::getFileTime(string f, int number,string &data)//Đọc dữ liệu từ file Language.txt
{
	//biến thể hiện chỉ số của các mảng time và zone
	int dem = 0;
	string time[100];
	string zone[100];
	ifstream fileText(f, ios::in);
	//biến đếm số hàng của file
	int num = 0;

	if (!fileText)
	{
		cout << "Can not Read File " << endl;
	}
	else
	{
		while (!fileText.eof())
		{
			char temp[255];
			fileText.getline(temp, 255);
			//cắt chuỗi
			strTok(temp, time, zone, dem);
			num++;
		}
	}
	/*for (size_t i = 0; i < num - 1; i++)
	{
		for (size_t j = i + 1; j < num; j++)
		{
			//sắp xếp theo anpha
			if (zone[i].compare(zone[j]) > 0)
			{
				swap(zone[j], zone[i]);
				//zone được sắp xếp thì time cũng được sắp xếp theo
				swap(time[j], time[i]);
			}
		}
	}*/
	if (number == 0)
	{
		for (size_t i = 0; i < num; i++)
		{
			//in ra bảng lựa chọn timezone
			cout << i + 1 << ". " << time[i] << "/" << zone[i] << endl;
		}
		cout << "YOUR SELECTION: ";
	}
	else
	{
		data = time[number - 1] + "/" + zone[number - 1];
		//lựa chọn timezone
		cout << "---->YOUR SELECTION: " << time[number - 1] << "/" << zone[number - 1] << endl;
		
	}

}
void General::strTok(char data[100], string time[100], string zone[100], int& dem)
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
	system("pause");
	system("cls");

}
void General::xuatThongTin()
{
	cout << setw(15) << getTimeZone() << setw(52) << getLanguage() << endl << endl;
}


