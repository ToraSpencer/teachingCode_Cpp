#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#define FILENAME "empFile.txt"
using namespace std;


// 管理系统
class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();

	void Show_Menu();		//显示菜单
	void ExitSystem();		//退出系统
	void Add_Emp();			//增加员工
	void save();					//保存员工
	void init_Emp();			//初始化员工
	void Show_Emp();		//显示员工
	void Del_Emp();			//删除员工
	int IsExist(int id);			//判断员工是否存在
	int get_EmpNum();		//文件存在，统计人数
	void Mod_Emp();			//修改职工
	void Find_Emp();			//查找职工
	void Sort_Emp();			//排序
	void Clean_File();			//清空文件



public:
	// 记录文件中的个数
	int m_EmpNum;

	// 职工数组的指针
	Worker ** m_EmpArray;

	// 判断文件是否为空
	bool m_FileIsEmpty;

};



