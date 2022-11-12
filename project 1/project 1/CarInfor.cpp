#include "CarInfor.h"

CarInfor::CarInfor()
{
	this->name = "";
	this->email = "";
	this->keyNumber = "0";
	this->odoNumber = 0;
	this->remindService = 0;
}
CarInfor::CarInfor(string name, string email, string keyNumber, int odoNumber, int remindService)
{
	this->name = name;
	this->email = email;
	this->keyNumber = keyNumber;
	this->odoNumber = odoNumber;
	this->remindService = remindService;

}
CarInfor::~CarInfor()
{
}

string CarInfor::getName()
{

	return this->name;
}
string CarInfor::getEmail()
{
	return this->email;
}
string CarInfor::getKeyNumber()
{
	return this->keyNumber;
}
int CarInfor::getOdoNumber()
{
	return this->odoNumber;
}
int CarInfor::getRemindService()
{
	return this->remindService;
}

void CarInfor::setName(string name)
{
	//kiểm tra đầu vào của tên có hợp lệ
	this->name = name;

}
void CarInfor::setEmail(string email)
{
	this->email = email;
}
void CarInfor::setKeyNumber(string keyNumber)
{
	this->keyNumber = keyNumber;
}
void CarInfor::setOdoNumber(int odoNumber)
{
	this->odoNumber = odoNumber;
}
void CarInfor::setRemindService(int remindService)
{
	this->remindService = remindService;
}

//hàm kiểm tra các ký tự nhập vào
bool CarInfor::checkRegex(string data, string f)
{
	regex check(f);
	if (!regex_match(data, check))
	{
		return false;
	}
	else
	{
		return true;
	}
}
int CarInfor::checkDataNum(string str)
{
	string strTemp = "";
	int iTemp;
	bool check = true;
	do
	{
		getline(cin, strTemp);
		if (!checkRegex(strTemp, str))
		{
			cout << endl;
			cout << "Your selection is illegal! Please again: ";
			check = false;
		}
		else
		{

			check = true;
			iTemp = stoi(strTemp);
		}
	} while (!check);
	return iTemp;
}
string CarInfor::checkDataString(string str)
{
	string strTemp = "";
	bool check = true;
	do {
		getline(cin, strTemp);
		if (!checkRegex(strTemp, str))
		{
			cout << endl;
			cout << "Your selection is illegal! Please again: ";
			check = false;
		}
		else
		{
			check = true;
		}
	} while (!check);
	return strTemp;
}

void CarInfor::nhapThongTin()
{
	string checkName = "(([A-Za-z]+) ([A-Za-z]+))+|[A-Za-z]+";
	string checkEmail = "[A-Za-z0-9_]{2,}\.@[A-Za-z]{2,}\.([A-Za-z]{3})";
	string checkKeyNumber = "[0-9]{8}";
	string checkOdoRemind = "[1-9]|[1-9][0-9]*";

	cout << "    Ower name: ";
	setName(checkDataString(checkName));

	cout << "    Email: ";
	setEmail(checkDataString(checkEmail));

	cout << "    Key number: ";
	setKeyNumber(checkDataString(checkKeyNumber));

	cout << "    ODO number: ";
	setOdoNumber(checkDataNum(checkOdoRemind));

	cout << "    Remind service (km): ";
	setRemindService(checkDataNum(checkOdoRemind));
}
void CarInfor::xuatThongTin()
{
	cout << setw(20) << getName() << setw(32) << getEmail() << setw(16) << getKeyNumber()
		<< setw(13) << getOdoNumber() << setw(22) << getRemindService() << endl << endl;
}


