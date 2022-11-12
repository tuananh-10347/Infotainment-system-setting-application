#include "btree.h"
//------------------------------------------------class btreee-------------------------------------------------------

btree::btree()
{
	this->num = 0;

}
btree::~btree()
{
}
int btree::getSize()
{
	a = 1; //số xe bắt đầu hiển thị ở xuất thông tin (Common 1:,....)
	ghifile = 0;//theo dõi để cập nhật file Setting.txt
	return num;
}

void btree::insertNode(node*& pNode, Setting* key, int bien) // biến: lựa chọn nhập cây MSCN hoặc cây Name
{
	if (pNode == NULL)
	{
		pNode = new node();
		pNode->data = key;
		pNode->left = NULL;
		pNode->right = NULL;
		if (bien == 1) { num++; };
	}
	else
	{
		switch (bien)
		{
		case 1://thêm node vài cây MSCN
			if (stoi(key->getKeyNumber()) < stoi(pNode->data->getKeyNumber())) //THÊM NODE KEY VÀO BÊN TRÁI			
			{
				insertNode(pNode->left, key, bien);
			}
			else if (stoi(key->getKeyNumber()) > stoi(pNode->data->getKeyNumber()))//THÊM NODE KEY VÀO BÊN PHẢI
			{
				insertNode(pNode->right, key, bien);
			}
			theodoi = 0;
			break;
		case 2://thêm node vào cây NAME
			if (stoi(key->getKeyNumber()) != stoi(pNode->data->getKeyNumber()))
			{
				if (key->getName().compare(pNode->data->getName()) == -1)
				{
					insertNode(pNode->left, key, bien); //THÊM NODE MSCN VÀO  BÊN TRÁI CÂY NAME
				}
				else if (key->getName().compare(pNode->data->getName()) >= 0)
				{
					insertNode(pNode->right, key, bien); //THÊM NODE CÂY MSCN VÀO BÊN PHẢI NAME
				}
			}
			break;
		}
	}
}
bool btree::findNode(node*& pNode, Setting* key) //đưa ra thông báo xe đã tồn tại hay chưa
{
	if (pNode != NULL)
	{

		if (stoi(pNode->data->getKeyNumber()) > stoi(key->getKeyNumber()))
		{
			findNode(pNode->left, key);
		}
		else if (stoi(pNode->data->getKeyNumber()) < stoi(key->getKeyNumber()))
		{
			findNode(pNode->right, key);
		}
		else
		{
			theodoi++;
		}
	}
	if (theodoi == 0)
	{
		return true; //xe chưa tồn tại
	}
	else
	{
		return false;
	}
}
void btree::replaceNode(node*& pNode, Setting* key, int thongbao, int bien) // biến: lựa chọn tìm kiếm cây MSCN hoặc cây Name
{
	if (pNode != NULL)
	{
		switch (bien)
		{
		case 1:
			if (stoi(pNode->data->getKeyNumber()) > stoi(key->getKeyNumber())) //duyệt sang trái để thêm key vào cây
			{
				replaceNode(pNode->left, key, thongbao, bien);
			}
			else if (stoi(pNode->data->getKeyNumber()) < stoi(key->getKeyNumber())) // duyệt sang phải để thêm key vào cây
			{
				replaceNode(pNode->right, key, thongbao, bien);
			}
			else
			{
				thaytheData(pNode, key, thongbao); //thay thế key trùng
				return;
			}
			break;
		case 2:
			if (key->getName().compare(pNode->data->getName()) == -1) // duyệt sang trái để thêm MSCN vào cây MSCN
			{
				if (key->getKeyNumber() == pNode->data->getKeyNumber())
				{
					thaytheData(pNode, key, thongbao);//thay thế key trùng
					return;
				}
				replaceNode(pNode->left, key, thongbao, bien);
			}
			else if (key->getName().compare(pNode->data->getName()) >= 0) //duyệt sang phải để thêm MSCN vào cây MSCN
			{
				if (key->getKeyNumber() == pNode->data->getKeyNumber())
				{
					thaytheData(pNode, key, thongbao);//thay thế key trùng
					return;
				}
				replaceNode(pNode->right, key, thongbao, bien);
			}
			break;
		}
	}
}

void btree::thaytheData(node*& pNode, Setting* name, int thongbao)
{
	pNode->data->setName(name->getName());
	pNode->data->setEmail(name->getEmail());
	pNode->data->setOdoNumber(name->getOdoNumber());
	pNode->data->setRemindService(name->getRemindService());
	switch (thongbao)
	{
	case 1:
		//Kiểm tra KeyNumber, thiết lập lại thông tin
		pNode->data->getDisplay()->setLightLevel(name->getDisplay()->getLightLevel());
		pNode->data->getDisplay()->setTaploLight(name->getDisplay()->getTaploLight());
		pNode->data->getDisplay()->setScreenLight(name->getDisplay()->getScreenLight());
		break;
	case 2:
		//Kiểm tra KeyNumber, thiết lập lại thông tin
		pNode->data->getSound()->setMedia(name->getSound()->getMedia());
		pNode->data->getSound()->setCall(name->getSound()->getCall());
		pNode->data->getSound()->setNavigation(name->getSound()->getNavigation());
		pNode->data->getSound()->setNotification(name->getSound()->getNotification());
		break;
	case 3:
		//Kiểm tra KeyNumber, thiết lập lại thông tin
		pNode->data->getGeneral()->setLanguage(name->getGeneral()->getLanguage());
		pNode->data->getGeneral()->setTimeZone(name->getGeneral()->getTimeZone());
		break;
	}
}

