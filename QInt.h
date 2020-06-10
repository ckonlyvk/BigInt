#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <bitset>
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
	string shiftRight(string StrBin, int SoBitDich);

	//Dịch trái
	string shiftLeft(string StrBin, int SoBitDich);

	//Dùng trong phép nhân.
	string DiChuyenSangTrai(string StrBin, int SoBitDich);

	string multiplyQInt(string SrtBin, string StrBin);

    int *CreateNewArrange(int *x,int count);

    string Check_0_in_head(string s);

    string BU2(string s);

    string ConvertToDecimal(string s);

    string cong(string a, string b);

    string AND(string s1, string s2);

    string OR(string s1, string s2);

    string XOR(string s1, string s2);

    string NOT(string s);

    string ROL(string s);

    string ROR(string s);

    bool check(string s1, string s2);

    string chia(string s1, string s2);
};

