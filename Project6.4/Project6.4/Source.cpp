#include <iostream>
#include <math.h>
#include <string>

using namespace std;

template <class T>
class Vector
{
	T* v;
	int size;
public:
	Vector(int newsize);
	Vector(Vector&);
	~Vector();

	T min();

	T& operator [] (int index);
	Vector& operator = (const Vector&);

	friend ostream& operator << <>(ostream&, Vector&);
	friend istream& operator >> <>(istream&, Vector&);
};

template <class T>
Vector<T>::Vector(int newsize)
{
	v = new T[size = newsize];
	for (int i = 0; i < size; i++)
		v[i] = T();
}

template <class T>
Vector<T>::Vector(Vector<T>& x)
{
	v = new T[size = x.size];
	for (int i = 0; i < size; i++)
		v[i] = x.v[i];
}

template <class T>
Vector<T>::~Vector()
{
	delete[] v;
}

template <class T>
T Vector<T>::min()
{
	T ExtrElem = v[0];
	for (int i = 0; i < size; i++) {
		if (v[i] < ExtrElem) ExtrElem = v[i];
	}
	return ExtrElem;
}

template <class T>
T& Vector<T>::operator [] (int index)
{
	if (index < 0 || index >= size)
	{
		throw exception("Index out of the range");
	}
	return v[index];
}

template <class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& x)
{
	if (this != &x)
	{
		delete[] v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}

template <class T>
istream& operator >> (istream& is, Vector<T>& x)
{
	cout << "Input " << x.size << " elements of Vector" << endl;
	for (int i = 0; i < x.size; i++) {
		cout << "element[" << i << "] = ";
		is >> x.v[i];
	}
	return is;
}

template <class T>
ostream& operator << (ostream& os, Vector<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	os << endl;
	return os;
}

int main()
{
	try
	{
		Vector<double> a(5);
		cin >> a;
		cout << "min element = " << a.min() << endl;
	}

	catch (exception e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}
