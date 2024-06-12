//Cấp phát và Giải phóng ô nhớ
#include<iostream>
using namespace std;
// ĐỊnh nghĩa 1 kiểu dữ liệu tên là sinh viên gồm 3 trường: masv, hoten,namsinh
struct Sinhvien
{
    int masv;
    string hoten;
    int namsinh;
};

int main(){
    Sinhvien Dssv[100];//Khai báo 1mangr tên dssv goomg 100 phần tử có kiểu sinh viên
    Sinhvien *Dssv1;//Khai báo 1 con trỏ Dssv1 kiểu sinh viên

    //Cấp phát 50 ô nhớ (tạo mảng 50 phần tử) kiểu Sinhvien
    Dssv1 = new Sinhvien[50];
    //Sử dụng Dssv như 1 mảng kiểu dữ liệu Sinhvien
    Dssv1[0].masv=123;
    Dssv1[0].hoten="VU NGOC TIEN";
    Dssv1[0].namsinh=2005;
    cout<<Dssv1[0].masv<<"\t"<<Dssv1[0].hoten<<"\t"<<Dssv1[0].namsinh<<endl;
    // Giải phóng con ô nhớ con trỏ
     delete [] Dssv1;
     //Tiếp tục thực hiện các công việc khác

}