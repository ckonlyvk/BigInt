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
	int lengthStrBin = StrBin.length();
	int size;

	if (lengthStrBin == 128 && StrBin[0] - '0' == 1) {

		if (SoBitDich > 128) {
			StrBin = "";
		}
		else {
			size = lengthStrBin - SoBitDich;
			StrBin = StrBin.substr(0, size);
			lengthStrBin = SoBitDich;
		}

		for (int i = 0; i < lengthStrBin; i++) {
			StrBin.insert(0, "1");
		}

	}
	else {
		StrBin = Check_0_in_head(StrBin);
		lengthStrBin = StrBin.length();

		if (StrBin.compare("") == 0 || SoBitDich >= lengthStrBin) {
			StrBin = "0";
		}
		else {
			size = lengthStrBin - SoBitDich;
			StrBin = StrBin.substr(0, size);
			StrBin = Check_0_in_head(StrBin);
		}

	}

	return StrBin;
}

string QInt::multiplyQInt(string StrBin1, string StrBin2){
	string result = "";
	string temp = "";

	if (Check_0_in_head(StrBin1).compare("") == 0 || Check_0_in_head(StrBin2).compare("") == 0) {
		result = "0";
		return result;
	}

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
	int length;
	int size;

	if (SoBitDich < 0) return Check_0_in_head(StrBin);//Xử lý như thế nào cho hợp lý?

	StrBin = Check_0_in_head(StrBin);
	length = StrBin.length();

	if (SoBitDich >= length || StrBin.compare("") == 0) {
		StrBin = "0";
		return StrBin;
	}
	else {
		StrBin = StrBin.substr(SoBitDich, length);
		size = SoBitDich;
		StrBin = Check_0_in_head(StrBin);

		if (StrBin.compare("") == 0) {
			StrBin = "0";
			return StrBin;
		}
		else {

			for (int i = 0; i < size; i++) {
				StrBin.push_back('0');
			}

		}
	}

	return StrBin;
}

string QInt::DiChuyenSangTrai(string StrBin, int SoBitDich) {
	for (int i = 0; i < SoBitDich; i++) {
		StrBin.push_back('0');
	}

	return StrBin;
}

int* QInt::CreateNewArrange(int *x,int count)
{
	int*y = new int[count + 1];
	for (int i = 0; i < count; i++)
	{
		y[i] = x[i];
	}
	y[count] = 0;
	return y;
}

string QInt::Check_0_in_head(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] - '0' == 1)
		{
			s = s.substr(i, s.length() - i);
			return s;
		}
	}
	return "";
}

string QInt::BU2(string s)
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
	return s;
}
string QInt::ConvertToDecimal(string s) 
{
	s = Check_0_in_head(s);
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
	int *y = new int[1];
	int*y1;
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
	str = Check_0_in_head(str);
	return str;
}

