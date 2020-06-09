#include <iostream>
#include <bitset>
#include <string>
//#include "QInt.h"
using namespace std;

int* CreateNewArrange(int* x, int count)
{
	int* y = new int[count + 1];
	for (int i = 0; i < count; i++)
	{
		y[i] = x[i];
	}
	y[count] = 0;
	return y;
}
string ConvertToDecimal(string s)
{
	int dau = s[0] - '0';
	if (s.length() == 128 && dau == 1)
	{
		for (int i = s.length() - 1; i >= 0; i--)
		{
			if (s[i] - '0' == 1)
			{
				for (int j = i - 1; j >= 0; j--)
				{
					if (s[j] - '0' == 1)
					{
						s[j] = '0';
					}
					else
					{
						s[j] = '1';
					}
				}
				break;
			}
		}
	}
	string str;
	string str1;
	int x = 0;
	int count = 0; //kích thước mảng
	int count2;
	int* y = new int[1];
	int* y1;
	if (s.length() >= 32)
	{
		for (int i = 0; i < 31; i++)
		{
			x = x * 2 + (s[i] - '0');
		}
		while (x > 0)
		{
			y[count] = x % 10;
			count++;
			y1 = CreateNewArrange(y, count);
			delete[]y;
			y = y1;
			x = (x - x % 10) / 10;
		}
		x = 0;
		for (int i = 31; i < s.length(); i++)
		{
			count2 = 0;
			for (int j = 0; j < count; j++)
			{
				y[j] = y[j] * 2 + x;//x là biến nhớ
				x = 0;
				if (y[j] > 9)
				{
					x = y[j] / 10;
					y[j] = y[j] % 10;
				}
			}
			if (x != 0)
			{
				y1 = CreateNewArrange(y, count);
				delete[]y;
				y = y1;
				y[count] = x;
				count++;
				x = 0;
			}
			y[0] = y[0] + (s[i] - '0');
			if (y[0] > 9)
			{
				y[0] = y[0] % 10;
				count2++;
				x = 1;
			}
			while (x != 0)
			{
				y[count2] = y[count2] + x;
				if (y[count2] > 9)
				{
					y[count2] = y[count2] % 10;
					count2++;
					x = 1;
				}
				else
				{
					x = 0;
				}
			}
		}
		for (int i = 0; i < count; i++)
		{
			str1.push_back(char(y[i] + 48));
		}
		if (dau == 1 && s.length() == 128)
		{
			str.push_back('-');
		}
		for (int i = str1.length() - 1; i >= 0; i--)
		{
			str.push_back(str1[i]);
		}
	}
	else
	{
		for (int i = 0; i < s.length(); i++)
		{
			x = x * 2 + (s[i] - '0');
		}
		while (x > 0)
		{
			str1.push_back(char(x % 10 + 48));
			x = (x - x % 10) / 10;
		}
		if (dau == 1 && s.length() == 128)
		{
			str.push_back('-');
		}
		for (int i = str1.length() - 1; i >= 0; i--)
		{
			str.push_back(str1[i]);
		}
	}
	return str;
}

char convertBin4bitsToHex(string subStr) {
	int length = subStr.length();
	char result = 0;
	char temp;

	for (int i = 0; i < length; i++) {
		temp = subStr[length - 1 - i] - '0';
		result += temp * pow(2, i);
	}

	if (result >= 0 && result <= 9) {
		result += 48;
	}
	else {
		result = 65 + (result - 10);
	}

	return result;
}

string convertBinToHex(string StrBin) {
	int lenghtStrBin = StrBin.length();
	int i = 0;

	while ((StrBin[i] - '0') == 0) {
		i++;
		
		if (i >= lenghtStrBin) {
			break;
		}
	}

	StrBin = StrBin.substr(i);
	lenghtStrBin = StrBin.length();

	string subStr4bits;
	string strHex = "";
	string temp = "";

	while (lenghtStrBin > 0) {

		if (lenghtStrBin < 4) {
			subStr4bits = StrBin.substr(0, lenghtStrBin);
		}
		else {
			subStr4bits = StrBin.substr(lenghtStrBin - 4, 4);
		}

		temp = convertBin4bitsToHex(subStr4bits);
		strHex.insert(0, temp);

		lenghtStrBin -= 4;
	}

	return strHex;
}

