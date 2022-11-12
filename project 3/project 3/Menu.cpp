#include "Menu.h"

using namespace std;
//hiển thị thông tin menu và cài đặt menu
void Menu::showMenu1()
{
    cout << "--- SELECT MENU ---" << endl
        << "1. Input setting information" << endl
        << "2. Print setting information" << endl
        << "0. Exit" << endl
        << "Your selection: ";
}
void Menu::Menu1() //Menu lựa chọn
{

    if (check == 0) //đọc file 1 lần
    {
        readFile();
        check++;
    }
    showMenu1();
    do
    {
        getline(cin, number);
        if (number == "1")
        {
            Menu2();

        }
        else if (number == "2")
        {
            Menu3();
        }
        else if (number == "0")
        {
            system("cls");
            cout << "Are you sure want to close the app?" << endl;
            cout << "CHOOSE Y: YES OR CHOOSE N: NO." << endl;
            string YN;
            do {
                getline(cin, YN);
                if (YN == "y" || YN == "Y")
                {

                    cout << "\t\t\t\tGood bye. See you again !" << endl;
                    exit(0);
                }
                else if (YN == "N" || YN == "n")
                {
                    system("cls");
                    Menu1();
                }
                else
                {
                    cout << "Your selection is illegal !" << endl;
                    cout << "Please selecting again" << endl;
                    system("pause");
                    system("cls");
                    cout << "Are you sure want to close the app?" << endl;
                    cout << "CHOOSE Y: YES OR CHOOSE N: NO." << endl;
                }
            } while (!(YN == "N" || YN == "n" || YN == "Y" || YN == "y"));
        }
        else
        {
            cout << "Your selection is illegal !" << endl;
            cout << "Please selecting again" << endl;
            system("pause");
            system("cls");
            showMenu1();
        }
    } while (!(number == "1" || number == "2" || number == "0"));
}

//hiển thị thông tin menu và cài đặt menu
void Menu::showMenu2()
{
    cout << "--- SELECT MENU ---" << endl
        << "1. Display setting" << endl
        << "2. Sound setting" << endl
        << "3. Gerenal setting" << endl
        << "0. Exit" << endl
        << "Your selection: ";
}
void Menu::Menu2() //menu thông báo cài đặt từng loại thông tin
{
    system("cls");
    showMenu2();
    do
    {
        getline(cin, number);
        if (number == "1")
        {

            thongbao = 1;
            system("cls");
            cout << "--- Input Display setting ---" << endl;
            cout << "Car index: " << per.size() + 1 << endl;
            Setting* temp = new Setting;

            temp->nhapThongTin();
            exist(temp);
            temp->getDisplay()->nhapThongTin();//Nhập thông tin chủ xe        
            compairKeyNumber(temp); //so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế 
            writeFile();// GHI FILE
            question(); //cài đặt xe tiếp theo
        }
        else if (number == "2")
        {
            Setting* temp = new Setting;
            thongbao = 2;
            system("cls");
            cout << "--- Input Sound setting ---" << endl;
            cout << "Car index: " << per.size() + 1 << endl;
            temp->nhapThongTin();
            exist(temp);//đưa ra thông báo xe đã tồn tại hay chưa
            temp->getSound()->nhapThongTin();//Nhập thông tin chủ xe 
            compairKeyNumber(temp); //so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế
            writeFile(); //GHI FILE
            question();//cài đặt xe tiếp theo

        }
        else if (number == "3")
        {
            Setting* temp = new Setting;
            thongbao = 3;
            system("cls");
            cout << "--- Input General setting ---" << endl;
            cout << "Car index: " << per.size() + 1 << endl;
            temp->nhapThongTin();
            exist(temp);//đưa ra thông báo xe đã tồn tại hay chưa
            system("pause");
            system("cls");
            temp->getGeneral()->nhapThongTin();//Nhập thông tin chủ xe 
            compairKeyNumber(temp); //so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế
            writeFile(); // GHI FILE
            question();//cài đặt xe tiếp theo

        }
        else if (number == "0")
        {
            system("cls");
            Menu1();

        }
        else
        {
            cout << "Your selection is illegal !" << endl;
            cout << "Please selecting again" << endl;
            system("pause");
            system("cls");
            showMenu2();
        }
    } while (!(number == "1" || number == "2" || number == "3" || number == "0"));

}

