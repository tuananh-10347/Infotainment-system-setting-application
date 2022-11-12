#include "Setting.h"

Setting::Setting()
{
	general = new General();
	sound = new Sound();
	display = new Display();
}
Setting::~Setting()
{
	delete general;
	delete sound;
	delete display;
}

void Setting::setDisplay(Display* display)
{
	this->display = display;
}
void Setting::setGeneral(General* general)
{
	general = general;
}
void Setting::setSound(Sound* sound)
{
	this->sound = sound;
}

General* Setting::getGeneral()
{
	return this->general;
}
Display* Setting::getDisplay()
{
	return this->display;
}
Sound* Setting::getSound()
{
	return this->sound;
}

void Setting::nhapThongTin()
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
void Setting::xuatThongTin()
{
	cout << setw(20) << getName() << setw(32) << getEmail() << setw(16) << getKeyNumber()
		<< setw(13) << getOdoNumber() << setw(22) << getRemindService() << endl << endl;
}

