#include <malloc.h>
#include <memory.h>
#include <iostream>
using namespace std;

struct SoPhuc
{
	int thuc = 0, ao = 0;
};

int memSize(int nItem, int szItem)
{
	return 8 + nItem * szItem;
}

void* data_address(void* origin_address)
{
	return (char*)origin_address + 8;
}

void* origin_address(void* data_address)
{
	return (char*)data_address - 8;
}

void* size_item_address(void* data_address)
{
	return (char*)data_address - 4;
}

void* arrInit(int nItem, int szItem)
{
	int sz = memSize(nItem, szItem);
	void* aOrigin = malloc(sz);
	if (aOrigin != NULL) {
		//memset(aOrigin, 0, sz);
		void* aData = data_address(aOrigin);
		*(int*)origin_address(aData) = nItem;
		*(int*)size_item_address(aData) = szItem;
		return aData;
	}
	return NULL;

}

int arr_size(void* data_address)
{
	return *((int*)origin_address(data_address));
}

int arr_item_size(void* data_address)
{
	return *((int*)size_item_address(data_address));
}

void* arrResize(void* aData, int nItem) {
	if (aData == NULL || nItem < 0) return NULL;
	void* aOrigin = origin_address(aData);
	int sizeItem = *(int*)size_item_address(aData);
	int sz = memSize(nItem, sizeItem);
	void* aNew = realloc(aOrigin, sz);
	if (aNew != NULL) {
		aData = data_address(aNew);
		*(int*)origin_address(aData) = nItem;
		return aData;
	}
	return NULL;
}


int arrPushback(void** aData, void* x) {
	int nItem = arr_size(*aData), szItem = arr_item_size(*aData);
	void* aNew = arrResize(*aData, 1 + nItem);
	if (aNew != NULL) 
	{
		memmove((char*)aNew + nItem * szItem, x, szItem);
		*aData = aNew;
		return 1;
	}
	return 0;
}

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


void* arrPopback(void** aData) {
	int nItem = arr_size(*aData), szItem = arr_item_size(*aData);
	void* x = malloc(szItem);
	if (*aData != NULL && nItem > 0) {
		nItem--;
		memmove(x, (char*)(*aData) + nItem * szItem, szItem);
		void* aNew = arrResize(*aData, nItem);
		if (aNew != NULL) *aData = aNew;
	}
	return x;
}

void arrFree(void* aData) {
	if (aData != NULL) 
		free(origin_address(aData));
}


int main()
{
	cout << "Input complex items\n"; 
	SoPhuc* B = soPhucArrIn(); 
	SoPhuc* x = (SoPhuc*)arrPopback((void**)&B);
	cout << "After pop: \n"; 
	soPhucArrOut(B); 
	cout << "Popped element : " << *x << endl;
	free(x); 
	arrFree(B);
}