string QInt::cong(string a, string b)
{
	string c;
	string str;
	int memo = 0;
	int num = 0;
	a = Check_0_in_head(a);
	b = Check_0_in_head(b);
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
		if (memo == 1 && c.length() < 128)
		{
			c.push_back('1');
		}
	}
	else if (a.length() == b.length())
	{
		for (int i = a.length() - 1; i >= 0; i--)
		{
			num = 0;
			num = a[i] - '0' + b[i] - '0' + memo;
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
		if (memo == 1 && c.length() < 128)
		{
			c.push_back('1');
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
		if (memo == 1 && c.length() < 128)
		{
			c.push_back('1');
		}
	}
	for (int i = c.length() - 1; i >= 0; i--)
	{
		str.push_back(c[i]);
	}
	str = Check_0_in_head(str);
	return str;
}

string QInt::AND(string s1, string s2)
{
	string s;
	s1 = Check_0_in_head(s1);
	s2 = Check_0_in_head(s2);
	int length = s1.length();
	if (s1.length() > s2.length())
	{
		length = s2.length();
		s1 = s1.substr(s1.length() - length, length);
	}
	else if(s1.length() < s2.length())
	{
		length = s1.length();
		s2 = s2.substr(s2.length() - length, length);
	}
	for (int i = 0; i < length; i++)
	{
		if (s1[i] - '0' == 1 && s2[i] - '0' == 1)
		{
			s.push_back('1');
		}
		else
		{
			s.push_back('0');
		}
	}
	s = Check_0_in_head(s);
	return s;
}

string QInt::OR(string s1, string s2)
{
	string s;
	string s3;
	s1 = Check_0_in_head(s1);
	s2 = Check_0_in_head(s2);
	int length = s1.length();
	if (s1.length() > s2.length())
	{
		length = s2.length();
		s3 = s1.substr(0, s1.length() - length);
		s1 = s1.substr(s1.length() - length, length);
	}
	else if (s1.length() < s2.length())
	{
		length = s1.length();
		s3 = s1.substr(0, s1.length() - length);
		s2 = s2.substr(s2.length() - length, length);
	}
	for (int i = 0; i < length; i++)
	{
		if (s1[i] - '0' == 1 || s2[i] - '0' == 1)
		{
			s.push_back('1');
		}
		else
		{
			s.push_back('0');
		}
	}
	s = Check_0_in_head(s3 + s);
	return s;
}

string QInt::XOR(string s1, string s2)
{
	string s;
	string s3;
	s1 = Check_0_in_head(s1);
	s2 = Check_0_in_head(s2);
	int length = s1.length();
	if (s1.length() > s2.length())
	{
		length = s2.length();
		s3 = s1.substr(0, s1.length() - length);
		s1 = s1.substr(s1.length() - length, length);
	}
	else if (s1.length() < s2.length())
	{
		length = s1.length();
		s3 = s1.substr(0, s1.length() - length);
		s2 = s2.substr(s2.length() - length, length);
	}
	for (int i = 0; i < length; i++)
	{
		if (s1[i] - '0' ==  s2[i] - '0')
		{
			s.push_back('0');
		}
		else
		{
			s.push_back('1');
		}
	}
	s = Check_0_in_head(s3 + s);
	return s;
}

string QInt::NOT(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] - '0' == 1)
		{
			s[i] = '0';
		}
		else
		{
			s[i] = '1';
		}
	}
	s = Check_0_in_head(s);
	return s;
}

string QInt::ROL(string s)
{
	char x = s[0];
	s = s.substr(1, s.length() - 1);
	s.push_back(x);
	s = Check_0_in_head(s);
	return s;
}

string QInt::ROR(string s)
{
	string s1;
	s1.push_back(s[s.length() - 1]);
	s.pop_back();
	s = s1 + s;
	s = Check_0_in_head(s);
	return s;
}

bool QInt::check(string s1, string s2)
{
	if (s1.length() == s2.length())
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] - '0' > s2[i] - '0')
			{
				break;
			}
			if (s1[i] - '0' < s2[i] - '0')
			{
				return false;
			}
		}
	}
	return true;
}

string QInt::chia(string s1, string s2)
{
	bool status = true;
	string s;
	string s3;
	s1 = Check_0_in_head(s1);
	s2 = Check_0_in_head(s2);
	if (s1.length() < s2.length())
	{
		s = s1;
	}
	else if (s1.length() == s2.length())
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] - '0' > s2[i] - '0')
			{
				return "1";
				break;
			}
			if (s1[i] - '0' < s2[i] - '0')
			{
				s = s1;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < s1.length(); i++)
		{
			s3.push_back(s1[i]);
			if (s3.length() > s2.length())
			{
				s.push_back('1');
				s3 = cong(s3, BU2(s2));
				s3 = s3.substr(1, s3.length() - 1);
			}
			else if (s3.length() == s2.length() && check(s3, s2) == true)
			{
				s.push_back('1');
				s3 = cong(s3, BU2(s2));
				s3 = s3.substr(1, s3.length() - 1);
			}
			else if (s3.length() < s2.length() || check(s3, s2) == false)
			{
				s.push_back('0');
			}
			s3 = Check_0_in_head(s3);
		}
	}
	s = Check_0_in_head(s);
	return s;
}