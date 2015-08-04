#include "stdafx.h"
#include "ColorUtil.h"
#include <iostream>
#include <float.h>
using namespace std;

float ColorUtil::rgbIntToFloat(int n){
	return (1 / (float)255)*(float)n;
}