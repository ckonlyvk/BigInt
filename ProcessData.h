#pragma once
#include<iostream>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<vector>
#include "QInt.h"

using namespace std;

int *CreateNewArrange(int *x,int count);//Tạo 1 mang dong
bool check(string s1, string s2);// So sanh 2 chuoi

// Xu ly so
string Divide2(string s);// Chuoi so he 10 chia 2  
string IntToStr(int num);// Chuyen doi so nguyen thanh 1 chuoi
void ConvertToBu2(string& s);// Chuyen so nhi phan sang bu 2
void ChuanHoa(string& s);//Chuan hoa chuoi nhi phan (bo bot so 0 du thua)

//Cac ham chuyen doi
int ConvertBinToDec(string s);//Chuyen tu he 2 -> 10 tra ve so nguyen
string ConvertDecimalToBin(string s,int szbits=0);//Chuyen tu he 10 -> 2 với kich thuoc day nhi phan la szbits 

char convertBin4bitsToHex(string subStr);//Ham phu tro dung de chuyen 4 bit nhi phan sang ky tu hexa
string ConvertBinToHex(string StrBin);//Chuyen tu he 2 -> 16
string ConvertHexToBin(string s);//Chuyen tu he 16 -> 2

//Ham chuyen doi chuoi sang nhi phan
//Tham so: s la chuoi muon chuyen doi ung voi heso 2,10,16 
//Tra ve day nhi phan co kich thuoc 128 bits
string ConvertStrToBin(string s, int heso);
 

//Xu ly tung dong du lieu trong tap tin
vector<string> ReadData(string line_info);//Doc cac dong thong tin cat ra cac thanh phan
string Calculator(vector<string> data);//Tinh toan và tra ra ket qua mong muon