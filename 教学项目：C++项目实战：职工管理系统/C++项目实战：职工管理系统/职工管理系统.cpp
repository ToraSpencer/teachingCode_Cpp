#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"

//void test() {
//	Worker *worker = NULL;
//	worker = new Employee(1, "����", 1);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(2, "����", 2);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(3, "����", 3);
//	worker->showInfo();
//	delete worker;
//}

int main() {
	//test();

	// ���ɹ���ϵͳ����
	WorkerManager wm;

	// ѡ����
	int select = 0;
	
	// ���˵�ѭ��
	while (1) {
		wm.Show_Menu();
		cout << "��������ѡ��" << endl;
		cin >> select;

		// ���������Ӧ
		switch (select)
		{
		case 0:			//�˳�
			wm.ExitSystem();
			break;
		
		case 1:			//����
			wm.Add_Emp();
			break;
		
		case 2:			//��ʾ
			wm.Show_Emp();
			break;
		
		case 3://ɾ��
			wm.Del_Emp();
			break;
		
		case 4://�޸�
			wm.Mod_Emp();
			break;
		
		case 5://����
			wm.Find_Emp();
			break;
		
		case 6://����
			wm.Sort_Emp();
			break;
		
		case 7://���
			wm.Clean_File();
			break;
		
		default:
			system("pause");
			break;
		}
	}

	system("pause");

	return 0;
}