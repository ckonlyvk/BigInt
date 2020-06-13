#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <bitset>
#include"ProcessData.h"
using namespace std;

class QInt
{
private:
	int arrayBits[4];
public:
	//Hàm khởi tạo
	//QInt();

	//Input QInt từ một dãy nhị phân
	void Input(string StrBin);
	void Output();
	//QInt sang cac he khac de tinh toan 
	string QIntToBin();
	string QIntToDecimal();
	string QIntToHex();
	//Chuyển QInt hệ nhị phân sang hệ thập lục phân
	//string convertBinToHex(string StrBin);

	//Chuyển 4 bits sang hệ thập lục phân
	//char convertBin4bitsToHex(string subStr);

	//Chuyển QInt hệ thập lục phân sang hệ nhị phân
	string convertHexToBin(string StrHex);

	//Dịch phải
	string shiftRight(string StrBin, int SoBitDich);

	//Dịch trái
	string shiftLeft(string StrBin, int SoBitDich);

	//Dùng trong phép nhân.
	string DiChuyenSangTrai(string StrBin, int SoBitDich);

	//string multiplyQInt(string SrtBin, string StrBin);
	//string multiplyQInt(QInt other);

    int *CreateNewArrange(int *x,int count);

    string BU2(string s);

    string ConvertToDecimal();

	QInt operator+ ( QInt a);

	QInt operator-(QInt a);

    QInt operator&(QInt x);

    QInt operator|(QInt x);

    QInt operator^(QInt x);

    QInt operator~();

	QInt ROL();

    QInt ROR();

    bool check(string s1, string s2);
	string Check_0_in_head(string s);
	QInt operator/(QInt x);

};

