#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;
class Colors{
	//������(.h)��Ա���������ܶ����ʱ���ʼ������Ҫ�ڹ��캯���г�ʼ��
public:
	Colors(){
		groundbrown[0] = 115;
		groundbrown[1] = 74;
		groundbrown[2] = 18;
	};
	~Colors(){};
public:
	int groundbrown[3];
};