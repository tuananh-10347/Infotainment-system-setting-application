#ifndef GENERAl_H_
#define GENERAL_H_
#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"

using namespace std;

class General : public Car
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

	void getFileTime(string f, int number, string& data);
	void getFileLanguage(string f, int number, string& data);

	void writeFileLanguage();
	void writeFileTime();

	void checkFileTime(string f); //kiểm soát ngoại lệ file timezone.txt
	void checkFileLanguage(string f); //kiểm soát ngoại lệ file language.txt

	bool checkEmptyFile(ifstream& pFile); //Kiểm tra file có dữ liệu hay không

	void nhapThongTin(); //Nhập thông tin General
	void xuatThongTin(); //Xuất thông tin General

protected:
	void strTok(char data[100], string time[100], string zone[100], int& dem); //hàm cắt chuỗi
};
#endif  //GENERAL_H_ 