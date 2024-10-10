#pragma once
#include <iostream>

using namespace std;

struct SinhVien
{
	int MSSV;
	string TenSV;
	double DiemTB;

	void NhapSV();
	void XuatSV();
	bool Compare(SinhVien x);
	void Swap(SinhVien &a, SinhVien &b);
};

