#include "SoPhuc.h"

istream& operator>>(istream& stream, SoPhuc& sp)
{
	cout << "Nhap vao phan thuc: ";
	stream >> sp.thuc;
	cout << "Nhap vao phan ao: ";
	stream >> sp.ao;
	return stream;
}

ostream& operator<<(ostream& stream, const SoPhuc& sp)
{
	if (sp.thuc == 0 && sp.ao == 0)
		stream << 0;
	else
	{
		if (sp.thuc != 0)
		{
			stream << sp.thuc;
			if (sp.ao > 0)
				stream << " + ";
		}
		if (sp.ao != 0)
			stream << sp.ao << "i";
	}
	return stream;
}

SoPhuc* soPhucArrIn() {
	SoPhuc* a = (SoPhuc*)arrInit(0, sizeof(SoPhuc)), x;
	while (cin >> x)
	{
		arrPushback((void**)&a, &x);
	}
	cin.clear();
	return a;
}

void soPhucArrOut(SoPhuc* data)
{
	int sz = arr_size(data);
	int itemSize = arr_item_size(data);
	for (int i = 0; i < sz; i++)
	{
		cout << *data << endl;
		data = (SoPhuc*)((char*)data + sizeof(SoPhuc));
	}
}