void Menu::Menu3() //menu thông báo print từng loại thông tin
{
    system("cls");
    cout << "--- SELECT MENU ---" << endl
        << "1. Print Display setting information" << endl
        << "2. Print Sound setting information" << endl
        << "3. Print Gerenal setting information" << endl
        << "4. Print all setting information" << endl
        << "0. Exit" << endl
        << "Your selection: ";
    do
    {
        getline(cin, number);
        //Hiển thị thông tin của Display
        if (number == "1")
        {
            system("cls");
            //kiểm tra Display đã có dữ liệu hay chưa
            if (per.size() == 0)
            {
                //chưa có thì yêu cầu người dùng nhập dữ liệu
                cout << "My list has not Data" << endl;
                cout << "Please input Data!" << endl;
                Menu1();
            }
            else
            {
                //xuất thông tin Display
                Menu5();
                system("pause");
                system("cls");
                Menu1();
            }
        }
        else if (number == "2")
        {
            system("cls");
            //kiểm tra Sound đã có dữ liệu hay chưa
            if (per.size() == 0)
            {
                //chưa có thì yêu cầu người dùng nhập dữ liệu
                cout << "My list has not Data" << endl;
                cout << "Please input Data!" << endl;
                Menu1();
            }
            else
            {
                //xuất thông tin Sound
                Menu6();
            }
        }
        else if (number == "3")
        {
            system("cls");
            //kiểm tra General đã có dữ liệu hay chưa
            if (per.size() == 0)
            {
                //chưa có thì yêu cầu người dùng nhập dữ liệu
                cout << "My list has not Data" << endl;
                cout << "Please input Data!" << endl;
                Menu1();
            }
            else
            {
                // xuất thông tin General
                Menu7();
            }

        }
        else if (number == "4")
        {
            system("cls");
            if (per.size() == 0)
            {
                cout << "My list has not Data" << endl;
                cout << "Please input Data!" << endl;
                Menu1();
            }
            else
            {
                Menu4();
            }

        }
        else if (number == "0")
        {
            system("cls");
            Menu1();
        }
        else
        {
            cout << "Your selection is illegal !" << endl;
            cout << "Please selecting again" << endl;
            system("pause");
            system("cls");
            cout << "--- SELECT MENU ---" << endl
                << "1. Print Display setting information" << endl
                << "2. Print Sound setting information" << endl
                << "3. Print Gerenal setting information" << endl
                << "4. Print all setting information" << endl
                << "0. Exit" << endl
                << "Your selection: ";
        }
    } while (!(number == "1" || number == "2" || number == "3" || number == "4" || number == "0"));

}
void Menu::Menu4() //in full thông tin theo tên hoặc key
{
    cout << "--- SELECT MENU ---" << endl;
    cout << "1. Print all setting by Name" << endl
        << "2. Print all setting by KeyNumber" << endl
        << "0. Exit" << endl
        << "Your selection: ";
    do
    {
        getline(cin, number);
        if (number == "1")
        {
            system("cls");
            sortName();
            showAllSetting();
            system("pause");
            system("cls");
            Menu1();
        }
        else if (number == "2")
        {
            system("cls");
            sortKeyNumber();
            showAllSetting();
            system("pause");
            system("cls");
            Menu1();
        }
        else if (number == "0")
        {
            system("cls");
            Menu3();
        }
        else
        {
            cout << "Your selection is illegal !" << endl;
            cout << "Please selecting again" << endl;
            system("pause");
            system("cls");
            cout << "--- SELECT MENU ---" << endl;
            cout << "1. Print all setting by Name" << endl
                << "2. Print all setting by KeyNumber" << endl
                << "3. Print all setting random" << endl
                << "0. Exit" << endl
                << "Your selection: ";
        }
    } while (!(number == "1" || number == "2" || number == "0"));


}