//string cong(string a, string b)
//{
//	string c;
//	string str;
//	int memo = 0;
//	int num = 0;
//	if (a.length() > b.length())
//	{
//		int j = b.length() - 1;
//		for (int i = a.length() - 1; i > a.length() - 1 - b.length(); i--)
//		{
//			if (j < 0)
//			{
//				break;
//			}
//			num = 0;
//			num = (a[i] - '0') + (b[j] - '0') + memo;//cộng từng số của hai string
//			j--;
//			memo = 0;
//
//			if (num > 2)										//lưu biến nhớ khi số cộng lại lớn hơn 9
//			{
//				memo = 1;
//				num = num % 2;
//			}
//			else if (num > 1)
//			{
//				memo = 1;
//				num = num % 2;
//			}
//			c.push_back(char(num + 48));
//		}
//		for (int i = a.length() - 1 - b.length(); i >= 0; i--)
//		{
//			num = 0;
//			num = memo + (a[i] - '0');
//			memo = 0;
//			if (num > 2)										//lưu biến nhớ khi số cộng lại lớn hơn 9
//			{
//				memo = 1;
//				num = num % 2;
//			}
//			else if (num > 1)
//			{
//				memo = 1;
//				num = num % 2;
//			}
//			c.push_back(char(num + 48));
//		}
//	}
//	else
//	{
//		int j = a.length() - 1;
//		for (int i = b.length() - 1; i > b.length() - 1 - a.length(); i--)
//		{
//			if (j < 0)
//			{
//				break;
//			}
//			num = 0;
//			num = (b[i] - '0') + (a[j] - '0') + memo; //cộng từng số của hai string
//			memo = 0;
//			j--;
//			if (num > 2)										//lưu biến nhớ khi số cộng lại lớn hơn 9
//			{
//				memo = 1;
//				num = num % 2;
//			}
//			else if (num > 1)
//			{
//				memo = 1;
//				num = num % 2;
//			}
//			c.push_back(char(num + 48));
//		}
//		for (int i = b.length() - 1 - a.length(); i >= 0; i--)
//		{
//			num = 0;
//			num = memo + (b[i] - '0');
//			memo = 0;
//			if (num > 2)										//lưu biến nhớ khi số cộng lại lớn hơn 9
//			{
//				memo = 1;
//				num = num % 2;
//			}
//			else if (num > 1)
//			{
//				memo = 1;
//				num = num % 2;
//			}
//			c.push_back(char(num + 48));
//		}
//	}
//	for (int i = c.length() - 1; i >= 0; i--)
//	{
//		str.push_back(c[i]);
//	}
//	return str;
//}
//
//string shiftRight(string StrBin, int SoBitDich) {
//	int BitDau = StrBin[0] - '0';
//	int length = StrBin.length();
//	int size;
//
//	if (length > 0) {
//
//		if (SoBitDich > length) {
//			size = 0;
//			SoBitDich = length;
//		}
//		else {
//			size = length - SoBitDich;
//		}
//
//		StrBin = StrBin.substr(0, size);
//
//		for (int i = 0; i < SoBitDich; i++) {
//			StrBin.insert(0, to_string(BitDau));
//		}
//
//	}
//
//	return StrBin;
//}
//
//string DiChuyenSangTrai(string StrBin, int SoBitDich) {
//	for (int i = 0; i < SoBitDich; i++) {
//		StrBin.push_back('0');
//	}
//
//	return StrBin;
//}
//
//string multiplyQInt(string StrBin1, string StrBin2) {
//	string result = "";
//	string temp = "";
//	int lenght = StrBin1.length();
//	int j = 0;
//	for (int i = lenght - 1; i >= 0; i--) {
//		if (StrBin1[i] - '0' == 1) {
//			temp = StrBin2;
//			result = cong(result, DiChuyenSangTrai(temp, j));
//		}		
//		j++;
//	}
//
//	return result;
//}
//
//string shiftLeft(string StrBin, int SoBitDich) {
//	int length = StrBin.length();
//	int size;
//	if (SoBitDich < 0) return StrBin;
//
//	if (length > 0) {
//		if (SoBitDich > length) {
//			StrBin = "";
//			size = length;
//		}
//		else { 
//			StrBin = StrBin.substr(SoBitDich, length); 
//			size = SoBitDich;
//		}
//	}
//
//	for (int i = 0; i < size; i++) {
//		StrBin.push_back('0');
//	}
//
//	return StrBin;
//}

int main() {
	//cout << convertBinToHex("101011")<<endl;
	//cout << s.length() <<endl;
	//cout << s.length()<<" " << s[0] <<endl;
	//string s = "1011011111000101010010010010110111110001001001010110010101010101";
	//cout << ConvertToDecimal(s);
	//cout << sizeof(QInt)<<endl;
	//cout << multiplyQInt("1101", "1011");
	//cout << cong("110111", "1011000");
	//cout << "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000" << endl;
	//cout << shiftRight("10001101", -1)<<endl;
	//cout << shiftLeft("10001101", 7) << endl;
	system("pause");
	return 0;
}