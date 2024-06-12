#include <bits/stdc++.h>
using namespace std;
// Tạo một danh sách rỗng
int truy_xuat(int *a, int n, int vi_tri)
{
    if (vi_tri < 0 || vi_tri >= n)
    {
        return -1;
    }
    else
    {
        return a[vi_tri];
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << truy_xuat(a, n, x) << endl;
    delete[] a;
}