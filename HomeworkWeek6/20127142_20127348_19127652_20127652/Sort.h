#ifndef SORT_H
#define SORT_H

template <class T>
void sort(T arr[], int n, bool(*compareCriteria)(T a, T b))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (compareCriteria(arr[i], arr[j]))
			{
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template <class T>
bool ascendingCompare(T a, T b)
{
	return a > b;
}

template <class T>
bool descendingCompare(T a, T b)
{
	return a < b;
}

#endif