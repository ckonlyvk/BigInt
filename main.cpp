#include "ProcessData.h"
#include "QInt.h"

int main(int argc, char *argv[]){
    fstream file1(argv[1],ios::in);
    fstream file2(argv[2],ios::trunc);
    string result;//Ket qua de ghi vao file
    string line_info;// Dong thong tin de xu lybb
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