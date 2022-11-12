#include "Caidat.h"
using namespace std;

Caidat::Caidat()
{
    this->num = 0;
    this->car_num = 0;
    this->thongbao = 0;
    this->number = "";
}
Caidat::~Caidat()
{
    delete car;
    delete sound;
    delete general;
    delete display;
}

void Caidat::selectMenuFirst() //Lựa chọn menu chọn setting hay print
{
    string number;
    cout << "--- SELECT MENU ---" << endl
        << "1. Input setting information" << endl
        << "2. Print setting information" << endl
        << "0. Exit" << endl
        << "Your selection: ";
    do
    {  
        getline(cin, number);
        if (number == "1")
        {
            selectMenuSecond();

        }
        else if (number == "2")
        {
            selectMenuThird();
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
                    selectMenuFirst();
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
            cout << "--- SELECT MENU ---" << endl
                << "1. Input setting information" << endl
                << "2. Print setting information" << endl
                << "0. Exit" << endl
                << "Your selection: ";
        }
    } while (!(number == "1" || number == "2" || number == "0"));
}
void Caidat::selectMenuSecond() //menu setting
{
    if (car_num >= MAX_CAR)
    {
        cout << "LIST FULL" << endl;
        system("pause");
        system("cls");
        selectMenuFirst();
    }
    else
    {
        system("cls");
        cout << "--- SELECT MENU ---" << endl
            << "1. Display setting" << endl
            << "2. Sound setting" << endl
            << "3. Gerenal setting" << endl
            << "0. Exit" << endl
            << "Your selection: ";
        do
        {
            getline(cin, number);
            if (number == "1")
            {
                thongbao = 1;
                system("cls");
                cout << "--- Input Display setting ---" << endl;
                getInforCar();
                getInforDisplay();
                overrideDisplay(car[num], display[num]);
                question();
            }
            else if (number == "2")
            {
                thongbao = 2;
                system("cls");
                cout << "--- Input Sound setting ---" << endl;
                getInforCar();
                getInforSound();
                overrideSound(car[num], sound[num]);
                question();
            }
            else if (number == "3")
            {
                thongbao = 3;
                system("cls");
                cout << "--- Input General setting ---" << endl;
                getInforCar();
                getInforGeneral();
                overrideGeneral(car[num], general[num]);
                question();

            }
            else if (number == "0")
            {
                system("cls");
                selectMenuFirst();

            }
            else
            {
                cout << "Your selection is illegal !" << endl;
                cout << "Please selecting again" << endl;
                system("pause");
                system("cls");
                cout << "--- SELECT MENU ---" << endl
                    << "1. Display setting" << endl
                    << "2. Sound setting" << endl
                    << "3. Gerenal setting" << endl
                    << "0. Exit" << endl
                    << "Your selection: ";
            }
        } while (!(number == "1" || number == "2" || number == "3" || number == "0"));

    }
}
void Caidat::selectMenuThird() //menu print
{
    string number;
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
       
        if (number == "1")  //Hiển thị thông tin của Display
        {
            system("cls");          
            if (num == 0)//kiểm tra Display đã có dữ liệu hay chưa
            {
                //chưa có thì yêu cầu người dùng nhập dữ liệu
                cout << "My list has not Data" << endl;
                cout << "Please input Data!" << endl;
                selectMenuFirst();
            }
            else
            {
                //Nếu có thì xuất xuất thông tin 
                Menu5();
            }
        }
        else if (number == "2")
        {
            system("cls");         
            if (num == 0) //kiểm tra Sound đã có dữ liệu hay chưa
            {
                //chưa có thì yêu cầu người dùng nhập dữ liệu
                cout << "My list has not Data" << endl;
                cout << "Please input Data!" << endl;
                selectMenuFirst();
            }
            else
            {
                //Nếu có thì xuất xuất thông tin 
                Menu6();
            }
        }
        else if (number == "3")
        {
            system("cls");       
            if (num == 0)  //kiểm tra General đã có dữ liệu hay chưa
            {
                //chưa có thì yêu cầu người dùng nhập dữ liệu
                cout << "My list has not Data" << endl;
                cout << "Please input Data!" << endl;
                selectMenuFirst();
            }
            else
            {
                //Nếu có thì xuất xuất thông tin 
                Menu7();
            }

        }
        else if (number == "4")
        {
            system("cls");
            if (num == 0)
            {
                cout << "My list has not Data" << endl;
                cout << "Please input Data!" << endl;
                selectMenuFirst();
            }
            else 
            {
                Menu4();
            }

        }
        else if (number == "0")
        {
            system("cls");
            selectMenuFirst();
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

void Caidat::Menu4() //in full thông tin theo tên hoặc key
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
            sortOwerName();
            showAllSetting();
            system("pause");
            system("cls");
            selectMenuFirst();
        }
        else if (number == "2")
        {
            system("cls");
            sortKey();
            showAllSetting();
            system("pause");
            system("cls");
            selectMenuFirst();
        }
        else if (number == "0")
        {
            system("cls");
            selectMenuThird();
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
                << "0. Exit" << endl
                << "Your selection: ";
        }
    } while (!(number == "1" || number == "2" || number == "0"));


}
void Caidat::Menu5() //in thông tin Display theo tên , key
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
            sortOwerName();
            cout << endl;
            showInforDisplay();
            system("pause");
            system("cls");
            selectMenuFirst();
        }
        else if (number == "2")
        {
            system("cls");
            sortKey();
            showInforDisplay();
            system("pause");
            system("cls");
            selectMenuFirst();
        }
        else if (number == "0")
        {
            system("cls");
            selectMenuThird();
        }
        else
        {
            cout << "Your selection is illegal !" << endl;
            cout << "Please selecting again" << endl;
            system("pause");
            system("cls");
            cout << "--- SELECT MENU ---" << endl;
            cout << "1. Print Display setting by Name" << endl
                << "2. Print Display setting by KeyNumber" << endl
                << "0. Exit" << endl
                << "Your selection: ";
        }
    } while (!(number == "1" || number == "2" || number == "0"));

}
void Caidat::Menu6() //in thông tin Sound theo tên , key
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
            sortOwerName();
            showInforSound();
            system("pause");
            system("cls");
            selectMenuFirst();
        }
        else if (number == "2")
        {
            system("cls");
            sortKey();
            showInforSound();
            system("pause");
            system("cls");
            selectMenuFirst();
        }
        else if (number == "0")
        {
            system("cls");
            selectMenuThird();
        }
        else
        {
            cout << "Your selection is illegal !" << endl;
            cout << "Please selecting again" << endl;
            system("pause");
            system("cls");
            cout << "--- SELECT MENU ---" << endl;
            cout << "1. Print Sound setting by Name" << endl
                << "2. Print Sound setting by KeyNumber" << endl
                << "0. Exit" << endl
                << "Your selection: ";
        }
    } while (!(number == "1" || number == "2" || number == "0"));
}
void Caidat::Menu7() //in thông tin General theo tên , key
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
            sortOwerName();
            showInforGeneral();
            system("pause");
            system("cls");
            selectMenuFirst();
        }
        else if (number == "2")
        {
            system("cls");
            sortKey();
            showInforGeneral();
            system("pause");
            system("cls");
            selectMenuFirst();
        }
        else if (number == "0")
        {
            system("cls");
            selectMenuThird();
        }
        else
        {
            cout << "Your selection is illegal !" << endl;
            cout << "Please selecting again" << endl;
            system("pause");
            system("cls");
            cout << "--- SELECT MENU ---" << endl;
            cout << "1. Print General setting by Name" << endl
                << "2. Print General setting by KeyNumber" << endl
                << "0. Exit" << endl
                << "Your selection: ";
        }
    } while (!(number == "1" || number == "2" || number == "0"));
}

