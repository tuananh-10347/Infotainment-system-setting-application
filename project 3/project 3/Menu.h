#ifndef MENU_H_
#define MENU_H_
#include"Setting.h"

class Menu
{
public:

	void showMenu1();
	void Menu1(); //Menu lựa chọn

	void showMenu2();
	void Menu2(); //menu thông báo cài đặt từng loại thông tin

	void Menu3(); //menu thông báo print từng loại thông tin
	void Menu4(); //in full thông tin sắp xếp theo tên, key

	void Menu5(); //in thông tin Display theo tên , key
	void Menu6(); //in thông tin Sound theo tên, key
	void Menu7(); //in thông tin General theo tên, key
protected:
	void exist(Setting* temp);
	void compairKeyNumber(Setting* temp);

	void readFile(); //đọc dữ liệu từ file Setting.txt
	void writeFile(); //ghi dữ liệu vào file Setting.txt
	bool checkEmptyFile(ifstream& pFile); //Kiểm tra file có dữ liệu hay không


	void showInforDisplay();
	void showInforSound();
	void showInforGeneral();

	void showAllSetting();
	void question(); //Lựa chọn yes no để tiếp tục cài đặt thông tin cho xe

	void sortName();
	void sortKeyNumber();

private:
	Sound d;
	vector<Setting*> per;
	int thongbao = 0;
	string number; //các phím lựa chọn
	int check = 0; // kiểm tra file chỉ đọc 1 lần
};
#endif //MENU_H_