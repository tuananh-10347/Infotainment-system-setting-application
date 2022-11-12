#pragma once
#include<iostream>
#include<regex>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;

class CarInfor
{
private:
	string name;
	string email;
	string keyNumber;
	int odoNumber;
	int remindService;
public:
	CarInfor();
	CarInfor(string, string, string, int, int);
	~CarInfor();

	//hàm set để thiết lập giá trị
	void setName(string);
	void setEmail(string);
	void setKeyNumber(string);
	void setOdoNumber(int);
	void setRemindService(int);

	//hàm get để lấy giá trị
	string getName();
	string getEmail();
	string getKeyNumber();
	int getOdoNumber();
	int getRemindService();

	void nhapThongTin(); //Nhập thông tin Display
	void xuatThongTin(); //Xuất thông tin Display

	//kiểm tra đầu vào của các ký tự
	bool checkRegex(string, string);
	int checkDataNum(string str);
	string checkDataString(string str);
};

