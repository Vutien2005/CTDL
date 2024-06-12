//su dung bien con tro kieu struct
#include<iostream>
 using namespace std;
 //??nh ngh?a 1 ki?u d? li?u là SinhVien g?m 3 tr??ng: masv,hoten,namsinh
 struct Sinhvien
 {
 	int masv;
 	string hoten;
 	int namsinh;
};
 	int main()
 	{
 		Sinhvien sv1;
 		Sinhvien *ptrSV1;
 		
 		ptrSV1 = &sv1;
 		
 		cout<<"Nhap thong tin sinh vien:"<<endl;
 		cout<<"Ma sv:";
 		cin>>sv1.masv;
 		cin.ignore();
 		cout<<"Ho ten:";
 		getline(cin,sv1.hoten);
 		cout<<"Nam sinh:";
 		cin>>sv1.namsinh;
 		cout<<sv1.masv<<"\t"<<(*ptrSV1).hoten<<"\t"<<ptrSV1->namsinh<<endl;
 		return 0;
 		}