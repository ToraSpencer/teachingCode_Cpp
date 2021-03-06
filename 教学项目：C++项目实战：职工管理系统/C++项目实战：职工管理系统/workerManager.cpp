#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"worker.h"


// 构造函数
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	
	//文件存在，没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空！" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	
	//文件存在有记录，更新人数
	int num = this->get_EmpNum();
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker *[this->m_EmpNum];

	//将文件中的数据存到数组中
	init_Emp();
	
}



// 析构函数
WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
	}
}


// 显示菜单：
void WorkerManager::Show_Menu() {
	cout << "*********************************" << endl;
	cout << "************欢迎使用!************" << endl;
	cout << "*********0.退出管理系统**********" << endl;
	cout << "*********1.增加职工信息**********" << endl;
	cout << "*********2.显示职工信息**********" << endl;
	cout << "*********3.删除离职员工**********" << endl;
	cout << "*********4.修改职工信息**********" << endl;
	cout << "*********5.查找职工信息**********" << endl;
	cout << "*********6.按照编号排序**********" << endl;
	cout << "*********7.清空所有文档**********" << endl;
	cout << "*********************************" << endl;
	cout << endl;
}


 // 退出系统
void WorkerManager::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}


// 保存员工
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);		//用输出的方式打开文件 -- 写文件

	// 将每个数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}



void WorkerManager::Add_Emp() {
	cout << "请输入增加员工数量：" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;

		// 开辟新空间
		Worker ** newSpace = new Worker*[newSize];

		// 将原空间内容放到新空间
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		// 添加新的数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			
			cout << "请输入第" << i + 1 << "职工编号" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "职工姓名" << endl;
			cin >> name;

			cout << "请选择职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更新新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的个数
		this->m_EmpNum = newSize;

		//将文件为空改为假
		this->m_FileIsEmpty = false;

		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;

		//保存数据到文件中
		this->save();
	}
	else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}



// 文件存在且有数据，获取员工个数
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	ifs.close();

	return num;
}


// 初始化员工
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) 
	{
		Worker * worker = NULL;

		//根据不同部门ID创建不同对象
		if (dId == 1) 
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else 
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
}



void WorkerManager::Show_Emp() {

	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_id == id) {
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入想删除的员工号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1) {
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();
			cout << "删除成功！" << endl;
		}
		else{
			cout << "删除失败，未找到该职工" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);

		if (ret != -1) {
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int newSelect = 0;

			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;

			cout << "请输入新姓名：" << endl;
			cin >> newName;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> newSelect;

			Worker *worker = NULL;

			switch (newSelect)
			{
			case 1:
				worker = new Employee(newId, newName, newSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, newSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, newSelect);
				break;
			default:
				break;
			}

			//更改数据写入数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else 
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}




void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入查找方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) {
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1) {
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++) {
				if (m_EmpArray[i]->m_Name == name) {
					cout << "查找成功，职工编号为："
						<< m_EmpArray[i]->m_id
						<< "号的信息如下：" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) {
				cout << "查找失败，查无此人" << endl;
			}
		}
		else {
			cout << "输入选项有误" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工好进行升序" << endl;
		cout << "2.按职工进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++) {
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++) {
				//升序
				if (select == 1) {
					if (m_EmpArray[minOrMax]->m_id > m_EmpArray[j]->m_id) {
						minOrMax = j;
					}
				}
				//降序
				else {
					if (m_EmpArray[minOrMax]->m_id < m_EmpArray[j]->m_id) {
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax) {
				Worker *temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功，排序后结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
	system("pause");
	system("cls");
}



void WorkerManager::Clean_File() {
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		//ios::trunc如果存在则删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}
