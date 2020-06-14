#include "QInt.h"

QInt::QInt(){
	for(int i=0;i<4;i++){
		arrayBits[i]=0;
	}
}

void QInt::Input(string StrBin){
	int end_pos=StrBin.length();
	int start_pos=(end_pos - 31 < 0? 0:end_pos-32);
	int k=3;
	while(k>=0 && end_pos>0){
		//Cat chuoi nhi phan thanh 32 bits va day vao tung phan tu mang int 
		arrayBits[k]=ConvertBinToDec(StrBin.substr(start_pos,end_pos-start_pos));
		k--;
		end_pos=start_pos;
		start_pos=(end_pos - 31 < 0? 0:end_pos-32);
	}
}

void QInt::Output(){
	for(int i=0;i<=3;i++)
	{
		cout<<arrayBits[i]<<" ";
	}
}

string QInt::QIntToBin(){
	string tmp="";
	for(int i=0;i<4;i++){
		//Lay tung phan tu chuyen sang nhi phan roi ghep lai thanh 1 day hoan chinh
		tmp+=ConvertDecimalToBin(IntToStr(arrayBits[i]),32);
	}
	return tmp;
}

string QInt::QIntToHex()
{
	string tmp=QIntToBin();
	ChuanHoa(tmp);
	return ConvertBinToHex(tmp);
}