void Caidat::sossanhKeyNumber(CarInfor* CAR)
{
    int number = 0;
    if (num > 0)
    {
        for (size_t i = 0; i < num; i++)
        {
            //so sánh key nhập vào và key đã có sẵn trước đó
            if (CAR->getKeyNumber() == car[i]->getKeyNumber())
            {
                car_num--;
                number =1;
                break;
            }
        }
        if (number == 1)
        {
            cout << "      -> This car already existed, data will be overriten" << endl;
            //num--;
        }
        else
        {
            cout << "      ->This is a new car, data will be appended to your list" << endl;
        }
    }
}
void Caidat::question()
{
    if (car_num >= MAX_CAR)
    {
        cout << "LIST FULL!" << endl;
        num++;
        system("pause");
        system("cls");
        selectMenuFirst();
    }
    else
    {
        Caidat cd;
        string YN;
        cout << "Will you input for car " << " " << "(y/n)" << endl;
        do
        {
            getline(cin, YN);
            if (!cd.checkRegex(YN, "y|n|Y|N"))
            {
                cout << "Please enter y: YES or n:NO." << endl;
            }
        } while (!cd.checkRegex(YN, "y|n|Y|N"));
        if (YN == "y" || YN == "Y")
        {
            if (number == "1")
            {
                num++;
                getInforCar();
                getInforDisplay();
                overrideDisplay(car[num], display[num]);
                question();
            }
            else if (number == "2")
            {
                num++;
                getInforCar();
                getInforSound();
                overrideSound(car[num], sound[num]);
                question();
            }
            else if (number == "3")
            {
                num++;
                getInforCar();
                getInforGeneral();
                overrideGeneral(car[num], general[num]);
                question();
            }
        }
        else//trở về MH1 nếu người dùng chọn No.
        {
            num++;
            system("cls");
            selectMenuFirst();//return MH1
        }
    }
}
void Caidat::sortOwerName()
{
    if (num > 0) {
        for (size_t i = 0; i < num; i++)
        {
            for (size_t j = 0; j < num - i - 1; j++)
            {
                if (car[j]->getName().compare(car[j + 1]->getName()) == 1)
                {
                    swap(car[j], car[j + 1]);
                    swap(display[j], display[j + 1]);
                    swap(sound[j], sound[j + 1]);
                    swap(general[j], general[j + 1]);
                }
            }
        }
    }
}
void Caidat::sortKey()
{
    if (num > 0) {
        for (size_t i = 0; i < num; i++)
        {
            for (size_t j = 0; j < num - i - 1; j++)
            {
                if (stoi(car[j]->getKeyNumber()) - stoi(car[j + 1]->getKeyNumber()) > 0)
                {
                    swap(car[j], car[j + 1]);
                    swap(display[j], display[j + 1]);
                    swap(sound[j], sound[j + 1]);
                    swap(general[j], general[j + 1]);
                }
            }
        }
    }
}
void Caidat::thongBao()
{
    if (thongbao == 1) 
    {
        cout << "--- Input Display setting ---" << endl;
    }
    else if (thongbao == 2) 
    {
        cout << "--- Input Sound setting ---" << endl;
    }
    else if (thongbao == 3)
    {
        cout << "--- Input General setting ---" << endl;
    }
}

