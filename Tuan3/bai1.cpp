// Viết hàm tính giải thừa bằng đề quy
#include<iostream>
using namespace std;
int tinhgiaithua(int n){
    if(n==1){
        return 1;
    }
    else{
        return n*tinhgiaithua(n-1);
    }
}
int main(){
    int n;
    cin>>n;
   cout<< tinhgiaithua(n);
    
    return 0;
}