string QInt::QIntToDecimal(){
	string s = this->QIntToBin();
	int dau = s[0] - '0';
	if (dau == 1)
	{
		ConvertToBu2(s);
	}

	string str;
	string str1;
	int x = 0;
	int count = 0; //kích thước mảng
	int count2;
	int *y = new int[1];
	int*y1;

	
	for (int i = 0; i < s.length(); i++)
	{
		count2 = 0;
		if (count != 0)
		{
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
		else
		{
			y[count] = s[i] - '0';
			if (y[count] > 0)
			{
				count++;
				y1 = CreateNewArrange(y, count);
				delete[]y;
				y = y1;
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		str1.push_back(char(y[i] + 48));
	}
	delete[]y;
	if (dau == 1)
	{
		str.push_back('-');
	}
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		str.push_back(str1[i]);
	}
	if (str.length() == 0)
	{
		str.push_back('0');
	}
	return str;
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

QInt QInt::operator=(QInt a){
	for(int i = 0; i < 4 ;i++){
		this->arrayBits[i] = a.arrayBits[i];
	}

	return *this;
}

void QInt::operator>>(int SoBitDich){
	string StrBin = this->QIntToBin();
	char BitDau = StrBin[0];
	string s;
	
	if (SoBitDich >= 0){
		StrBin = StrBin.substr(0, 128 - SoBitDich);

		for(int i = 0; i < SoBitDich; i++){
			s.push_back(BitDau);
		}

		s = s + StrBin;
	}
	//Nếu số bit dịch nhỏ hơn 0 thì không xử lý.
	this->Input(s);
}

void QInt::operator<<(int SoBitDich){
	string StrBin = this->QIntToBin();

	if (SoBitDich >= 0){
		StrBin = StrBin.substr(SoBitDich);

		for(int i = 0; i < SoBitDich; i++){
			StrBin.push_back('0');
		}
		
	}
	//Nếu số bit dịch nhỏ hơn 0 thì không xử lý.
	this->Input(ConvertStrToBin(StrBin, 2));
}

QInt QInt::operator*(QInt qint){
	string StrBin = this->QIntToBin();
	QInt kq;
	
	QInt Qtemp;
	string result = "0";
	string temp = "";

	kq.Input(ConvertStrToBin("0", 10));

	if (this->QIntToDecimal() == "0" || qint.QIntToDecimal() == "0"){
		this->Input(ConvertStrToBin("0", 10));
	} else {

		for (int i = 128 - 1; i >= 0; i--) {

			if (StrBin[i] - '0' == 1) {
				kq = kq + qint;			
			}

			qint << 1;
		}

	}

	return kq;
}

QInt QInt::operator+(QInt a)
{
	QInt KQ;
	string x = this->QIntToBin();
	string y = a.QIntToBin();
	string c;
	string str;
	int memo = 0;
	int num = 0;

	for (int i = y.length() - 1; i >= 0; i--)
	{
		num = 0;
		num = y[i] - '0' + x[i] - '0' + memo;
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
	for (int i = c.length() - 1; i >= 0; i--)
	{
		str.push_back(c[i]);
	}
	if (str.length() == 0)
	{
		str.push_back('0');
	}
	KQ.Input(str);
	return KQ;
}

QInt QInt::operator&(QInt x)
{
	QInt y;
	string s;
	string s1 = this->QIntToBin();
	string s2 = x.QIntToBin();
	for (int i = 0; i < 128; i++)
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
	y.Input(s);
	return y;
}

QInt QInt::operator|(QInt x)
{
	string s, s1, s2;
	QInt y;
	s1 = this->QIntToBin();
	s2 = x.QIntToBin();

	for (int i = 0; i < 128; i++)
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
	y.Input(s);
	return y;
}

QInt QInt::operator^(QInt x)
{
	string s, s1, s2;
	QInt y;
	s1 = this->QIntToBin();
	s2 = x.QIntToBin();
	for (int i = 0; i < 128; i++)
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
	y.Input(s);
	return y;
}

QInt QInt::operator-(QInt a)
{
	string s = a.QIntToBin();
	ConvertToBu2(s);
	a.Input(s);
	return *this + a;
}

QInt QInt::operator~()
{
	string s = this->QIntToBin();
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
	this->Input(s);
	return *this;
}

QInt QInt::ROL()
{
	string s = this->QIntToBin();
	char x = s[0];
	s = s.substr(1, s.length() - 1);
	s.push_back(x);
	this->Input(s);
	return *this;
}

QInt QInt::ROR()
{
	string s = this->QIntToBin();
	string s1;
	s1.push_back(s[127]);
	s.pop_back();
	s = s1 + s;
	this->Input(s);
	return *this;
}

QInt QInt::operator/(QInt x)
{
	QInt KQ, element1, element2;
	string s, s1, s2, kq;
	string s3;
	int dau1, dau2;
	s1 = this->QIntToBin();
	s2 = x.QIntToBin();
	dau1 = s1[0] - '0';
	dau2 = s2[0] - '0';
	if (dau1 == 1)
	{
		ConvertToBu2(s1);
	}
	if (dau2 == 1)
	{
		ConvertToBu2(s2);
	}
	s1 = Check_0_in_head(s1);
	s2 = Check_0_in_head(s2);
	if (s2.length() == 0)
	{
		s.push_back('0');
	}
	else if (s1.length() < s2.length())
	{
		s.push_back('0');
	}
	else if (s1.length() == s2.length())
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] - '0' > s2[i] - '0')
			{
				s.push_back('1');
			}
			if (s1[i] - '0' < s2[i] - '0')
			{
				s.push_back('0');
			}
		}
		s.push_back('1');
	}
	else
	{
		for (int i = 0; i < s1.length(); i++)
		{
			s3.push_back(s1[i]);
			if (s3.length() > s2.length())
			{
				s.push_back('1');
				s2 = ConvertStrToBin(s2, 2);
				s3 = ConvertStrToBin(s3, 2);
				element1.Input(s3);
				element2.Input(s2);
				s3 = (element1 - element2).QIntToBin();
				s3 = s3.substr(1, s3.length() - 1);
			}
			else if (s3.length() == s2.length() && check(s3, s2) == true)
			{
				s.push_back('1');
				s2 = ConvertStrToBin(s2, 2);
				s3 = ConvertStrToBin(s3, 2);
				element1.Input(s3);
				element2.Input(s2);
				s3 = (element1 - element2).QIntToBin();
				s3 = s3.substr(1, s3.length() - 1);
			}
			else if (s3.length() < s2.length() || check(s3, s2) == false)
			{
				s.push_back('0');
			}
			s2 = Check_0_in_head(s2);
			s3 = Check_0_in_head(s3);
		}
	}
	for (int i = 0; i < (128 - s.length()); i++)
	{
		kq.push_back('0');
	}
	kq = kq + s;
	if ((dau1 == 1 && dau2 == 0) || (dau1 == 0 && dau2 == 1))
	{
		ConvertToBu2(kq);
	}
	KQ.Input(kq);
	return KQ;
}
