#pragma once
#include <iostream>
#include <string>
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

	//Dịch phải
	//friend QInt operator>>(QInt &a, int SoBitDichPhai);

	//Dịch phải
	string shiftRight(string StrBin, int SoBitDich);

	//Dịch trái
	string shiftLeft(string StrBin, int SoBitDich);

	//Dùng trong phép nhân.
	string DiChuyenSangTrai(string StrBin, int SoBitDich);

	string multiplyQInt(string SrtBin, string StrBin);

	//QInt& operator+(const QInt &a);

	string cong(string a, string b);
};