void Menu::Menu5() //in thông tin Display theo tên , key
{
    cout << "--- SELECT MENU ---" << endl;
    cout << "1. Print Display setting by Name" << endl
        << "2. Print Display setting by KeyNumber" << endl
        << "0. Exit" << endl
        << "Your selection: ";
    do
    {
        getline(cin, number);
        if (number == "1")
        {
            system("cls");
            sortName();
            cout << endl;
            showInforDisplay();
            system("pause");
            system("cls");
            Menu1();
        }
        else if (number == "2")
        {
            system("cls");
            sortKeyNumber();
            showInforDisplay();
            system("pause");
            system("cls");
            Menu1();
        }
        else if (number == "0")
        {
            system("cls");
            Menu3();
        }
        else
        {
            cout << "--- SELECT MENU ---" << endl;
            cout << "1. Print Display setting by Name" << endl
                << "2. Print Display setting by KeyNumber" << endl
                << "0. Exit" << endl
                << "Your selection: ";
        }
    } while (!(number == "1" || number == "2" || number == "0"));

}
void Menu::Menu6() //in thông tin Sound theo tên , key
{
    cout << "--- SELECT MENU ---" << endl;
    cout << "1. Print Sound setting by Name" << endl
        << "2. Print Sound setting by KeyNumber" << endl
        << "0. Exit" << endl
        << "Your selection: ";
    do
    {
        getline(cin, number);
        if (number == "1")
        {
            system("cls");
            sortName();
            showInforSound();
            system("pause");
            system("cls");
            Menu1();
        }
        else if (number == "2")
        {
            system("cls");
            sortKeyNumber();
            showInforSound();
            system("pause");
            system("cls");
            Menu1();
        }
        else if (number == "0")
        {
            system("cls");
            Menu3();
        }
        else
        {
            cout << "--- SELECT MENU ---" << endl;
            cout << "1. Print Sound setting by Name" << endl
                << "2. Print Sound setting by KeyNumber" << endl
                << "0. Exit" << endl
                << "Your selection: ";
        }
    } while (!(number == "1" || number == "2" || number == "0"));
}
void Menu::Menu7() //in thông tin General theo tên , key
{
    cout << "--- SELECT MENU ---" << endl;
    cout << "1. Print General setting by Name" << endl
        << "2. Print General setting by KeyNumber" << endl
        << "0. Exit" << endl
        << "Your selection: ";
    do
    {
        getline(cin, number);
        if (number == "1")
        {
            system("cls");
            sortName();
            showInforGeneral();
            system("pause");
            system("cls");
            Menu1();
        }
        else if (number == "2")
        {
            system("cls");
            sortKeyNumber();
            showInforGeneral();
            system("pause");
            system("cls");
            Menu1();
        }
        else if (number == "0")
        {
            system("cls");
            Menu3();
        }
        else
        {
            cout << "--- SELECT MENU ---" << endl;
            cout << "1. Print General setting by Name" << endl
                << "2. Print General setting by KeyNumber" << endl
                << "0. Exit" << endl
                << "Your selection: ";
        }
    } while (!(number == "1" || number == "2" || number == "0"));
}

