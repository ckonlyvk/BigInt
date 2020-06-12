#pragma once
#include<iostream>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<vector>
#include "QInt.h"

using namespace std;

// xu ly chuyen so
string Devide2(string s);
string IntToStr(int num);
void ConvertToBu2(string& s);

int ConvertBinToDec(string s);
string ConvertDecimalToBin(string s,int szbits=0);

char convertBin4bitsToHex(string subStr);
string ConvertBinToHex(string StrBin);
string ConvertHexToBin(string s);

string ConvertStrToBin(string s, int heso);
void ChuanHoa(string& s); 

//Doc file
vector<string> ReadData(string line_info);
string Caculator(vector<string> data);