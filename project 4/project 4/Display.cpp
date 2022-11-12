#include "Display.h"

Display::Display()
{
	lightLevel = 0;
	screenLight = 0;
	taploLight = 0;
}
Display::Display(int lightLevel, int screenLight, int taploLight)
{
	this->lightLevel = lightLevel;
	this->screenLight = screenLight;
	this->taploLight = taploLight;
}
Display::~Display()
{
}

void Display::setLightLevel(int lightLevel)
{
	this->lightLevel = lightLevel;
}
void Display::setScreenLight(int screenLight)
{
	this->screenLight = screenLight;
}
void Display::setTaploLight(int taploLight)
{
	this->taploLight = taploLight;
}

int Display::getLightLevel()
{
	return this->lightLevel;
}
int Display::getScreenLight()
{
	return this->screenLight;
}
int Display::getTaploLight()
{
	return this->taploLight;
}


void Display::nhapThongTin()
{
	string f = "[1-9]|[1-9][0-9]*";
	cout << "    Light Level: ";
	setLightLevel(checkDataNum(f));
	cout << "    Screen light level: ";
	setScreenLight(checkDataNum(f));
	cout << "    Taplo light level: ";
	setTaploLight(checkDataNum(f));
	cout << endl;
}
void Display::xuatThongTin()
{
	cout << setw(15) << getLightLevel() << setw(24) << getScreenLight() << setw(30) << getTaploLight() << endl << endl;
}



