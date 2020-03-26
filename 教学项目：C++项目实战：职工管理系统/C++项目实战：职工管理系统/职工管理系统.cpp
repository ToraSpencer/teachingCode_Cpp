#include<iostream>
using namespace std;
#include"workerManager.h"
#include"worker.h"
#include"boss.h"
#include"employee.h"
#include"manager.h"

//void test() {
//	Worker *worker = NULL;
//	worker = new Employee(1, "张三", 1);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Manager(2, "李四", 2);
//	worker->showInfo();
//	delete worker;
//
//	worker = new Boss(3, "王五", 3);
//	worker->showInfo();
//	delete worker;
//}

int main() {
	//test();

	// 生成管理系统对象
	WorkerManager wm;

	// 选择功能
	int select = 0;
	
	// 主菜单循环
	while (1) {
		wm.Show_Menu();
		cout << "输入您的选择：" << endl;
		cin >> select;

		// 对输入的响应
		switch (select)
		{
		case 0:			//退出
			wm.ExitSystem();
			break;
		
		case 1:			//增加
			wm.Add_Emp();
			break;
		
		case 2:			//显示
			wm.Show_Emp();
			break;
		
		case 3://删除
			wm.Del_Emp();
			break;
		
		case 4://修改
			wm.Mod_Emp();
			break;
		
		case 5://查找
			wm.Find_Emp();
			break;
		
		case 6://排序
			wm.Sort_Emp();
			break;
		
		case 7://清空
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