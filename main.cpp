#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

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
    while(num!=0){
        result+=char(num%10)+'0';
        num/=10;
    }

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
string ConvertDecimalToBin(string s){
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
    reverse(result.begin(),result.end());   

    if(isNegative){
        ConvertToBu2(result);
    }

    return result;
}
string ConvertHexToBin(string s){
    string result="";
    for(int i=0;i<s.length();i++){
        string tmp;
        if(s[i]<='9'){
            tmp=ConvertDecimalToBin(s.substr(i,1));
            reverse(tmp.begin(),tmp.end());
            while(tmp.length()<4){
                tmp+='0';
            }
            reverse(tmp.begin(),tmp.end());
        }
        else{
            string num=IntToStr((int)(s[i]-'A')+10);
            tmp=ConvertDecimalToBin(num);
        }
        result+=tmp;
    }

    return result;
}
string ConvertStrToBin(string s, int heso){
    string result="";
    if(heso==10){
        result=ConvertDecimalToBin(s);
    }
    else if(heso==16){
        result=ConvertHexToBin(s);
    }
    else{
            result=s;
    }
    
    return result;
}

int main(int argc, char *argv[]){
    fstream file1(argv[1],ios::in);
    fstream file2(argv[2],ios::trunc);
    string result;//Ket qua de ghi vao file
    string line_info;// Dong thong tin de xu ly
    while(!file1.eof()){
        getline(file1,line_info); 
        //Xu ly dong thong tin tho(line_info) thanh du lieu co the xu ly duoc
        /* 
        - Doc tung dong ghi ra cac bien string 
        - Dua du lieu vao QInt
        */

        //Xu ly du lieu(duoi dang QInt) thanh ket qua 
        /*
        - Cac phep toan + - * / rol >> << tren nhi phan (QInt -> string(nhi phan))
        - Chuyen Nhi Phan ve he so cuoi
         */

        //luu ket qua vao trong bien result
        
        file2<<result<<endl;
    }

    file1.close();
    file2.close();
    return 1;
}