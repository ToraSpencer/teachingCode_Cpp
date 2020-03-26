#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#define FILENAME "empFile.txt"
using namespace std;


// ����ϵͳ
class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();

	void Show_Menu();		//��ʾ�˵�
	void ExitSystem();		//�˳�ϵͳ
	void Add_Emp();			//����Ա��
	void save();					//����Ա��
	void init_Emp();			//��ʼ��Ա��
	void Show_Emp();		//��ʾԱ��
	void Del_Emp();			//ɾ��Ա��
	int IsExist(int id);			//�ж�Ա���Ƿ����
	int get_EmpNum();		//�ļ����ڣ�ͳ������
	void Mod_Emp();			//�޸�ְ��
	void Find_Emp();			//����ְ��
	void Sort_Emp();			//����
	void Clean_File();			//����ļ�



public:
	// ��¼�ļ��еĸ���
	int m_EmpNum;

	// ְ�������ָ��
	Worker ** m_EmpArray;

	// �ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

};



