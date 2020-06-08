#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class QInt
{
private:
	int arrayBits[4];
public:
	//Chuyển QInt hệ nhị phân sang hệ thập lục phân
	string convertBinToHex(string StrBin);

	//Chuyển 4 bits sang hệ thập lục phân
	char convertBin4bitsToHex(string subStr);

	//Chuyển QInt hệ thập lục phân sang hệ nhị phân
	string convertHexToBin(string StrHex);
};

