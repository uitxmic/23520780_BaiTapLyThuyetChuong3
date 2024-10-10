#include "SinhVien.h"
#include <string>


void SinhVien::NhapSV()
{
	cout << "Nhap ten Sinh Vien:";
	
	getline(cin, TenSV);
	cout << "Nhap MSSV: ";
	cin >> MSSV;
	cout << "Nhap diem TB: ";
	cin >> DiemTB;
	cin.ignore();
}

void SinhVien::XuatSV()
{
	cout << "Ten SV: " << TenSV << ' ';
	cout << " MSSV: " << MSSV << ' ';
	cout << " Diem TB: " << DiemTB << '\n';
}

bool SinhVien::Compare(SinhVien x)
{
	return (TenSV.compare(x.TenSV) == 0) && MSSV == x.MSSV && DiemTB == x.DiemTB;
}

void SinhVien::Swap(SinhVien &a, SinhVien &b)
{
	SinhVien tmp;
	tmp = a;
	a = b;
	b = tmp;
}
