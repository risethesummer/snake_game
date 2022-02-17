void InputArray_1D(int*& a, int& n)
{

}

void FreeArray(int*& a)
{
  for (int i = 0; i < sizeof(a); i++)
		delete[]a;
}

void OutputArray_1D(int* a, int n)
{

}
