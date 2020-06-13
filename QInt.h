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
QInt();

	//Input QInt từ một dãy nhị phân
	void Input(string StrBin);
	void Output();
	//QInt sang cac he khac de tinh toan 
	string QIntToBin();
	string QIntToDecimal();
	string QIntToHex();
	//Chuyển QInt hệ nhị phân sang hệ thập lục phân
	string convertBinToHex();

	//Chuyển 4 bits sang hệ thập lục phân
	char convertBin4bitsToHex(string subStr);

	//Chuyển QInt hệ thập lục phân sang hệ nhị phân
	string convertHexToBin();

    int *CreateNewArrange(int *x,int count);

    string Check_0_in_head(string s);

    string BU2(string s);

    string ConvertToDecimal();

    bool check(string s1, string s2);

	QInt operator=(QInt a);
	
	void operator>> (int SoBitDich);

	void operator<<(int SoBitDich);

	QInt operator*(QInt qint);

	QInt operator+(QInt a);

	QInt operator&(QInt x);

	QInt operator|(QInt x);

	QInt operator^(QInt x);

	QInt operator~();

	QInt operator-(QInt a);

	QInt ROL();

	QInt ROR();

	QInt operator/(QInt x);
};