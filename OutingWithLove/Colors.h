#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;
class Colors{
	//在类中(.h)成员变量，不能定义的时候初始化，需要在构造函数中初始化
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