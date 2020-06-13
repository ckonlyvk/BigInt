#include "ProcessData.h"
#include "QInt.h"
//g++ main.cpp QInt.cpp -o main
//g++ main.cpp ProcessData.cpp -o main
//.\main.exe input.txt output.txt
// int main(int argc, char *argv[]){
//     fstream file1(argv[1],ios::in);
//     fstream file2(argv[2],ios::out);
//     string result;//Ket qua de ghi vao file
//     string line_info;// Dong thong tin de xu lybb
//     while(!file1.eof()){
//         getline(file1,line_info);
//         vector<string> data =ReadData(line_info);
//         result=Calculator(line_info);
        
//         file2<<result<<endl;
//     }

//     file1.close();
//     file2.close();

//     return 1;
// }


//g++ main.cpp ProcessData.cpp QInt.cpp -o main && main
int main (){
    string s="10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011";
    // QInt q;
    // q.Input(s);
    // q.Output();
    // string bin=q.QIntToBin();
    // cout<<bin.length();
    // cout<<endl;
    // cout<<s<<endl;
    // cout<<bin<<endl;
    string dec="-2147483648";
    int d1=-100;
    int d=-2147483648;
    cout<<IntToStr(d)<<endl;
    cout<<ConvertDecimalToBin(dec,32)<<endl;
    system("pause"); 
    return 0;
}