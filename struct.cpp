//Khai báo kiểu sinh viên gồm:MSV,tensv,namsinh
#include<iostream>
using namespace std;
 struct Sinhvien{
        int Masv;
        string Tensv;
        int Namsinh;
    };
    //Nhập vào 1 mảng số nguyên với n phần tử
    void Nhapmang(int a[],int n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
    }
    //Nhập vào 1 mảng sinhvien gồm n phần tử
    void NhapSinhVien(Sinhvien a[],int n){
        for(int i=0;i<n;i++){
            cout<<"Nhap thong tin sinh vien:"<<i+1<<endl;
            cout<<"Ma SV:";
            cin>>a[i].Masv;
            cin.ignore();
            cout<<"Ten SV:";
            getline(cin,a[i].Tensv);
            cout<<"Nam sinh:";
            cin>>a[i].Namsinh;
    

        }
    }
    //Viết hàm In ra danh sách sinh viên
    void Inddsv(Sinhvien a[],int n){
        for(int i=0;i<n;i++){
            cout<<a[i].Masv<<"\t"<<a[i].Namsinh<<"\t"<<a[i].Tensv<<"\n";
        }
    }
int main(){
    Sinhvien dssv[100];
    //Dùng hàm để nhập thông tin 2 sinh viên vào mảng dssv
    NhapSinhVien(dssv,2);
    Inddsv(dssv,2);
   
}