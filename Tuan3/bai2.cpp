//Viết hàm tỉnh tổng các số nguyên từ 1 đến n bằng đề quy
#include<iostream>
using namespace std;
int tinhtong(int n){
    if(n==1){
        return 1;
    }
    else{
        return n+tinhtong(n-1);
    }
}
int main(){
    int n;
    cin>>n;
   cout<< tinhtong(n);
    
    return 0;
}