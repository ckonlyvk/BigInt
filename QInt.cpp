#include "QInt.h"
char QInt::convertBin4bitsToHex(string subStr) {
	int length = subStr.length();
	char result = 0;
	char t;

	for (int i = 0; i < length; i++) {
		t = subStr[length - 1 - i] - '0';
		result += t * pow(2, i);
	}

	if (result >= 0 && result <= 9) {
		result += 48;
	}
	else {
		result = 65 + (result - 10);
	}

	return result;
}

string QInt::convertBinToHex(string StrBin){
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

//string QInt::convertHexToBin(string StrHex) {
//	//return toStrBin();
//}

string QInt::shiftRight(string StrBin, int SoBitDich){
	int BitDau = StrBin[0] - '0';
	int length = StrBin.length();
	int size;

	if (length > 0) {

		if (SoBitDich > length) {
			size = 0;
			SoBitDich = length;
		}
		else {
			size = length - SoBitDich;
		}

		StrBin = StrBin.substr(0, size);

		for (int i = 0; i < SoBitDich; i++) {
			StrBin.insert(0, to_string(BitDau));
		}

	}

	return StrBin;
}

string QInt::cong(string a, string b){
	string c;
	string str;
	int memo = 0;
	int num = 0;
	if (a.length() > b.length())
	{
		int j = b.length() - 1;
		for (int i = a.length() - 1; i > a.length() - 1 - b.length(); i--)
		{
			if (j < 0)
			{
				break;
			}
			num = 0;
			num = (a[i] - '0') + (b[j] - '0') + memo;//cộng từng số của hai string
			j--;
			memo = 0;

			if (num > 2)										//lưu biến nhớ khi số cộng lại lớn hơn 9
			{
				memo = 1;
				num = num % 2;
			}
			else if (num > 1)
			{
				memo = 1;
				num = num % 2;
			}
			c.push_back(char(num + 48));
		}
		for (int i = a.length() - 1 - b.length(); i >= 0; i--)
		{
			num = 0;
			num = memo + (a[i] - '0');
			memo = 0;
			if (num > 2)										//lưu biến nhớ khi số cộng lại lớn hơn 9
			{
				memo = 1;
				num = num % 2;
			}
			else if (num > 1)
			{
				memo = 1;
				num = num % 2;
			}
			c.push_back(char(num + 48));
		}
	}
	else
	{
		int j = a.length() - 1;
		for (int i = b.length() - 1; i > b.length() - 1 - a.length(); i--)
		{
			if (j < 0)
			{
				break;
			}
			num = 0;
			num = (b[i] - '0') + (a[j] - '0') + memo; //cộng từng số của hai string
			memo = 0;
			j--;
			if (num > 2)										//lưu biến nhớ khi số cộng lại lớn hơn 9
			{
				memo = 1;
				num = num % 2;
			}
			else if (num > 1)
			{
				memo = 1;
				num = num % 2;
			}
			c.push_back(char(num + 48));
		}
		for (int i = b.length() - 1 - a.length(); i >= 0; i--)
		{
			num = 0;
			num = memo + (b[i] - '0');
			memo = 0;
			if (num > 2)										//lưu biến nhớ khi số cộng lại lớn hơn 9
			{
				memo = 1;
				num = num % 2;
			}
			else if (num > 1)
			{
				memo = 1;
				num = num % 2;
			}
			c.push_back(char(num + 48));
		}
	}
	for (int i = c.length() - 1; i >= 0; i--)
	{
		str.push_back(c[i]);
	}
	return str;
}

string QInt::multiplyQInt(string StrBin1, string StrBin2){
	string result = "";
	string temp = "";
	int lenght = StrBin1.length();
	int j = 0;
	for (int i = lenght - 1; i >= 0; i--) {
		if (StrBin1[i] - '0' == 1) {
			temp = StrBin2;
			result = cong(result, DiChuyenSangTrai(temp, j));
		}
		j++;
	}

	return result;
}

string QInt::shiftLeft(string StrBin, int SoBitDich) {
	int length = StrBin.length();
	int size;
	if (SoBitDich < 0) return StrBin;

	if (length > 0) {
		if (SoBitDich > length) {
			StrBin = "";
			size = length;
		}
		else {
			StrBin = StrBin.substr(SoBitDich, length);
			size = SoBitDich;
		}
	}

	for (int i = 0; i < size; i++) {
		StrBin.push_back('0');
	}

	return StrBin;
}

string QInt::DiChuyenSangTrai(string StrBin, int SoBitDich) {
	for (int i = 0; i < SoBitDich; i++) {
		StrBin.push_back('0');
	}

	return StrBin;
}