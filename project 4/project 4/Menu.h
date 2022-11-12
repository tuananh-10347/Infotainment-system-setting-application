#ifndef MENU_H_
#define MENU_H_
#include"Setting.h"
#include"btree.h"
#include<string>

using namespace std;

class Menu
{
public:
	Menu();
	~Menu();
	void showMenu1();
	void Menu1(); //Menu lựa chọn
	void showMenu2();
	void Menu2(); //menu thông báo cài đặt từng loại thông tin
	void Menu3(); //menu thông báo print từng loại thông tin
	void xuatThongTin(string f, int index); //xuất thông tin từng loại theo Key	
protected:
	void exist(Setting* temp);//Thông báo xe đã có trong danh sách hay chưa
	void readFile(); //đọc dữ liệu từ file Setting.txt	
	void writeFile();
	bool checkEmptyFile(ifstream& pFile); //Kiểm tra file có dữ liệu hay không
	void question(); //Lựa chọn yes no để tiếp tục cài đặt thông tin cho xe	
private:
	Sound d;
	btree per;
	node* pNodeKey;//node chứa MSCN
	node* pNodeName;//node chưa name	
	int thongbao;
	string number; //các phím lựa chọn
	int check; // kiểm tra file chỉ đọc 1 lần
};
#endif //MENU_H_