// Viết chương trình khai báo các hàm để
// thực hiện:
// 1. nhập danh sách số nguyên gồm n phần tử (3<=n<=10)
// 2. Xuất danh sách
// 3. Sắp xếp danh sách theo thứ tự tăng/giảm dần
// 4. Nhập số nguyên k bất kỳ, tìm k có trong danh sách hay
// không. Nếu không, chèn k vào vị trí thích hợp để dãy
// vẫn có thứ tự tăng/giảm dần. In kết quả.
// 5. Tính tổng S các số nguyên tố trong dãy.
// Tìm xoá tất cả các phân tử có giá trị bằng int(sqrt(S))
// trong dãy. In kết  quả.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void Nhap(int *a, int n);
void Xuat(int *a, int n);
bool ascending(int l, int r);
bool descending(int l, int r);
void SX(int *a, int n, bool (*fComp)(int, int) = ascending);
void Chen(int *a, int &n, int k, bool (*fComp)(int, int) = ascending);
bool Ngto(int x);
int TongNgto(int *a, int n);
int TKNP(int *a, int n, int x, bool (*fComp)(int, int) = ascending);
void Xoa(int *a, int &n, int x);
int main()
{
    int *a;
    int n;
    do
    {
        cout << "Nhập n (3<=n<=10):";
        cin >> n;
    } while (n < 3 || n > 10);
    a = new int[n]; // a là mảng động
    cout << "Nhập dãy số nguyên gồm " << n << " phần tử:" << endl;
    Nhap(a, n);
    cout << "Dãy số vừa nhập:";
    Xuat(a, n);
    SX(a, n);
    int k;
    cout << "Nhập k:";
    cin >> k;
    Chen(a, n, k);
    cout << "Dãy số nguyên sau khi chèn k:";
    Xuat(a, n);
    int S = TongNgto(a, n);
    Xoa(a, n, int(sqrt(S)));
    cout << "Dãy số nguyên sau khi xóa phần tử:";
    Xuat(a, n);
    return 0;
}
void Nhap(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i << ":";
        cin >> a[i]; //*(a+i)
    }
}
void Xuat(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
bool ascending(int l, int r)
{
    return (l > r);
}
bool descending(int l, int r)
{
    return (l < r);
}
void SX(int *a, int n, bool (*fComp)(int, int))
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            // if (a[i]>a[j]) {
            // if (a[i] < a[j]) {
            if ((*fComp)(a[i], a[j]))
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}
void Chen(int *a, int &n, int k, bool (*fComp)(int, int))
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (a[i] == k)
            return;
        if ((*fComp)(a[i], k))
            break;
    }
    for (j = n; j > i; j--)
        a[j] = a[j - 1];
    a[i] = k;
    n++;
}
bool Ngto(int x)
{
    for (int i = 2; i < sqrt(x); i++)
        if (x % i == 0)
            return 0;
    return 1;
}
int TongNgto(int *a, int n)
{
    int S = 0;
    for (int i = 0; i < n; i++)
        if (Ngto(a[i]))
            S += a[i];
    return S;
}
int TKNP(int *a, int n, int x, bool (*fComp)(int, int))
{
    int d, c, g;
    d = 0;
    c = n - 1;
    do
    {
        g = (d + c) / 2;
        if (a[g] == x)
            return g;
        else if ((*fComp)(a[g], x))
            c = g - 1;
        else
            d = g + 1;
    } while (d <= c);
    return -1;
}
void Xoa(int *a, int &n, int x)
{
    int i, j;
    i = TKNP(a, n, x);
    if (i == -1)
        return;
    for (j = i; j < n - 1; j++)
        a[j] = a[j + 1];
    n--;
}
