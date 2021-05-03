#include <iostream>
#include <ctime>
using namespace std;

/*


������� ������, ����������� ������� � �������� ���������.
������� ��������� �������:
�	��� ������������� ���������� �������
�	� ���������� ������ ����� K. ������� ������ �� �������� ���������, �������� ������� �� ����������� K
���� ����������� �������  ������������� ��� ���� char � ������������� ��������� ������� ���������� ��������.
������������������ ������ � ������ ������: double, char


*/

template<class X>
void init(X*& arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() * 0.001;
	}
}

void init(char*& arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 'A' + (rand() % (25 - 0 + 1) + 0);
	}
}

template<class X>
void print(X* arr, const int size)
{
	if (size)
	{
		cout << "Array: ";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	else cout << "Required indexes not found...";
}

template<class X, class Y>
int find(const int K, X*& newArr, Y* oldArr, const int oldSize)
{	
	int newSize = 0;
	for (int i = 0; i < oldSize; i++)
	{
		if (oldArr[i] <= K)
		{
			newSize++;
		}
	}

	if (newSize)
	{
		newArr = new X[newSize];
		for (int i = 0, j = 0; i < oldSize; i++)
		{
			if (oldArr[i] <= (double) K)
			{
				newArr[j] = i;
				j++;
			}
		}
	}

	return newSize;
}

int main()
{
	srand(time(0));
	int size;
	cin >> size;

	char* arrChar = new char[size];
	double* arrDouble = new double[size];

	init(arrChar, size);
	init(arrDouble, size);

	print(arrChar, size);
	print(arrDouble, size);

	int* newArrDouble = NULL;
	int K;
	cin >> K;

	int newSize = find(K, newArrDouble, arrDouble, size);
	print(newArrDouble, newSize);

	delete[] arrChar;
	delete[] arrDouble;
	delete[] newArrDouble;
}