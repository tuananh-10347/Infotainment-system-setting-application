#pragma once
#ifndef SOUND_H_
#define SOUND_H_
#include "Car.h"
using namespace std;

class Sound : public Car
{
private:
    int media;
    int call;
    int navigation;
    int notification;
public:
    Sound();
    Sound(int, int, int, int);
    ~Sound();

    void setMedia(int);
    void setCall(int);
    void setNavigation(int);
    void setNotification(int);

    int getMedia();
    int getCall();
    int getNavigation();
    int getNotification();

    void nhapThongTin(); //nhập thông tin Sound
    void xuatThongTin(); //Xuat thong tin Sound
};
#endif // SOUND_H_
