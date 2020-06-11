#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int *CreateNewArrange(int *x,int count)
{
	int*y = new int[count + 1];
	for (int i = 0; i < count; i++)
	{
		y[i] = x[i];
	}
	y[count] = 0;
	return y;
}
string Check_0_in_head(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] - '0' == 1)
		{
			if (i != 0)
			{
				s = s.substr(i, s.length() - i);
			}
			return s;
		}
	}
	return "";
}
string BU2(string s)
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
string ConvertToDecimal(string s) 
{
	s = Check_0_in_head(s);
	int dau = s[0] - '0';
	if (s.length() == 128 && dau == 1)
	{
		s = BU2(s);
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
	if (dau != 1)
	{
		str = Check_0_in_head(str);
	}
	if(str.length()==0)
	{
		str.push_back('0');
	}
	return str;
}

string cong(string a, string b)
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
	if (str.length() == 0)
	{
		str.push_back('0');
	}
	return str;
}

string AND(string s1, string s2)
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
	if (s.length() == 0)
	{
		s.push_back('0');
	}
	return s;
}

string OR(string s1, string s2)
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
		s3 = s2.substr(0, s2.length() - length);
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
	if (s.length() == 0)
	{
		s.push_back('0');
	}
	return s;
}

string XOR(string s1, string s2)
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
		s3 = s2.substr(0, s2.length() - length);
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
	if (s.length() == 0)
	{
		s.push_back('0');
	}
	return s;
}

string NOT(string s)
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
	if (s.length() == 0)
	{
		s.push_back('0');
	}
	return s;
}

string ROL(string s)
{
	char x = s[0];
	s = s.substr(1, s.length() - 1);
	s.push_back(x);
	s = Check_0_in_head(s);
	if (s.length() == 0)
	{
		s.push_back('0');
	}
	return s;
}

string ROR(string s)
{
	string s1;
	s1.push_back(s[s.length() - 1]);
	s.pop_back();
	s = s1 + s;
	s = Check_0_in_head(s);
	if (s.length() == 0)
	{
		s.push_back('0');
	}
	return s;
}

bool check(string s1, string s2)
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

string chia(string s1, string s2)
{
	bool status = true;
	string s;
	string s3;
	s1 = Check_0_in_head(s1);
	s2 = Check_0_in_head(s2);
	if (s2.length() == 0)
	{
		return "";
	}
	if (s1.length() < s2.length())
	{
		return "0";
	}
	else if (s1.length() == s2.length())
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] - '0' > s2[i] - '0')
			{
				return "1";
			}
			if (s1[i] - '0' < s2[i] - '0')
			{
				return "0";
			}
		}
		return "1";
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
int main() 
{
	string s = "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001";
	string s1 = "100001";
	cout << ConvertToDecimal(s);
	
	system("pause");
	return 0;
}