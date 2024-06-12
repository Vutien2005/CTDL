//Khai báo kiểu sinh viên gồm:MSV,tensv,namsinh
#include<iostream>
using namespace std;
 struct Sinhvien{
        int Masv;
        string Tensv;
        int Namsinh;
    };
int main(){
   Sinhvien sv1,sv2;
   //Nhập cho biến sv1
   cout<<"Nhap ma sinh vien:";
   cin>>sv1.Masv;
   cin.ignore();
   cout<<"Nhap vao ten sinh vien:";
   getline(cin,sv1.Tensv);
   cout<<"Nhap nam sinh:";
   cin>>sv1.Namsinh;
   cout<<sv1.Masv<<"\t"<<sv1.Tensv<<"\t"<<sv1.Namsinh<<"\n";
}