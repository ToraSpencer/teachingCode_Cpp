#pragma once
#include<iostream>
using namespace std;
#include<string>


// 顶层基类，抽象类——职工类
class Worker 
{
public:
	// 显示个人信息
	virtual void showInfo() = 0;

	// 获取岗位名称
	virtual string getDeptName() = 0;

	int m_id;								//职工编号
	string m_Name;					//职工姓名
	int m_DeptId;						//部门编号

};
