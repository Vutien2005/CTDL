//Sử dụng con trỏ 
// viết hàm nhập mảng Sinh viên goomg n phần tử
// Viết hàm in mảng Sinh viên gồm n phần tử
#include<iostream>
using namespace std;
struct Sinhvien
{
    int masv;
    string hoten;
    int namsinh;
};
//void Nhap(int a[],int n)
void Nhap(Sinhvien *a, int n){
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin sinh vien thu "<<i+1<<endl;
        cout<<"Ma SV:";
        cin>>a[i].masv;
        cin.ignore();
        cout<<"Ho ten:";
        getline(cin,a[i].hoten);
        cout<<"Nam sinh:";
        cin>>a[i].namsinh;
    }
}
void Inmang(Sinhvien *a, int n){
    for(int i=0; i<n ;i++){
        cout<<a[i].masv<<"\t"<<a[i].hoten<<"\t"<<a[i].namsinh<<endl;
    }
}
int main()
{
    Sinhvien *a;
    //SỬ dụng hàm nhập để nhập 3 phần tử kiểu Sinhvien
    a = new Sinhvien[3];
    Nhap(a,3);
    Inmang(a,3);
    return 0;
} 
