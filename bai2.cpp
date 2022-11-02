#include <iostream>
using namespace std;

struct students
{
  string hoVaTen;
  int maSo, namSinh, ngayNghi;
  float diemTrungBinh;

  students operator=(students x)
  {
    this->hoVaTen = x.hoVaTen;
    this->maSo = x.maSo;
    this->namSinh = x.namSinh;
    this->ngayNghi = x.ngayNghi;
    this->diemTrungBinh = x.diemTrungBinh;
    return *this;
  }
  students *operator+(students *sv)
  {
    int len = sizeof(sv) + 1;
    students *sv_new = new students[len];
    for (int i = 0; i < sizeof(sv); i++)
    {
      sv_new[i] = sv[i];
    }
    cout << sv_new[0].hoVaTen;
    sv_new[len - 1] = *this;
    cout << sv_new[len - 1].hoVaTen;
    return sv_new;
  }

  students *operator-(students *sv)
  {
    int len = sizeof(sv) - 1;
    students *sv_new = new students[len];
    for (int i = 0; i < sizeof(sv) - 1; i++)
    {
      sv_new[i] = sv[i];
    }
    return sv_new;
  }

  int &operator()(int maSo, students *st)
  {
    int index = -1;
    for (int i = 0; i < sizeof(st); i++)
    {
      if (st->maSo == maSo)
      {
        index = i;
      }
    }
    return index;
  }
};

istream &operator>>(istream &in, students &st)
{
  cout << "Nhap ma so sinh vien: ";
  in >> st.maSo;
  cout << "Nhap ho va ten sinh vien: ";
  fflush(stdin);
  getline(cin, st.hoVaTen);
  cout << "Nhap nam sinh: ";
  in >> st.namSinh;
  cout << "Nhap diem trung binh: ";
  in >> st.diemTrungBinh;
  cout << "Nhap so ngay nghi: ";
  in >> st.ngayNghi;
  return in;
}

ostream &operator<<(ostream &out, students &st)
{
  cout << st.maSo << " - " << st.hoVaTen << " - " << st.namSinh << " - " << st.diemTrungBinh << " - " << st.ngayNghi << endl;
  return out;
}

void nhapSinhVien(students *st, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "Sinh vien thu " << i + 1 << ": \n";
    cin >> st[i];
  }
}

void xuatSinhVien(students *st, int n)
{
  cout << "Thong tin cua sinh vien la: \n";
  for (int i = 0; i < n; i++)
  {
    cout << st[i];
  }
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
void sapXepSinhVienTang(students *st, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (st[i].diemTrungBinh > st[j].diemTrungBinh)
      {
        swap(st[i], st[j]);
      }
    }
  }
  xuatSinhVien(st, n);
}

void sapXepSinhVienGiam(students *st, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (st[i].diemTrungBinh < st[j].diemTrungBinh)
      {
        swap(st[i], st[j]);
      }
    }
  }
  xuatSinhVien(st, n);
}

int main()
{
  int n, co;

  cout << "Nhap so luong sinh vien: ";
  cin >> n;

  students *st = new students[n];

  nhapSinhVien(st, n);
  cout << "Thong tin cua sinh vien la: \n";
  xuatSinhVien(st, n);

  cout << "\nSinh vien sau khi sap xep tang dan la: ";
  sapXepSinhVienTang(st, n);
  cout << "\nSinh vien sau khi sap xep giam dan la: ";
  sapXepSinhVienGiam(st, n);

  students sv;
  cin >> sv;

  delete[] st;
  return 0;
}
