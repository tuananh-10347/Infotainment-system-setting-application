#include "Sound.h"

Sound::Sound()
{
	media = 0;
	call = 0;
	navigation = 0;
	notification = 0;
}
Sound::Sound(int media, int call, int navigation, int notification)
{
	this->media = media;
	this->call = call;
	this->navigation = navigation;
	this->notification = notification;
}
Sound::~Sound()
{
}

void Sound::setMedia(int media)
{
	this->media = media;
}
void Sound::setCall(int call)
{
	this->call = call;
}
void Sound::setNavigation(int navigation)
{
	this->navigation = navigation;
}
void Sound::setNotification(int notification)
{
	this->notification = notification;
}

int Sound::getMedia()
{
	return this->media;
}
int Sound::getCall()
{
	return this->call;
}
int Sound::getNavigation()
{
	return this->navigation;
}
int Sound::getNotification()
{
	return this->notification;
}

void Sound::nhapThongTin()
{
	string f = "[1-9]|[1-9][0-9]*";
	cout << "    Media: ";
	setMedia(checkDataNum(f));
	cout << "    Call: ";
	setCall(checkDataNum(f));
	cout << "    Navigation: ";
	setNavigation(checkDataNum(f));
	cout << "    Notification: ";
	setNotification(checkDataNum(f));
	cout << endl;
}
void Sound::xuatThongTin()
{
	cout << setw(15) << getMedia() << setw(24) << getCall() << setw(30)
		<< getNavigation() << setw(20) << getNotification() << endl << endl;
}