void btree::inforDisplay(node*& pNode)
{
	cout << setw(15) << "Ower name" << setw(20) << "Email" << setw(35) << "Key number" << setw(20)
		<< "ODO number" << setw(30) << "Remind service (km)" << endl << endl;
	pNode->data->xuatThongTin();
	cout << "---Display: " << endl;
	cout << setw(15) << "Light level" << setw(31) << "Screen Light level" << setw(29) << "Taplo light level" << endl;
	pNode->data->getDisplay()->xuatThongTin();
	cout << "----------------------------------------------------------------------------------";
	cout << "--------------------------------------------------------------------------------------" << endl;

}
void btree::inforSound(node*& pNode)
{
	cout << setw(15) << "Ower name" << setw(20) << "Email" << setw(35) << "Key number" << setw(20)
		<< "ODO number" << setw(30) << "Remind service (km)" << endl;
	pNode->data->xuatThongTin();
	cout << "---Sound: " << endl;
	cout << setw(15) << "Media" << setw(23) << "Call" << setw(36) << "Navigation" << setw(22) << "Notification" << endl;
	pNode->data->getSound()->xuatThongTin();
	cout << "----------------------------------------------------------------------------------";
	cout << "--------------------------------------------------------------------------------------" << endl;

}
void btree::inforGeneral(node*& pNode)
{
	cout << setw(15) << "Ower name" << setw(20) << "Email" << setw(35) << "Key number" << setw(20)
		<< "ODO number" << setw(30) << "Remind service (km)" << endl;
	pNode->data->xuatThongTin();
	cout << "---General:" << endl;
	cout << setw(15) << "TimeZone" << setw(24) << "Language" << endl;
	pNode->data->getGeneral()->xuatThongTin();
	cout << "----------------------------------------------------------------------------------";
	cout << "--------------------------------------------------------------------------------------" << endl;

}
void btree::inforAll(node*& pNode)
{
	cout << setw(15) << "Ower name" << setw(20) << "Email" << setw(35) << "Key number" << setw(20)
		<< "ODO number" << setw(30) << "Remind service (km)" << endl;
	pNode->data->xuatThongTin();
	cout << "---Display: " << endl;
	cout << setw(15) << "Light level" << setw(31) << "Screen Light level" << setw(29) << "Taplo light level" << endl;
	pNode->data->getDisplay()->xuatThongTin();
	cout << "---Sound: " << endl;
	cout << setw(15) << "Media" << setw(23) << "Call" << setw(36) << "Navigation" << setw(22) << "Notification" << endl;
	pNode->data->getSound()->xuatThongTin();
	cout << "---General:" << endl;
	cout << setw(15) << "TimeZone" << setw(24) << "Language" << endl;
	pNode->data->getGeneral()->xuatThongTin();
	cout << "----------------------------------------------------------------------------------";
	cout << "--------------------------------------------------------------------------------------" << endl;
}

void btree::sortNode(node*& pNode, int index)
{
	if (pNode != NULL)
	{
		sortNode(pNode->left, index);
		cout << "---Common " << a << ":" << endl;
		a++;
		switch (index)
		{
		case 1:
			inforDisplay(pNode);
			break;
		case 2:
			inforSound(pNode);
			break;
		case 3:
			inforGeneral(pNode);
			break;
		case 4:
			inforAll(pNode);
			break;
		}
		sortNode(pNode->right, index);
	}
}
void btree::writeFile(node*& pNode) //ghi dữ liệu vào file Setting.txt
{
	if (ghifile == 0) /*Mỗi lần thêm 1 phần tử mới hàm này sẽ cập nhật lại file 1 lần và dòng 257 sẽ ghi tiếp vào đuôi của file */
	{
		ofstream settingOutput("Setting.txt", ios::trunc);
		try {
			if (settingOutput.is_open())
			{
				settingOutput << "";
			}
			settingOutput.close();
		}
		catch (...)
		{
			cerr << "Loi ghi file!" << endl;
		}
	}
	ofstream settingOutput("Setting.txt", ios::app); // thêm dữ liệu vào file theo ios::app
	try
	{
		if (settingOutput.is_open())
		{
			if (pNode != NULL)
			{
				settingOutput << "Common: "
					<< pNode->data->getName() << "," << pNode->data->getEmail() << ","
					<< pNode->data->getKeyNumber() << "," << pNode->data->getOdoNumber() << ","
					<< pNode->data->getRemindService() << " "
					<< "General: "
					<< pNode->data->getGeneral()->getLanguage() << ","
					<< pNode->data->getGeneral()->getTimeZone() << ";"
					<< "Sound: "
					<< pNode->data->getSound()->getMedia() << ","
					<< pNode->data->getSound()->getCall() << ","
					<< pNode->data->getSound()->getNavigation() << ","
					<< pNode->data->getSound()->getNotification() << ";"
					<< "Display: "
					<< pNode->data->getDisplay()->getLightLevel() << ","
					<< pNode->data->getDisplay()->getScreenLight() << ","
					<< pNode->data->getDisplay()->getTaploLight() << "; " << endl;
				ghifile = 1; //theo dõi việc ghi file		
				writeFile(pNode->left);
				writeFile(pNode->right);
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
void btree::deletebtree(node*& pNode)
{
	if (pNode != NULL)
	{
		deletebtree(pNode->left);
		deletebtree(pNode->right);
		delete pNode;
	}
}