void Menu::question() //mục đích của hàm: hỏi người dùng có tiếp tục nhập thông tin cho xe
{
    string YN; //YES OR NO
    cout << "Will you input for car " << " " << "(y/n)" << endl;
    YN = d.checkDataString("y|n|Y|N");
    if (YN == "y" || YN == "Y")
    {
        if (number == "1")
        {
            Setting* temp = new Setting;
            cout << "Car index: " << per.size() + 1 << endl;
            temp->nhapThongTin();
            exist(temp);
            temp->getDisplay()->nhapThongTin();
            compairKeyNumber(temp); //so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tại thì thay thế  
            writeFile(); //GHI FILE
            question();
        }
        else if (number == "2")
        {
            Setting* temp = new Setting;
            cout << "Car index: " << per.size() + 1 << endl;
            temp->nhapThongTin();
            exist(temp);
            temp->getSound()->nhapThongTin();
            compairKeyNumber(temp); //so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tại thì thay thế  
            writeFile(); //GHI FILE
            question();
        }
        else if (number == "3")
        {
            Setting* temp = new Setting;
            cout << "Car index: " << per.size() + 1 << endl;
            temp->nhapThongTin();
            exist(temp);
            temp->getGeneral()->nhapThongTin();
            compairKeyNumber(temp); //so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tại thì thay thế  
            writeFile(); //GHI FILE
            question();
        }
    }
    else
    {
        system("cls");
        //return MH1
        Menu1();
    }
}
void Menu::compairKeyNumber(Setting* temp) //so sánh keyNumber
{
    int theodoi = 0; //biến xác định có trùng key hay không
    if (per.size() > 0)
    {
        for (size_t i = 0; i < per.size(); i++)
        {
            if (per.at(i)->getKeyNumber() == temp->getKeyNumber())
            {
                per.at(i)->setName(temp->getName());
                per.at(i)->setEmail(temp->getEmail());
                per.at(i)->setOdoNumber(temp->getOdoNumber());
                per.at(i)->setRemindService(temp->getRemindService());
                switch (thongbao)
                {

                case 1:
                    theodoi = 1;
                    //Kiểm tra KeyNumber, thiết lập lại thông tin
                    per.at(i)->getDisplay()->setLightLevel(temp->getDisplay()->getLightLevel());
                    per.at(i)->getDisplay()->setTaploLight(temp->getDisplay()->getTaploLight());
                    per.at(i)->getDisplay()->setScreenLight(temp->getDisplay()->getScreenLight());
                    break;
                case 2:
                    theodoi = 1;
                    //Kiểm tra KeyNumber, thiết lập lại thông tin
                    per.at(i)->getSound()->setMedia(temp->getSound()->getMedia());
                    per.at(i)->getSound()->setCall(temp->getSound()->getCall());
                    per.at(i)->getSound()->setNavigation(temp->getSound()->getNavigation());
                    per.at(i)->getSound()->setNotification(temp->getSound()->getNotification());
                    break;
                case 3:
                    theodoi = 1;
                    //Kiểm tra KeyNumber, thiết lập lại thông tin
                    per.at(i)->getGeneral()->setLanguage(temp->getGeneral()->getLanguage());
                    per.at(i)->getGeneral()->setTimeZone(temp->getGeneral()->getTimeZone());
                    break;
                }
            }
        }
        if (theodoi == 0)
        {
            per.push_back(temp);
        }
    }
    else {
        per.push_back(temp);
    }
}
void Menu::sortName() //sap xep theo ten
{
    if (per.size() > 1)
    {
        for (size_t i = 0; i < per.size(); i++)
        {
            for (size_t j = 0; j < per.size() - 1 - i; j++)
            {
                if (per.at(j)->getName().compare(per.at(j + 1)->getName()) == 1)
                {
                    swap(per.at(j), per.at(j + 1));
                }

            }
        }
    }
}
void Menu::sortKeyNumber() //sắp xếp theo MSCN
{
    if (per.size() > 1)
    {
        for (size_t i = 0; i < per.size(); i++)
        {
            for (size_t j = 0; j < per.size() - i - 1; j++)
            {
                if (stoi(per.at(j)->getKeyNumber()) > stoi(per.at(j + 1)->getKeyNumber()))
                {
                    swap(per.at(j), per.at(j + 1));
                }

            }
        }
    }
}
void Menu::exist(Setting* temp) //kiểm tra xe đã có trong danh sách
{
    int counter = 0; //biến đếm để xem MSCN bằng nhau
    for (size_t i = 0; i < per.size(); i++)
    {
        if (per.at(i)->getKeyNumber() == temp->getKeyNumber())
        {
            counter = 1;
            break;
        }
    }
    if (counter == 1)
    {
        cout << "      -> This car already existed, data will be overriten" << endl;
    }
    else
    {
        if (per.size() != 0)
        {
            cout << "      ->This is a new car, data will be appended to your list" << endl;
        }
    }
}

