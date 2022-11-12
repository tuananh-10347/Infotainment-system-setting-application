#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Sound.h"
#include<fstream>
class General : public CarInfor
{
private:
	string timeZone;
	string language;
public:
	General();
	General(string, string);
	~General();

	void setTimeZone(string);
	void setLanguage(string);

	string getTimeZone();
	string getLanguage();

	void getFileTime(string f, int number, string &data);
	void getFileLanguage(string f, int number, string &data);
	
	void nhapThongTin(); //Nhập thông tin Display
	void xuatThongTin(); //Xuất thông tin Display
protected:
	//hàm cắt chuỗi
	void strTok(char data[100], string time[100], string zone[100], int& dem);

};

