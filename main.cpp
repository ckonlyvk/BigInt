#include "ProcessData.h"
#include "QInt.h"

//g++ main.cpp ProcessData.cpp QInt.cpp -o main
//.\main.exe input.txt output.txt
int main(int argc, char *argv[]){
    fstream file1(argv[1],ios::in);
    fstream file2(argv[2],ios::out);
    string result;//Ket qua de ghi vao file
    string line_info;// Dong thong tin de xu ly
    int i=1;
    while(!file1.eof()){
        getline(file1,line_info);
        if(line_info=="")
            break;
        vector<string> data=ReadData(line_info);
        result=Calculator(data);
        file2<<result<<endl;
    }

    return 1;
}