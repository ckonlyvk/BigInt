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

string QInt::convertHexToBin(string StrHex) {
	//return toStrBin();
}