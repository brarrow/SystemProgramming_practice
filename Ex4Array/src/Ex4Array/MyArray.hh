#pragma once
#include <exception>
#include <iostream>
#include "MyMaskedArray.hh"

template <typename T>
class MyArray
{
  private:
	int x;
	int y;
	T **arr;
	
	template <typename Head>
	void set(int i, int j, Head head)
	{
		arr[i][j] = head;
	}
	
	template <typename Head, typename... Tail>
	void set(int xInd, int yInd, Head head, Tail... tail)
	{
		set(xInd, yInd, head);
		if (xInd + 1 == x && yInd + 1 == y)
			return;
		else if (yInd + 1 == y)
			set(xInd + 1, 0, tail...);
		else
			set(xInd, yInd + 1, tail...);
	}

  public:
	template <typename M>
	friend class MyMaskedArray;
	
	MyArray()
	{
		arr = nullptr;
		x = 0;
		y = 0;
	}
	
	MyArray(int i, int j)
	{
		x = i;
		y = j;
		arr = new T *[x];
		for (i = 0; i < x; i++)
			arr[i] = new T[y];
	}
	
	MyArray(MyArray &a)
	{
		y = a.y;
		x = a.x;
		arr = new T *[x];
		for (int i = 0; i < x; i++)
		{
			arr[i] = new T[y];
			for (int j = 0; j < y; j++)
				arr[i][j] = a.arr[i][j];
		}
	}
	
	MyArray(MyArray &&a)
	{
		arr = a.arr;
		y = a.y;
		x = a.x;
		a.arr = nullptr;
		a.y = 0;
		a.x = 0;
	}

		
	template <typename... Tail>
	void setMat(int xInd, int yInd, Tail... tail)
	{
		x = xInd;
		y = yInd;
		arr = new T *[x];
		for (int i = 0; i < x; i++)
			arr[i] = new T[y];
		set(0, 0, tail...);
	}
	
	MyArray &operator=(const MyArray &a)
	{
		delete[] this->array;
		y = a.y;
		x = a.x;
		arr = new T *[x];
		for (int i = 0; i < x; i++)
		{
			arr[i] = new T[y];
			for (int j = 0; j < y; j++)
				arr[i][j] = a.arr[i][j];
		}
		return *this;
	}
	
	MyArray &operator=(MyArray &&a)
	{
		delete[] a;
		y = a.y;
		x = a.x;
		arr = a.arr;
		a.arr = nullptr;
		a.x = 0;
		a.y = 0;
		return *this;
	}
	
	template <typename... P>
	MyArray(int x, int y, P... args)
	{
		this->x = x;
		this->y = y;
		arr = new T *[x];
		for (int i = 0; i < x; i++)
			arr[i] = new T[y];
		set(0, 0, args...);
	}
	
	MyArray operator+(const MyArray &a)
	{
		int x = a.x;
		int y = a.y;
		MyArray MyArray(a.x, a.y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				MyArray(i, j) = this->arr[i][j] + a.arr[i][j];
		return MyArray;
	}
	
	MyArray operator-(const MyArray &a)
	{
		int x = a.x;
		int y = a.y;
		MyArray MyArray(a.x, a.y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				MyArray(i, j) = this->arr[i][j] - a.arr[i][j];
		return MyArray;
	}
	
	MyArray operator*(const MyArray &a)
	{
		int x = a.x;
		int y = a.y;
		MyArray MyArray(a.x, a.y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				MyArray(i, j) = this->arr[i][j] * a.arr[i][j];
		return MyArray;
	}
	
	MyArray operator/(const MyArray &a)
	{
		int x = a.x;
		int y = a.y;
		MyArray MyArray(a.x, a.y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				MyArray(i, j) = this->arr[i][j] / a.arr[i][j];
		return MyArray;
	}
	
	MyArray operator%(const MyArray &a)
	{
		int x = a.x;
		int y = a.y;
		MyArray MyArray(a.x, a.y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				MyArray(i, j) = this->arr[i][j] % a.arr[i][j];
		return MyArray;
	}
	
	MyArray<bool> operator==(const MyArray &a)
	{
		int x = a.x;
		int y = a.y;
		MyArray<bool> MyArray(a.x, a.y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				MyArray(i, j) = this->arr[i][j] == a.arr[i][j];
		return MyArray;
	}
	
	MyArray<bool> operator!=(const MyArray &a)
	{
		int x = a.x;
		int y = a.y;
		MyArray<bool> MyArray(a.x, a.y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				MyArray(i, j) = this->arr[i][j] != a.arr[i][j];
		return MyArray;
	}
	
	MyArray<bool> operator>(const MyArray &a)
	{
		int x = a.x;
		int y = a.y;
		MyArray<bool> MyArray(a.x, a.y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				MyArray(i, j) = this->arr[i][j] > a.arr[i][j];
		return MyArray;
	}
	
	MyArray<bool> operator<(const MyArray &a)
	{
		int x = a.x;
		int y = a.y;
		MyArray<bool> MyArray(a.x, a.y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				MyArray(i, j) = this->arr[i][j] < a.arr[i][j];
		return MyArray;
	}
	
	MyArray<bool> operator>=(const MyArray &a)
	{
		int x = a.x;
		int y = a.y;
		MyArray<bool> MyArray(a.x, a.y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				MyArray(i, j) = this->arr[i][j] >= a.arr[i][j];
		return MyArray;
	}
	
	MyArray<bool> operator<=(const MyArray &a)
	{
		int x = a.x;
		int y = a.y;
		MyArray<bool> MyArray(a.x, a.y);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				MyArray(i, j) = this->arr[i][j] <= a.arr[i][j];
		return MyArray;
	}
	
	T &operator()(const int &i, const int &j) { return arr[i][j]; }

	MyMaskedArray<T> operator()(MyArray<bool> &mask)
	{
		MyMaskedArray<T> res;
		res.arr = this;
		res.mask = &mask;
		return res;
	}

	~MyArray()
	{
		for (int i = 0; i < x; i++)
			delete[] arr[i];
		delete[] arr;
	}
};
