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


//g++ main.cpp ProcessData.cpp QInt.cpp -o main
int main (){

    QInt a, b;
    string s="110001100001001001000100";
    string s2="1001101010101111111000011111000101000110001110001100";
    string bin=ConvertStrToBin(s,10);
    a.Input(ConvertStrToBin(s,2));
    b.Input(ConvertStrToBin(s2,2));
    
   // cout << a.QIntToBin()<<endl;
   // cout << b.QIntToBin()<<endl;
    //cout << "lb = " << b.QIntToBin().length()<<endl;
    //a.Output();
    cout<<endl;
    //cout<<s.length()<<endl;
   //cout<<a.QIntToBin();
   cout << a.convertBinToHex()<<endl;
    cout << b.convertBinToHex()<<endl;
    //cout << b.QIntToBin()<<endl;
    //a << 5;
    //cout << a.QIntToBin()<<endl;
    string tich = (a*b).convertBinToHex();
   // cout << "tich chua chuan hoa: "<< tich << endl;
    //ChuanHoa(tich);
    //cout << "tich da chuan hoa: "<<tich << endl;
    system("pause"); 
    return 0;
}