//viết hàm tìm ước chung lớn nhât 
#include<iostream>
using namespace std;
int ucln(int a, int b){
    while (b!=0)
    {
        int temp=b;
        b= a%b;
        a=temp;
    }
    return a;
    
}
int main()
{
    int a, b;
    cout<<"Nhap 2 so a,b:";
    cin>>a>>b;
    cout<<"Ước chung lon nhat la:"<<ucln(a,b);
    return 0;
} 