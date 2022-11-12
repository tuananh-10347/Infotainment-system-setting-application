#pragma once
#include "Display.h"
class Sound : public CarInfor
{
private:
    int media;
    int call;
    int navigation;
    int notification;
public:
    Sound();
    Sound(int, int, int,int);
    ~Sound();

    void setMedia(int);
    void setCall(int);
    void setNavigation(int);
    void setNotification(int);

    int getMedia();
    int getCall();
    int getNavigation();
    int getNotification();

    void nhapThongTin(); //Nhập thông tin Display
    void xuatThongTin(); //Xuất thông tin Display
};

