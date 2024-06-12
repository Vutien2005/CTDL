//Cài đặt danh sách bằng con trỏ
#include<iostream>
using namespace std;
struct Sinhvien
{
	int masv;
	string hoten;
	int namsinh;
};
typedef Sinhvien Item; //định ng  hĩa kiểu Item chính là kiểu Sinhvien
struct Node
{
	Item Data;
	Node *Next;
};
typedef Node *List;

//Khởi tạo danh sách
void Init(List &L)
{
	L =NULL;
}
//Kiểm tra danh sách L có trống không? true/false
bool isEmpty(List L)
{
	if(L==NULL)
		return true;
	else
		return false;
}
//Trả về độ dài của danh sách
int len(List L)
{
	int dodai=0;
	while(L!=NULL)
	{
		dodai++;
		L=L->Next;
	}
	return dodai;
}
//tạo và trả về 1 node có data được gán là x
Node * Make_Node(Item x)
{
	Node *p;
	p= new Node;
	p->Data=x;
	p->Next=NULL;
	return p;
}
//chèn 1 phần tử x vào vị trí đầu tiên của danh sách
void Insert_First(List &L, Item x)
{
	Node *p;
	p = Make_Node(x); //gọi hàm để tạo 1 node có data là x
	if (L==NULL)
	{
		L = p;
	}
	else{
		p->Next = L;
		L = p;
	}
}
//hiển thị thông tin trong danh sách
void HienThiDanhSach(List L)
{
	while (L!=NULL)
	{
		cout<<L->Data.masv<<"\t"<<L->Data.hoten<<"\t"<<L->Data.namsinh<<endl;
		L=L->Next;
	}
	
}
//chenf phaanf tuwr cos data la x vao vi tri k
void Insert_k(List &L, Item x, int k)
{
	List L1;
	L1 = L;
	
	int vitri=1;
	while (L1!=NULL && vitri<k-1)//di chuyển L1 đến trước vị trí k
	{
		vitri++;
		L1 = L1->Next;
	}
	Node *p;
	p=Make_Node(x);//tạo node p  với data là x
	p->Next=L1->Next;
	L1->Next = p;
}
void Del_fish(List &L){
	Node *p;
	p=L;
	L=L->Next;
	delete p;
}
//Tìm mã sinh viên trong danh sách
//Trả về vị trí nếu tìm thấy, trả về -1 nếu ko tìm thayas
    int Search(List L, int masv){
        int vitri=0;
        int Timthay=0;
        while(L!=NULL ){
            vitri++;
            if(L->Data.masv==masv){
                Timthay=vitri;
                break;
            }else{
                 L=L->Next;
            }
    return Timthay;
        }
    }
    // Xóa mode thứ k trong danh sách
    void Del_k(List &L,int k)
    {
        Node *L1,*p;
        int vitri=1;
        if(L=NULL){
            cout<<"RaNH SACH RONG";
        }
        else{
                if(k==1)
        {
            p=L;//Lưu lại Node cần xóa để giải phóng
            L=L->Next;
            delete p;
        }
        else
        {
            L1=L;
        while(L1!=NULL & vitri<k-1)//Di chuyển L1 đén vị trí k-1
        {
            vitri++;
            L1=L1->Next;
            
        }
        p=L1->Next;//Lưu lại vị trí cần xóa để giải phóng
        L1->Next=p->Next;
        delete p;//Giải phòng p
        }
        }
        
        
    }
//Menu
void Menu(List L)
{
	int LuaChon;
	
	do
	{
		cout<<"\nCAC CHUC NANG\n";
		cout<<"1. Khoi tao\n";
		cout<<"2. Kiem tra trong\n";
		cout<<"3. Do dai danh sach\n";
		cout<<"4. Chen dau danh sach\n";
		cout<<"5. Chen them phan tu\n";
		cout<<"6. Xoa Phan tu n: \n";
		cout<<"7. Tim ma Sv:\n";
		cout<<"8. Hien thi danh sach\n";
		cout<<"9. Thoat khoi chuong trinh\n";
        cout<<"10. Xóa vi tri:\n";
		cout<<"Moi chon chuc nang (1-9)?";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1://Khoi tao
			{
				Init(L);
				cout<<"Da khoi tao!";
				break;
			}
			case 2://Kiem tra trong
			{
				if (isEmpty(L))
					cout<<"Danh sach trong!";
				else
					cout<<"Danh sach khong trong!";
				break;
			}
			case 3:
			{
				cout<<"Do dai danh sach la: "<<len(L)<<endl;
				break;
			}
			case 4:
			{
				Item x;
				//nhập x ~ nhập 1 sinh viên
				cout<<"Nhap thong tin sinh vien: \n";
				cout<<"Nhap ma sinh vien: ";
				cin>>x.masv;
				cin.ignore();
				cout<<"Nhap ho ten: ";
				getline(cin,x.hoten);
				cout<<"Nhap nam sinh: ";
				cin>>x.namsinh;
				//gọi hàm chèn node có data là x ở đầu danh sách
				Insert_First(L, x);
				break;
			}
			case 5: //chèn phần tử x vào vị trí k
			{
				//nhập vị trí chèn
				cout<<"Hay nhap vi tri can chen: \t";
				
				Item x;
				int k;
				cin>>k;
				//nhập x ~ nhập 1 sinh viên
				cout<<"Nhap thong tin sinh vien: \n";
				cout<<"Nhap ma sinh vien: ";
				cin>>x.masv;
				cin.ignore();
				cout<<"Nhap ho ten: ";
				getline(cin,x.hoten);
				cout<<"Nhap nam sinh: ";
				cin>>x.namsinh;
				//gọi hàm chèn node có data là x ở đầu danh sách
				Insert_k(L, x,k);
				break;
			}
			case 6:{
				Del_fish(L);
				cout<<"Xoa xong";
				break;
			}
            case 7:
            {
                int masv;
                cout<<"Nhap ma sinh vien can tim:";
                cin>>masv;
                int Timthay=Search(L,masv);
                if(Search(L,masv)==0){
                    cout<<"Khong tim thay\n";
                }
                else{
                    cout<<"Tim thay tai vi tri:"<<Timthay<<endl;
                }
            }
			case 8:
			{
				HienThiDanhSach(L);
				break;
			}
			
			case 9:
			{
				cout<<"Tam biet!";
				break;
			}	
            case 10:{
                int k;
                cout<<"Nhap vi tri can xoa:";
                cin>>k;
                Del_k(L,k);
                cout<<"Da xoa";
            }	
		}
	}while(LuaChon!=11);
}
int main()
{
	List L;
	
	//Init(L);
	//cout<<isEmpty(L)<<endl;
	//cout<<"Do dai:"<<len(L);
	Menu(L);
	
	return 0;
}