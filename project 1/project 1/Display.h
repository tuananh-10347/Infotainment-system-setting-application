#pragma once
#include"CarInfor.h"

class Display:public CarInfor
{
private:
	int lightLevel;
	int screenLight;
	int taploLight;
public: 
	Display();
	Display(int, int, int);
	~Display();

	//hàm set cài đặt giá trị
	void setLightLevel(int);
	void setScreenLight(int);
	void setTaploLight(int);
	
	//hàm get để trả về giá trị
	int getLightLevel();
	int getScreenLight();
	int getTaploLight();

	void nhapThongTin(); //Nhập thông tin Display
	void xuatThongTin(); //Xuất thông tin Display
};

