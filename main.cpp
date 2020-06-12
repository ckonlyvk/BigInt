#include "ProcessData.h"
#include "QInt.h"
//g++ main.cpp QInt.cpp -o main
//g++ main.cpp QInt.cpp ProcessData.cpp -o main
//.\main.exe input.txt output.txt
// int main(int argc, char *argv[]){
//     fstream file1(argv[1],ios::in);
//     fstream file2(argv[2],ios::out);
//     string result;//Ket qua de ghi vao file
//     string line_info;// Dong thong tin de xu lybb
//     while(!file1.eof()){
//         getline(file1,line_info); 
//         //Xu ly dong thong tin tho(line_info) thanh du lieu co the xu ly duoc
//         /* 
//         - Doc tung dong ghi ra cac bien string 
//         - Dua du lieu vao QInt
//         */

//         //Xu ly du lieu(duoi dang QInt) thanh ket qua 
//         /*
//         - Cac phep toan + - * / rol >> << tren nhi phan (QInt -> string(nhi phan))
//         - Chuyen Nhi Phan ve he so cuoi
//          */

//         //luu ket qua vao trong bien result
        
//         file2<<line_info<<endl;
//     }

//     file1.close();
//     file2.close();

//     return 1;
// }


//g++ main.cpp QInt.cpp ProcessData.cpp -o main && main
int main (){

    // QInt a;
    // cout << "Hello World!"<<endl;
    // cout<<a.multiplyQInt("100110110", "0");
    // string s="-99999";
    // string bin=ConvertStrToBin(s,10);
    // ChuanHoa(bin);
    // QInt qInt;
    // cout<<bin<<endl;
    // qInt.Input(bin);
    // qInt.Output();
    // cout<<endl;
    // cout<<qInt.QIntToBin();

    string s="ABD";
    string bin=ConvertStrToBin(s,16);
    cout<<bin<<endl;
    ChuanHoa(bin);
    cout<<bin<<endl;
    
    system("pause");
    return 0;
}