#include"ProcessData.h"

string Devide2(string s){
    string result="";
    int tmp=0;
    for(int i=0;i<s.length();i++){
        tmp=tmp*10+(int)(s[i]-'0');
        if(result==""&&tmp/2 <=0)
            continue;
        result+=char(tmp/2)+'0';
        tmp%=2;
    }
    return result!=""?result:"0";
}
string IntToStr(int num){
    string result="";
    bool isPositive=false;
    if(num<0){
        isPositive=true;
        num*=-1;
    }
    while(num!=0){
        result+=char(abs(num%10))+'0';
        num/=10;
    }
    if(isPositive)
        result+='-';
    reverse(result.begin(),result.end());
    return result!=""?result:"0";
}
void ConvertToBu2(string& s){
    for(int i=0;i<s.length();i++){
        s[i]=(s[i]=='1'?'0':'1');
    }
    int tmp=1;
    for(int i=s.length()-1;i>=0 && tmp==1;i--){
        if(s[i]=='1')
        {
            s[i]='0';
            tmp=1;
        }
        else{
            s[i]='1';
            tmp=0;
        }
    }

}

int ConvertBinToDec(string s){
    int result=0;
    int sz=s.length()-1;
    for(int i=sz;i>=1;i--){
        result+=int(s[i]-'0')*pow(2,sz-i);
    }   
    result-=int(s[0]-'0')*pow(2,sz);
    return result;
}

string ConvertDecimalToBin(string s, int szbits){
    string result="";
    bool isNegative=false;
    if(s[0]=='-'){
        isNegative= true;
        s=s.substr(1);
    }
    
    while(s!="0"){
        int tmp=int(s[s.length()-1]-'0');
        result+=tmp%2?"1":"0";
        s=Devide2(s);
    }

    int i=result.length();
    while(i<szbits)
    {
        result+='0';
        i++;
    }

    reverse(result.begin(),result.end());   

    if(isNegative){
        ConvertToBu2(result);
    }

    return result;
}

char convertBin4bitsToHex(string subStr) {
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
string ConvertBinToHex(string StrBin)
{
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

string ConvertHexToBin(string s){
    string result="";
    for(int i=0;i<s.length();i++){
        string tmp;
        if(s[i]<='9'){
            tmp=ConvertDecimalToBin(s.substr(i,1),4);
            // reverse(tmp.begin(),tmp.end());
            // while(tmp.length()<4){
            //     tmp+='0';
            // }
            //reverse(tmp.begin(),tmp.end());
        }
        else{
            string num=IntToStr((int)(s[i]-'A')+10);
            tmp=ConvertDecimalToBin(num,4);
        }
        result+=tmp;
    }
    reverse(result.begin(),result.end());
    int i=result.length();
    while(i<128){
        result+="0000";
        i+=4;
    }
    reverse(result.begin(),result.end());
    return result;
}

string ConvertStrToBin(string s, int heso){
    string result="";
    if(heso==10){
        result=ConvertDecimalToBin(s,128);
    }
    else if(heso==16){
        result=ConvertHexToBin(s);
    }
    else{
        int sz=s.length();
        reverse(s.begin(),s.end());
        while(sz<128){
            s+='0';
            sz++;
        }
        reverse(s.begin(),s.end());
        result=s;
    }
    
    return result;
}
void ChuanHoa(string& s)
{
    int start_pos=0;
    while(s[start_pos]=='0')
    {
        start_pos++;
    }

    s=s.substr(start_pos);

	if (s.length() == 0){
		s = "0";
	}
}


vector<string> ReadData(string line_info){

    vector<string> data;
    int start_pos=0;
    int end_pos=0;
    while(start_pos<line_info.length()){
        if(end_pos>=line_info.length() || line_info[end_pos]==' '){
            data.push_back(line_info.substr(start_pos,end_pos-start_pos));
            start_pos=end_pos+1;
        }
        end_pos++;
    }

    return data;
}

// string Caculator(vector<string> data)
// {
//     string result;
//     int hs1=0,hs2=0;
//     int i=2;
//     vector<QInt> qInt;
//     vector<string> pheptoan;
//     hs1=stoi(data[0]);
//     if(data[1]=="2"||data[1]=="10"||data[1]=="16")
//         hs2=stoi(data[1]);
//     else{
//         hs2=hs1;
//         i=1;
//     }
    
//     while(i<data.size()){
//         if((data[i][0]>='0'&&data[i][0]<='9')||(data[i][0]=='-' &&data[i].length()>1)){
//             QInt tmp;
//             tmp.Input(ConvertStrToBin(data[i],hs1));
//             qInt.push_back(tmp);
//         }
//         else if(data[i]=="~"||data[i]=="rol"||data[i]=="ror"){
//             QInt tmp;
//             string s=ConvertStrToBin(data[i],hs1);
//             tmp.Input(s);
//             if(data[i]=="~"){
//                 s=tmp.NOT(s);
//                 tmp.Input(s);
//             }
//             else if(data[i]=="rol"){
//                 s=tmp.ROL(s);
//                 tmp.Input(s);
//             }
//             else
//             {
//                 s=tmp.ROR(s);
//                 tmp.Input(s);
//             }
//             qInt.push_back(tmp);
//         }
//         else if(data[i]=="*"||data[i]=="/"){
//             int size=qInt.size()-1;
//             QInt tmp;
//             tmp.Input(ConvertStrToBin(data[i+1],hs1));
//             if(data[i]=="*"){
//                 string s=qInt[size].multiplyQInt(tmp);
//             }
//             else ;
//                 //Thuc hien phep nhan tren qInt vi tri size
//         }
//         else if(data[i]=="<<"||data[i]==">>"){
//             int size=qInt.size()-1;
//             if(data[i]=="<<"){
//                 //Thuc hien phep dich trai tren qInt vi tri size 
//             }
//             else ;
//                 //Thuc hien phep nhan tren qInt vi tri size
//         }
//         else
//         {
//             pheptoan.push_back(data[i]);
//         }
//         i++;
//     }

//     for(int i=0;i<pheptoan.size()-1;i++){
//         if(pheptoan[i]=="+");
//         else;
//         // qInt[0] Xu ly + , -,&,|, ^ voi qInt[i+1] cho den khi het phep toan
        
//     }
    
//     // result =qInt[0].convert(hs2) chuyen QInt thanh string minh muon xuat
//     result=qInt[0].QIntToBin();
//     return result;
// }