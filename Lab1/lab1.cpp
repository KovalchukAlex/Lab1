#include <iostream>
using namespace std;
void EnterArray(int a[], int n);
void DisplayArray(int a[], int n);
void Swap(int &a, int &b);
int EnterDimention(int n);
int NumberOfElemetsInArray(int a[], int n);
int* NewArray(int* a, int n, int m);
void InTheBinarySystem(int* a, int n);
void BubbleSort(int* a, int n);
int NumberOfOne(double a);
int NumberOfZero(double a);
int main()
{
	const int N = 100;
	int n = EnterDimention(N);
	int l = 0; int r = n - 1;
	int *a = new int[n];
	EnterArray(a, n);
	cout << "Source array" << endl;
	DisplayArray(a, n);
	int m = NumberOfElemetsInArray(a, n);
	int* b = NewArray(a, n, m);
	cout << endl;
	cout << "New Array" << endl;
	DisplayArray(b, m);
	cout << endl;
	int t = n - m;
	cout << endl;
	DisplayArray(a, t);
	cout << endl;
	cout << endl << "In binary system:" << endl;
	InTheBinarySystem(a, t);
	DisplayArray(a, t);
	cout << endl;
	BubbleSort(a, n);
	DisplayArray(a, t);
	system("pause");

}
void EnterArray(int a[], int n)
{
	cout << "Enter Elements" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << (i + 1) << "]=";
		cin >> a[i];
	}

}
void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

}
int EnterDimention(int n)
{
	int k;
	while (true)
	{
		cout << "Enter 0<=n<= " << n << ":" << endl;
		cin >> k;
		if (k>0 && k <= n)
			return k;
	}
}
void Swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
bool IsDataValid(int n)
{
	if (n <= 0) return false;
	return true;
}
int NumberOfElemetsInArray(int* a, int n)
{

	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if ((i % 2) != 1)
		{
			if ((a[i] % 2) != 0 && a[i] < 0)
			{
				m++;
			}
		}
	}
	return m;
}
int* NewArray(int* a, int n, int m)
{
	int* b = new int[m];
	int j = 0;
	for (int i = n - 1; 0 <= i; i--)
	{
		if (((i + 1) % 2) == 1)
		{
			if ((a[i] % 2) != 0 && a[i] < 0)
			{
				b[j] = a[i];
				j++;
				for (int k = i; k < n; k++)
					a[k] = a[k + 1];
			}
		}
	}
	return b;
}
void InTheBinarySystem(int* a, int n)
{
	int t, d;
	for (int *p = a; p < a + n; p++)
	{
		t = 0, d = 1;
		while (*p)
		{
			t += (*p % 2)*d;
			*p = *p / 2;
			d = d * 10;
		}
		*p = t;
	}
}
void BubbleSort(int* a, int n)
{
	{
		for (int i = 0; i < n; i++)
			for (int j = n - 1; j>i; j--)
				if (NumberOfOne(a[j]) - NumberOfZero(a[j]) >NumberOfOne(a[j - 1]) - NumberOfZero(a[j - 1]))
					Swap(a[j], a[j - 1]);
	}
}
int NumberOfOne(double a)
{
	int i = 0;
	int c = a / 2;
	int d = a - c * 2;
	if (a == 1)
	{
		return 1;
	}
	while (c)
	{
		c = a / 2;
		d = a - c * 2;
		if (d == 1)
			i++;
		a = c;
	}
	return i;
}

int NumberOfZero(double a)
{
	int i = 0;
	int c = a / 2;
	int d = a - c * 2;
	if (a == 0)
	{
		return 1;
	}
	while (c)
	{
		c = a / 2;
		d = a - c * 2;
		if (d == 0)
			i++;
		a = c;
	}
	return i;
}