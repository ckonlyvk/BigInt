#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <bitset>
#include "ProcessData.h"
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

    int *CreateNewArrange(int *x,int count);

    string Check_0_in_head(string s);

    bool check(string s1, string s2);

	//Cac ham operator toan tu
	QInt operator=(QInt a);//Phep gan 
	
	void operator>> (int SoBitDich);//Phep dich phai 

	void operator<<(int SoBitDich);//Phep dich trai

	QInt operator*(QInt qint);//Phep nhan

	QInt operator+(QInt a);//Phep cong

	QInt operator&(QInt x);//Phep and

	QInt operator|(QInt x);//Phep or

	QInt operator^(QInt x);//Phep xor

	QInt operator~();//Phep not

	QInt operator-(QInt a);//Phep tru

	QInt operator/(QInt x);//Phep chia

	QInt ROL();//Quay trai

	QInt ROR();//Quay phai
};