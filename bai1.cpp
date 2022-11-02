#include <iostream>
#include <set>
#include <algorithm>
#define max 100
using namespace std;
int main()
{
  int n;
  cout << "Nhap so phan tu: ";
  cin >> n;

  int *a = new int[max];
  set<int> b;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++)
  {
    int value;
    cin >> value;
    b.insert(value);
  }
  sort(a);
  sort(b);
  return 0;
}
