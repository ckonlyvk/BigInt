#include <iostream>
#include <bitset>
#include <string>
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

int main() {
	//cout << convertBin4bitsToHex("1111")<<endl;
	//string s = "0";

	cout << convertBinToHex("101011")<<endl;
	//cout << s.length() <<endl;
	//cout << s.length()<<" " << s[0] <<endl;
	//string s = "1011011111000101010010010010110111110001001001010110010101010101";
	//cout << ConvertToDecimal(s);
	system("pause");
	return 0;
}