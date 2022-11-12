#pragma once
#include "Display.h"
#include"CarInfor.h"
#include"Sound.h"
#include"General.h"
#define MAX_CAR 100

class Caidat :public CarInfor
{
public:
	Caidat();
	~Caidat();
	
	void selectMenuFirst(); //menu lựa chọn MH1.
	void selectMenuSecond();//menu lựa chọn MH2.
	void selectMenuThird();//menu lựa chọn MH3.

	void Menu4(); //in full thông tin sắp xếp theo tên, key
	void Menu5(); //in thông tin Display theo tên , key
	void Menu6(); //in thông tin Sound theo tên, key
	void Menu7(); //in thông tin General theo tên, key

	void sossanhKeyNumber (CarInfor* CAR);//so sánh key number
	void overrideDisplay(CarInfor* CAR, Display* DISPLAY);//ghi đè Display	
	void overrideSound(CarInfor* CAR, Sound* SOUND);//ghi đè Sound
	void overrideGeneral( CarInfor* CAR, General* GENERAL);//ghi đè General
	
	void question();//Hỏi người dùng có muốn nhập xe tiếp không
	void sortOwerName();//sắp xếp theo tên chủ xe
	void sortKey();//sắp xếp theo MSCN
protected:
	void getInforCar();//Lấy thông tin của car
	void getInforDisplay();//lấy thông tin Display
	void getInforSound();//lấy thông tin sound
	void getInforGeneral();//lấy thông tin của general

	void showInforDisplay();//xuất thông tin Display
	void showInforSound();//xuất thông tin Display
	void showInforGeneral();//xuất thông tin General
	void showAllSetting();//xuất thông tin all setting

	void thongBao();
private:	
	CarInfor** car = new CarInfor*[MAX_CAR];
	Display** display = new Display * [MAX_CAR];
	Sound** sound = new Sound * [MAX_CAR];
	General** general = new General * [MAX_CAR];
	string number;//các phím lựa chọn
	int thongbao; //biến thông báo cacs lựa chọn Display, Sound, General
	int num;//đếm số xe tăng lên
	int car_num = 0;//đếm số xe hiện có
};

