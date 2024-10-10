#include <iostream>
#include "LIST.h";
#include "Node.h"
#include "SinhVien.h"

using namespace std;

int main()
{
	LIST l;
	l.CreateList(l);
	// 2. Nhap danh sach cac SV, them vao o dau
	while (true)
	{
		SinhVien x;
		x.NhapSV();
		if (x.TenSV == " ") break; // dung neu TenSV = khoang trang
		Node* p = Node::CreateNode(x);
		l.AddHead(l, p);
	}
	cout << "The list of student is: \n";
	l.DisplayList();
	// 3. Tim SV co trong danh sach hay khong
	SinhVien Tim;
	Tim.NhapSV();
	Node* foundNode = l.Search(Tim);
	if (foundNode != NULL)
	{
		cout << "Tim thay sinh vien trong danh sach.\n";
		cout << "Thong tin sinh vien la.\n";
		Tim.XuatSV();
		cout << '\n';
	}
	else
	{
		cout << "Khong tim thay sinh vien trong danh sach!\n\n";
	}
	// 4. Xoa SV nhap vao tu ban phim
	SinhVien Xoa;
	Xoa.NhapSV();
	int ktra = l.RemoveX(Xoa);
	if (ktra)
	{
		cout << "Da xoa thanh cong sinh vien!\n";
		cout << "Danh sach sinh vien duoc cap nhat lai:\n";
		l.DisplayList();
		cout << '\n';
	}
	else
		cout << "Khong tim thay sinh vien de xoa\n\n";
	// 5. Danh sach cac sinh vien co Diem TB >= 5.0
	l.LietKe();
	cout << '\n';
	// 6. Xep loai sinh vien
	cout << "Xep loai hoc luc cac sinh vien nhu sau\n";
	l.XepLoai();
	// 7. Sắp xếp và in ra danh sách sinh viên tăng theo điểm trung bình.
	l.SelectionSort();
	cout << "Danh sach sinh vien sau khi duoc sap xep\n";
	l.DisplayList();
	cout << '\n';
	// 8. Chèn một sinh viên vào danh sách sinh viên tăng theo điểm trung bình nói trên,
	// sao cho sau khi chèn danh sách sinh viên vẫn tăng theo điểm trung bình
	SinhVien Chen;
	Chen.NhapSV();
	l.Insert(Chen);
	cout << "\nDanh sach sinh vien sau khi chen\n";
	l.DisplayList();
	return 0;
}