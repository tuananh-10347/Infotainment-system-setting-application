#ifndef CAR_H_
#define CAR_H_
#include <iostream>
#include <iomanip>
#include <string>
#include<regex>
#include<fstream>
#include<vector>

using namespace std;

class Car
{
private:
	string name;
	string email;
	string keyNumber;
	int odoNumber;
	int remindService;
public:
	Car();
	Car(string, string, string, int, int);
	~Car();

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

	virtual void nhapThongTin() = 0; //Nhập thông tin General
	virtual void xuatThongTin() = 0; //Xuất thông tin General

	//kiểm tra đầu vào của các ký tự
	bool checkRegex(string, string);
	int checkDataNum(string str);
	string checkDataString(string str);
};

#endif /* CAR_H_ */