void Caidat::getInforCar()
{
    car_num++;
    string name, email, keyNumber, odoNumber, remindService;//kiểu dữ liệu các chế độ kiểu string
    CarInfor* c = new CarInfor();
    cout << "Car index: " << num + 1 << endl;
    c->nhapThongTin();
    //khởi tạo mặc định các giá trị general, sound, display
    display[num] = new Display();
    sound[num] = new Sound();
    general[num] = new General();
    
    sossanhKeyNumber(c); //so sánh keyNumber
    car[num] = c;
}
void Caidat::getInforDisplay()
{
    display[num]->nhapThongTin();
    
}
void Caidat::getInforSound()
{  
    sound[num]->nhapThongTin();
}
void Caidat::getInforGeneral()
{
    system("pause");
    system("cls"); 
    general[num]->nhapThongTin();
}

void Caidat::overrideDisplay(CarInfor* CAR, Display* DISPLAY)
{
    if (num > 0) {
        for (size_t i = 0; i < num; i++)
        {
            //Kiêm tra KeyNumber, nếu giống thì ghi đè dữ liệu 
            if (CAR->getKeyNumber() == car[i]->getKeyNumber())
            {
                //ghi đè dữ liệu thông tin xe
                car[i]->setName(CAR->getName());
                car[i]->setEmail(CAR->getEmail());
                car[i]->setKeyNumber(CAR->getKeyNumber());
                car[i]->setOdoNumber(CAR->getOdoNumber());
                car[i]->setRemindService(CAR->getRemindService());

                //ghi đè thông tin Display
                display[i]->setScreenLight(DISPLAY->getScreenLight());
                display[i]->setTaploLight(DISPLAY->getScreenLight());
                display[i]->setLightLevel(DISPLAY->getLightLevel());
                num--;
                break;
            }
        }      
    }
}
void Caidat::overrideSound(CarInfor* CAR, Sound* SOUND)
{
    if (num > 0) {
        for (size_t i = 0; i < num; i++)
        {
            if (CAR->getKeyNumber() == car[i]->getKeyNumber())
            {
                //ghi đè dữ liệu thông tin xe
                car[i]->setName(CAR->getName());
                car[i]->setEmail(CAR->getEmail());
                car[i]->setKeyNumber(CAR->getKeyNumber());
                car[i]->setOdoNumber(CAR->getOdoNumber());
                car[i]->setRemindService(CAR->getRemindService());

                //ghi đè thông tin Display
                sound[i]->setCall(SOUND->getCall());
                sound[i]->setMedia(SOUND->getMedia());
                sound[i]->setNavigation(SOUND->getNavigation());
                sound[i]->setNotification(SOUND->getNotification());
                num--;
                break;
            }
        }
    }
}
void Caidat::overrideGeneral(CarInfor* CAR, General* GENERAL)
{
    if (num > 0) {
        for (size_t i = 0; i < num; i++)
        {
            if (CAR->getKeyNumber() == car[i]->getKeyNumber())
            {
                //ghi đè dữ liệu thông tin xe
                car[i]->setName(CAR->getName());
                car[i]->setEmail(CAR->getEmail());
                car[i]->setKeyNumber(CAR->getKeyNumber());
                car[i]->setOdoNumber(CAR->getOdoNumber());
                car[i]->setRemindService(CAR->getRemindService());
                //ghi de General
                general[i]->setLanguage(GENERAL->getLanguage());
                general[i]->setTimeZone(GENERAL->getTimeZone());
                num--;
                break;
            }
        }
    }
}