void Menu::showInforDisplay()
{

    for (size_t i = 0; i < per.size(); i++)
    {
        cout << "---Common " << i + 1 << ":" << endl;
        cout << setw(15) << "Ower name" << setw(20) << "Email" << setw(35) << "Key number" << setw(20)
            << "ODO number" << setw(30) << "Remind service (km)" << endl;
        per.at(i)->xuatThongTin();
        cout << "---Display: " << endl;
        cout << setw(15) << "Light level" << setw(31) << "Screen Light level" << setw(29) << "Taplo light level" << endl;
        per.at(i)->getDisplay()->xuatThongTin();
        cout << "----------------------------------------------------------------------------------";
        cout << "--------------------------------------------------------------------------------------" << endl;
    }
}
void Menu::showInforSound()
{
    for (size_t i = 0; i < per.size(); i++)
    {
        cout << "---Common " << i + 1 << ":" << endl;
        cout << setw(15) << "Ower name" << setw(20) << "Email" << setw(35) << "Key number" << setw(20)
            << "ODO number" << setw(30) << "Remind service (km)" << endl;
        per.at(i)->xuatThongTin();
        cout << "---Sound: " << endl;
        cout << setw(15) << "Media" << setw(23) << "Call" << setw(36) << "Navigation" << setw(22) << "Notification" << endl;
        per.at(i)->getSound()->xuatThongTin();
        cout << "----------------------------------------------------------------------------------";
        cout << "--------------------------------------------------------------------------------------" << endl;
    }

}
void Menu::showInforGeneral()
{
    for (size_t i = 0; i < per.size(); i++)
    {
        cout << "---Common " << i + 1 << ":" << endl;
        cout << setw(15) << "Ower name" << setw(20) << "Email" << setw(35) << "Key number" << setw(20)
            << "ODO number" << setw(30) << "Remind service (km)" << endl;
        per.at(i)->xuatThongTin();
        cout << "---General:" << endl;
        cout << setw(15) << "TimeZone" << setw(24) << "Language" << endl;
        per.at(i)->getGeneral()->xuatThongTin();
        cout << "----------------------------------------------------------------------------------";
        cout << "--------------------------------------------------------------------------------------" << endl;
    }
}
void Menu::showAllSetting()
{
    for (size_t i = 0; i < per.size(); i++)
    {
        cout << "---Common " << i + 1 << ":" << endl;
        cout << setw(15) << "Ower name" << setw(20) << "Email" << setw(35) << "Key number" << setw(20)
            << "ODO number" << setw(30) << "Remind service (km)" << endl;
        per.at(i)->xuatThongTin();
        cout << "---Display: " << endl;
        cout << setw(15) << "Light level" << setw(31) << "Screen Light level" << setw(29) << "Taplo light level" << endl;
        per.at(i)->getDisplay()->xuatThongTin();
        cout << "---Sound: " << endl;
        cout << setw(15) << "Media" << setw(23) << "Call" << setw(36) << "Navigation" << setw(22) << "Notification" << endl;
        per.at(i)->getSound()->xuatThongTin();
        cout << "---General:" << endl;
        cout << setw(15) << "TimeZone" << setw(24) << "Language" << endl;
        per.at(i)->getGeneral()->xuatThongTin();
        cout << "----------------------------------------------------------------------------------";
        cout << "--------------------------------------------------------------------------------------" << endl;
    }

}

