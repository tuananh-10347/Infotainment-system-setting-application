#pragma once
#ifndef SETTING_H_
#define SETTING_H_
#include"General.h"
#include "Display.h"
#include "Sound.h"
#include "car.h"

class Setting : public Car
{
private:
	General* general;
	Sound* sound;
	Display* display;
public:
	Setting();
	~Setting();

	void setGeneral(General* general);
	void setDisplay(Display* display);
	void setSound(Sound* sound);

	Sound* getSound();
	Display* getDisplay();
	General* getGeneral();

	void nhapThongTin(); //Nhap thông tin Car
	void xuatThongTin(); //Xuất thông tin Car
};
#endif /* SETTING_H_ */

