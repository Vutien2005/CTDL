# include<iostream>
using namespace std;
int main()
{
    int so = -9;//Biến số kiểu int có giá trị là 9
    int *ptr;// Khai báo 1 biến con trỏ ptr chứa địa chỉ kiểu int
   
    // VD SAI: ptr = so;// ==>Sai vi trí, vì gán giá trị 9 cho biến con trỏ chỉ được địa chỉ
   ptr = &so;
    cout<<"so:"<<so<<endl;// in ra giá trị của biến số
    cout<<"dia chi:"<<&so<<endl;// in ra địa chỉ của biến số
    cout<<"ptr:"<<ptr<<endl;//in ra giá trị của con trỏ ptr
    cout<<"&ptr:"<<&ptr<<endl;//in ra địa chỉ của con trỏ ptr
    cout<<"*ptr:"<<*ptr;//in giá trị tại địa chỉ ptr đang trỏ tới (Lưu trữ)
    return 0;
} 
