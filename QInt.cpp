#include "QInt.h"
#include "ProcessData.h"
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

char QInt::convertBin4bitsToHex(string subStr) {
	int length = subStr.length();
	char result = 0;
	char t;

	for (int i = 0; i < length; i++) {
		t = subStr[length - 1 - i] - '0';
		result += t * pow(2, i);
	}
	//cout << "convertBin4bitsToHex:"<<(int)result<<endl;

	if (result >= 0 && result <= 9) {
		result += 48;
	}
	else {
		result = 65 + (result - 10);
	}

	return result;
}

string QInt::convertBinToHex(){
 	string StrBin = this->QIntToBin();
	string subStr4bits;
	string strHex = "";
	string temp = "";
	int lenghtStrBin = 128;

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

string QInt::convertHexToBin() {
	return this->QIntToBin();
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

string QInt::ConvertToDecimal()
{
	string s = this->QIntToBin();
	int dau = s[0] - '0';
	if (dau == 1)
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

	if (this->ConvertToDecimal() == "0" || qint.ConvertToDecimal() == "0"){
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
	a.Input(BU2(s));
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
	s1 = this->QIntToBin();
	s2 = x.QIntToBin();
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
				element1.Input(s3);
				element2.Input(s2);
				s3 = (element1 - element2).QIntToBin();
				s3 = s3.substr(1, s3.length() - 1);
			}
			else if (s3.length() == s2.length() && check(s3, s2) == true)
			{
				s.push_back('1');
				element1.Input(s3);
				element2.Input(s2);
				s3 = (element1 - element2).QIntToBin();
				s3 = s3.substr(1, s3.length() - 1);
			}
			else if (s3.length() < s2.length() || check(s3, s2) == false)
			{
				s.push_back('0');
			}
			s3 = Check_0_in_head(s3);
		}
	}
	
	for (int i = 0; i <= (128 - s.length()); i++)
	{
		kq.push_back('0');
	}
	kq = kq + s;
	KQ.Input(kq);
	return KQ;
}