void Caidat::showInforDisplay()
{  
    cout << "---DISPLAY SETTING---" << endl << endl;  
    for (size_t i = 0; i < num ; i++)
    {
        cout << "---Common " << i + 1 << ":" << endl;
        cout << setw(15) << "Ower name" << setw(20) << "Email" << setw(35) << "Key number" << setw(20)
            << "ODO number" << setw(30) << "Remind service (km)" << endl << endl;
        car[i]->xuatThongTin();

        cout << "---Display: " << endl;
        cout << setw(15) << "Light level" << setw(31) << "Screen Light level" << setw(29) << "Taplo light level" << endl << endl;
        display[i]->xuatThongTin();
        cout << "----------------------------------------------------------------------------------";
        cout << "--------------------------------------------------------------------------------------" << endl;
    }           
}
void Caidat::showInforSound()
{
    cout << "---SOUND SETTING---" << endl << endl;

    for (size_t i = 0; i < num; i++)
    {
        cout << "---Common " << i + 1 <<":" << endl;
        cout << setw(15) << "Ower name" << setw(20) << "Email" << setw(35) << "Key number" << setw(20)
            << "ODO number" << setw(30) << "Remind service (km)" << endl << endl;
        car[i]->xuatThongTin();
        cout << "---Sound: " << endl;
        cout << setw(15) << "Media" << setw(23) << "Call" << setw(36) << "Navigation" << setw(22) << "Notification" << endl << endl;
        sound[i]->xuatThongTin();
        cout << "----------------------------------------------------------------------------------";
        cout << "--------------------------------------------------------------------------------------" << endl;
    }
}
void Caidat::showInforGeneral()
{
    cout << "---GENERAL SETTING---" << endl;  
    for (size_t i = 0; i < num; i++)
    {
        cout << "---Common " << i + 1 << ":" << endl;
        cout << setw(15) << "Ower name" << setw(20) << "Email" << setw(35) << "Key number" << setw(20)
            << "ODO number" << setw(30) << "Remind service (km)" << endl << endl;
        car[i]->xuatThongTin();
        cout << "---General:" << endl;
        cout << setw(15) << "TimeZone" << setw(24) << "Language" << endl << endl;
        general[i]->xuatThongTin();
        cout << "----------------------------------------------------------------------------------";
        cout << "--------------------------------------------------------------------------------------" << endl;
    }
}
void Caidat::showAllSetting()
{
    cout << "---ALL SETTING---" << endl;
    for (size_t i = 0; i < num; i++)
    {
        //Thong tin xe
        cout << "---Common " << i + 1 << ":" << endl;
        cout << setw(15) << "Ower name" << setw(20) << "Email" << setw(35) << "Key number" << setw(20)
            << "ODO number" << setw(30) << "Remind service (km)" << endl << endl;
        car[i]->xuatThongTin();
        //Thong tin Display
        cout << "---Display: " << endl;
        cout << setw(15) << "Light level" << setw(31) << "Screen Light level" << setw(29) << "Taplo light level" << endl << endl;
        display[i]->xuatThongTin();
        //Thong tin Sound
        cout << "---Sound: " << endl;
        cout << setw(15) << "Media" << setw(23) << "Call" << setw(36) << "Navigation" << setw(22) << "Notification" << endl << endl;
        sound[i]->xuatThongTin();
        //Thong tin General
        cout << "---General:" << endl;
        cout << setw(15) << "TimeZone" << setw(24) << "Language" << endl << endl;
        general[i]->xuatThongTin();
        cout << "----------------------------------------------------------------------------------";
        cout << "--------------------------------------------------------------------------------------" << endl;
    }
}

