void InputArray_1D(int*& a, int& n)
{
  a = new int[n];
}

void FreeArray(int*& a)
{
for (int i = 0; &a[i] != nullptr; i++)
		delete[]a;
}

void OutputArray_1D(int* a, int n)
{

}
