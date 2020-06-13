#include "ProcessData.h"
#include "QInt.h"
//g++ main.cpp QInt.cpp -o main
//g++ main.cpp ProcessData.cpp QInt.cpp -o main && main
//.\main.exe input.txt output.txt
int main(int argc, char *argv[]){
    // fstream file1(argv[1],ios::in);
    // fstream file2(argv[2],ios::out);
    // string result;//Ket qua de ghi vao file
    // string line_info;// Dong thong tin de xu lybb
    // int i=1;
    // while(!file1.eof()){
    //     getline(file1,line_info);
    //     if(line_info=="")
    //         break;
    //     vector<string> data=ReadData(line_info);
    //     result=Calculator(data);
    //     // system("pause");
    //     // system("cls");
    //     file2<<result<<endl;
    // }

    // file1.close();
    // file2.close();
    fstream file1(argv[1],ios::in);
    fstream file2(argv[2],ios::in);
    string s1;
    string s2;
    int i=1;
    while(!file1.eof()){
        getline(file1,s1);
        getline(file2,s2);
        if(s1!=s2){
            cout<<i<<endl;
            cout<<s1<<endl;
            cout<<s2<<endl;
        }
        i++;
    }
    return 1;
}


