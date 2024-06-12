/* Sử dụng con trỏ để thực hiện bài sau:
   1. Định nghĩa 1 kiểu dữ liệu NhanVien gồm các trường sau: maNV, tenNV, hệ số lương, tiền lương
   VD: 111, Dau Hai Phong, 5.5, 1000
   2. Viết hàm nhập 1 danh sách nhân viên gồm n phần tử
   3. Viết hàm in ra 1 danh sách nhân viên gồm n phần tử
   4. viết hàm trả về tổng lương của danh sách nhân viên gồm n phần tử
   5. Viết hàm main sử dụng các hàm trên
*/
# include <iostream>
using namespace std;
struct Nhanvien
{
    int MaNV;
    string TenNV;
    double Hesoluong;
    double tienluong;
};
void Nhap(Nhanvien *a, int n){
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin nhan vien thu "<<i+1<<endl;
        cout<<"Ma NV:";
        cin>>a[i].MaNV;
        cin.ignore();
        cout<<"Ho ten:";
        getline(cin,a[i].TenNV);
        cout<<"He so luong:";
        cin>>a[i].Hesoluong;
        cout<<" So tien luong:";
        cin>>a[i].tienluong;
  }
}
void Inmang(Nhanvien *a, int n){
    for(int i=0; i<n ;i++){
        cout<<a[i].MaNV<<"\t"<<a[i].TenNV<<"\t"<<a[i].Hesoluong<<"\t"<<a[i].tienluong<<endl;
    }
}
void TongLuong(Nhanvien *a, int n){
    int tien =0;
    for(int i=0;i<n;i++){
        tien+= a[i].tienluong;
    }
    cout<<"Tong so tien la:"<<tien;
}

 int main(){
    int n;
    cin>>n;
     Nhanvien *a;
    //SỬ dụng hàm nhập để nhập 3 phần tử kiểu Sinhvien
    a = new Nhanvien[n];
    Nhap(a,n);
    Inmang(a,n);
    TongLuong(a,n);
    return 0;
 }