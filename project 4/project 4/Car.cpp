#include "Car.h"

Car::Car()
{
	this->name = "";
	this->email = "";
	this->keyNumber = "";
	this->odoNumber = 0;
	this->remindService = 0;
}
Car::Car(string name, string email, string keyNumber, int odoNumber, int remindService)
{
	this->name = name;
	this->email = email;
	this->keyNumber = keyNumber;
	this->odoNumber = odoNumber;
	this->remindService = remindService;

}
Car::~Car()
{
}

void Car::setName(string name)
{
	this->name = name;
}
void Car::setEmail(string email)
{
	this->email = email;
}
void Car::setKeyNumber(string keyNumber)
{
	this->keyNumber = keyNumber;
}
void Car::setOdoNumber(int odoNumber)
{
	this->odoNumber = odoNumber;
}
void Car::setRemindService(int remindService)
{
	this->remindService = remindService;
}

string Car::getName()
{

	return this->name;
}
string Car::getEmail()
{
	return this->email;
}
string Car::getKeyNumber()
{
	return this->keyNumber;
}

int Car::getOdoNumber()
{
	return this->odoNumber;
}
int Car::getRemindService()
{
	return this->remindService;
}

//kiểm tra ký tự nhập vào theo regex
bool Car::checkRegex(string data, string f)
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
int Car::checkDataNum(string str)
{
	string strTemp = "";
	int iTemp;
	bool check = true;
	do
	{
		try {
			getline(cin, strTemp);
			if (!checkRegex(strTemp, str))
			{
				cout << endl;
				cout << "Your selection is illegal! Please again: ";
				check = false;
			}
			else
			{
				throw 909;
			}
		}
		catch (...)
		{
			check = true;
			iTemp = stoi(strTemp);
		}
	} while (!check);
	return iTemp;
}
string Car::checkDataString(string str)
{
	string strTemp = "";
	bool check = true;
	do {
		try {
			getline(cin, strTemp);
			if (!checkRegex(strTemp, str))
			{
				cout << endl;
				cout << "Your selection is illegal! Please again: ";
				check = false;
			}
			else
			{
				throw 909;

			}
		}
		catch (...)
		{
			check = true;
		}
	} while (!check);
	return strTemp;
}