void Menu::readFile() //đọc dữ liệu vào file
{
    ifstream settingInput("Setting.txt");
    try
    {
        if (settingInput.fail())
        {
            throw "File setting.txt dose not Exits!";
        }
        else if (checkEmptyFile(settingInput))
        {
            throw 909;
        }
        else if (settingInput.is_open())
        {
            while (!settingInput.eof())
            {
                string tam;
                Setting* temp = new Setting;
                string name, email, keyNumber, language, timeZone;
                string odoNumber, remindService;
                string lightLevel, screenLight, taploLight, media, call,
                    navigation, notification;

                //đọc thông tin xe
                getline(settingInput, tam, ' ');
                getline(settingInput, name, ',');
                getline(settingInput, email, ',');
                getline(settingInput, keyNumber, ',');
                getline(settingInput, odoNumber, ',');
                getline(settingInput, remindService, ' ');

                //đọc thông tin General
                getline(settingInput, tam, ' ');
                getline(settingInput, language, ',');
                getline(settingInput, timeZone, ';');

                //đọc thông tin Sound
                getline(settingInput, tam, ' ');
                getline(settingInput, media, ',');
                getline(settingInput, call, ',');
                getline(settingInput, navigation, ',');
                getline(settingInput, notification, ';');

                //đọc thông tin Display
                getline(settingInput, tam, ' ');
                getline(settingInput, lightLevel, ',');
                getline(settingInput, screenLight, ',');
                getline(settingInput, taploLight, ';');
                getline(settingInput, tam);

                //đưa dữ liệu từ file vào đối tượng temp
                temp->setName(name);
                temp->setEmail(email);
                temp->setKeyNumber(keyNumber);
                temp->setOdoNumber(stoi(odoNumber));
                temp->setRemindService(stoi(remindService));
                temp->getDisplay()->setLightLevel(stoi(lightLevel));
                temp->getDisplay()->setScreenLight(stoi(screenLight));
                temp->getDisplay()->setTaploLight(stoi(taploLight));
                temp->getSound()->setCall(stoi(call));
                temp->getSound()->setMedia(stoi(media));
                temp->getSound()->setNavigation(stoi(navigation));
                temp->getSound()->setNotification(stoi(notification));
                temp->getGeneral()->setLanguage(language);
                temp->getGeneral()->setTimeZone(timeZone);

                //thêm đối tượng vào list
                per.push_back(temp);
            }
            settingInput.close();
        }
    }
    catch (int)
    {
        cerr << "File Setting.txt is empty!" << endl;
    }
    catch (const char* exception)
    {
        cout << exception << endl;
    }
    catch (...)
    {
    }
}
void Menu::writeFile() //ghi dữ liệu vào file Setting.txt
{
    ofstream settingOutput("Setting.txt");
    try
    {
        if (settingOutput.is_open())
        {
            for (size_t i = 0; i < per.size(); i++)
            {
                settingOutput << "Common: "
                    << per.at(i)->getName() << "," << per.at(i)->getEmail() << ","
                    << per.at(i)->getKeyNumber() << "," << per.at(i)->getOdoNumber() << ","
                    << per.at(i)->getRemindService() << " "
                    << "General: "
                    << per.at(i)->getGeneral()->getLanguage() << ","
                    << per.at(i)->getGeneral()->getTimeZone() << ";"
                    << "Sound: "
                    << per.at(i)->getSound()->getMedia() << ","
                    << per.at(i)->getSound()->getCall() << ","
                    << per.at(i)->getSound()->getNavigation() << ","
                    << per.at(i)->getSound()->getNotification() << ";"
                    << "Display: "
                    << per.at(i)->getDisplay()->getLightLevel() << ","
                    << per.at(i)->getDisplay()->getScreenLight() << ","
                    << per.at(i)->getDisplay()->getTaploLight() << "; " << endl;
            }
            settingOutput.close();
        }
        else
        {
            throw exception();
        }
    }
    catch (...)
    {
        cout << "Loi ghi file!" << endl;
    }

}
bool Menu::checkEmptyFile(ifstream& pFile) //Kiểm tra file có dữ liệu hay không
{
    if (pFile.peek() == ifstream::traits_type::eof())
    {
        return true;
    }
    else return false;
}