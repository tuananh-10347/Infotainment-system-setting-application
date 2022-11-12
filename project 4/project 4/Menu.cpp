#include "Menu.h"

using namespace std;

Menu::Menu()
{
    pNodeKey = NULL;
    pNodeName = NULL;
    thongbao = 0;
    number = "";
    check = 0;
}
Menu::~Menu()
{
    if (pNodeKey != NULL)
    {
        per.deletebtree(pNodeKey);

    }
    if (pNodeName != NULL)
    {
        per.deletebtree(pNodeName);
    }
}

void Menu::showMenu1()//hiển thị thông tin menu và cài đặt menu
{
    cout << "--- SELECT MENU ---" << endl
        << "1. Input setting information" << endl
        << "2. Print setting information" << endl
        << "0. Exit" << endl
        << "Your selection: ";
}
void Menu::Menu1() //Menu lựa chọn nhập thông tin hoặc xuất thông tin
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

void Menu::showMenu2() //hiển thị thông tin menu và cài đặt menu
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
            cout << "Car index: " << per.getSize() + 1 << endl;
            Setting* temp = new Setting;
            temp->nhapThongTin();
            exist(temp); //Đưa ra thông báo xe đã tgồn tại hay chưa
            temp->getDisplay()->nhapThongTin();//Nhập thông tin chủ xe 

            per.replaceNode(pNodeKey, temp, thongbao, 1);//so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế - theo Key
            per.replaceNode(pNodeName, temp, thongbao, 2);//so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế - theo Name

            per.insertNode(pNodeKey, temp, 1);//thêm temp vào cây MSCN
            per.insertNode(pNodeName, temp, 2);//thêm temp vào cây teen


            writeFile();
            question(); //cài đặt xe tiếp theo
        }
        else if (number == "2")
        {
            Setting* temp = new Setting;
            thongbao = 2;
            system("cls");
            cout << "--- Input Sound setting ---" << endl;
            cout << "Car index: " << per.getSize() + 1 << endl;
            temp->nhapThongTin();
            exist(temp);
            temp->getSound()->nhapThongTin();//Nhập thông tin chủ xe 

            per.replaceNode(pNodeKey, temp, thongbao, 1);//so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế - theo Key
            per.replaceNode(pNodeName, temp, thongbao, 2);//so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế - theo Name

            per.insertNode(pNodeKey, temp, 1);//thêm temp vào cây MSCN
            per.insertNode(pNodeName, temp, 2);//thêm temp vào cây teen
            //per.insertNodeName(pNodeName, temp,2); // thêm name vào cây tên

            writeFile();// GHI FILE
            question();//cài đặt xe tiếp theo
        }
        else if (number == "3")
        {
            Setting* temp = new Setting;
            thongbao = 3;
            system("cls");
            cout << "--- Input General setting ---" << endl;
            cout << "Car index: " << per.getSize() + 1 << endl;
            temp->nhapThongTin();
            exist(temp);//đưa ra thông báo xe đã tồn tại hay chưa
            system("pause");
            system("cls");
            temp->getGeneral()->nhapThongTin();//Nhập thông tin chủ xe 

            per.replaceNode(pNodeKey, temp, thongbao, 1);//so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế - theo Key
            per.replaceNode(pNodeName, temp, thongbao, 2);//so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế - theo Name

            per.insertNode(pNodeKey, temp, 1);//thêm temp vào cây MSCN
            per.insertNode(pNodeName, temp, 2);//thêm temp vào cây teen
            //per.insertNodeName(pNodeName, temp,2); // thêm name vào cây tên

            writeFile();// GHI FILE
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
            if (per.getSize() == 0) //kiểm tra Display đã có dữ liệu hay chưa
            {
                cout << "My list has not Data" << endl;//chưa có thì yêu cầu người dùng nhập dữ liệu
                cout << "Please input Data!" << endl;
                Menu1();
            }
            else
            {
                per.getSize();//tạo mới giá trị của a: số xe xuất ra
                int index = 1;
                xuatThongTin("Display", index); //xuất thông tin Display
                Menu1();
            }
        }
        else if (number == "2")
        {
            system("cls");
            if (per.getSize() == 0) //kiểm tra Sound đã có dữ liệu hay chưa
            {
                cout << "My list has not Data" << endl;  //chưa có thì yêu cầu người dùng nhập dữ liệu
                cout << "Please input Data!" << endl;
                Menu1();
            }
            else
            {
                per.getSize();//tạo mới giá trị của a: số xe xuất ra
                int index = 2;
                xuatThongTin("Sound", index);//xuất thông tin Sound  
                Menu1();
            }
        }
        else if (number == "3")
        {
            system("cls");
            if (per.getSize() == 0)  //kiểm tra General đã có dữ liệu hay chưa
            {
                cout << "My list has not Data" << endl;//chưa có thì yêu cầu người dùng nhập dữ liệu
                cout << "Please input Data!" << endl;
                Menu1();
            }
            else
            {
                per.getSize();//tạo mới giá trị của a: số xe xuất ra
                int index = 3;
                xuatThongTin("General", index);// xuất thông tin General   
                Menu1();
            }
        }
        else if (number == "4")
        {
            system("cls");
            if (per.getSize() == 0)
            {
                cout << "My list has not Data" << endl;
                cout << "Please input Data!" << endl;
                Menu1();
            }
            else
            {
                per.getSize();//tạo mới giá trị của a: số xe xuất ra
                int index = 4;
                xuatThongTin("all", index);//xuất all thông tin
                Menu1();
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
void Menu::xuatThongTin(string f, int index)
{
    cout << "--- SELECT MENU ---" << endl;
    cout << "1. Print " << f << " setting by Name" << endl
        << "2. Print " << f << " setting by KeyNumber" << endl
        << "0. Exit" << endl
        << "Your selection: ";
    do
    {
        getline(cin, number);
        if (number == "1")
        {
            per.getSize();//tạo mới giá trị của a: số xe xuất ra
            system("cls");
            per.sortNode(pNodeName, index);//Duyệt theo tên
            system("pause");
            system("cls");
        }
        else if (number == "2")
        {
            per.getSize();//tạo mới giá trị của a: số xe xuất ra
            system("cls");
            per.sortNode(pNodeKey, index); //Duyệt theo key
            system("pause");
            system("cls");
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
            cout << "1. Print " << f << " setting by Name" << endl
                << "2. Print " << f << " setting by KeyNumber" << endl
                << "0. Exit" << endl
                << "Your selection: ";
        }
    } while (!(number == "1" || number == "2" || number == "0"));
}
void Menu::exist(Setting* temp)
{
    if (per.getSize() != 0) //Thông báo xe đã tồn tại hay chưa
    {
        if (per.findNode(pNodeKey, temp))
        {
            cout << "      ->This is a new car, data will be appended to your list" << endl;
        }
        else
        {
            cout << "      -> This car already existed, data will be overriten" << endl;
        }
    }

}
void Menu::question() //mục đích của hàm: hỏi người dùng có tiếp tục nhập thông tin cho xe
{
    system("pause");
    system("cls");
    string YN; //YES OR NO
    cout << "Will you input for car " << per.getSize() + 1 << " " << "(y/n)" << endl;
    YN = d.checkDataString("y|n|Y|N");
    if (YN == "y" || YN == "Y")
    {
        if (number == "1")
        {
            Setting* temp = new Setting;
            cout << "Car index: " << per.getSize() + 1 << endl;
            temp->nhapThongTin();
            exist(temp);//đưa ra thông báo xe đã tồn tại hay chưa
            temp->getDisplay()->nhapThongTin();//Cài đặt cho xe tiếp theo

            per.replaceNode(pNodeKey, temp, thongbao, 1);//so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế - theo Key
            per.replaceNode(pNodeName, temp, thongbao, 2);//so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế - theo Name

            per.insertNode(pNodeKey, temp, 1);//thêm temp vào cây MSCN
            per.insertNode(pNodeName, temp, 2);//thêm temp vào cây teen
            //per.insertNodeName(pNodeName, temp,2); // thêm name vào cây tên

            writeFile();// GHI FILE
            question();//Cài đặt cho xe tiếp theo
        }
        else if (number == "2")
        {
            Setting* temp = new Setting;
            cout << "Car index: " << per.getSize() + 1 << endl;
            temp->nhapThongTin();
            exist(temp);
            temp->getSound()->nhapThongTin();

            per.replaceNode(pNodeKey, temp, thongbao, 1);//so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế - theo Key
            per.replaceNode(pNodeName, temp, thongbao, 2);//so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế - theo Name

            per.insertNode(pNodeKey, temp, 1);//thêm temp vào cây MSCN
            per.insertNode(pNodeName, temp, 2);//thêm temp vào cây teen
            //per.insertNodeName(pNodeName, temp,2); // thêm name vào cây tên

            writeFile();// GHI FILE
            question();//Cài đặt cho xe tiếp theo
        }
        else if (number == "3")
        {
            Setting* temp = new Setting;
            cout << "Car index: " << per.getSize() + 1 << endl;
            temp->nhapThongTin();
            exist(temp);
            system("pause");
            system("cls");
            temp->getGeneral()->nhapThongTin();

            per.replaceNode(pNodeKey, temp, thongbao, 1);//so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế - theo Key
            per.replaceNode(pNodeName, temp, thongbao, 2);//so sánh để biết rằng xe đã tồn tại hay chưa, nếu tồn tịa thì thay thế - theo Name

            per.insertNode(pNodeKey, temp, 1);//thêm temp vào cây MSCN
            per.insertNode(pNodeName, temp, 2);//thêm temp vào cây teen
            //per.insertNodeName(pNodeName, temp,2); // thêm name vào cây tên
            writeFile();// GHI FILE
            question(); //Cài đặt cho xe tiếp theo
        }
    }
    else
    {
        system("cls");
        Menu1();  //return MH1
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
                per.insertNode(pNodeKey, temp, 1);//thêm temp vào cây MSCN
                per.insertNode(pNodeName, temp, 2);//thêm temp vào cây teen
                //per.insertNodeName(pNodeName, temp,2); // thêm name vào cây tên
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
void Menu::writeFile()
{
    per.getSize();
    per.writeFile(pNodeKey);
}
bool Menu::checkEmptyFile(ifstream& pFile) //Kiểm tra file có dữ liệu hay không
{
    if (pFile.peek() == ifstream::traits_type::eof())
    {
        return true;
    }
    else return false;
}