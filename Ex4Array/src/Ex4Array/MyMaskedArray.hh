#include "MyArray.hh"

template <typename A>
class MyArray;
template <typename T>
class MyMaskedArray{
private:
    MyArray<T> *arr;
    MyArray<bool> *mask;
public:
    friend class MyArray<T>;
    MyMaskedArray(){
        arr = nullptr;
        mask = nullptr;
    }
    MyMaskedArray& operator=(const T& e){
        int s = this->arr->x;
        int c = this->arr->y;
        
		for (int i = 0; i < this->arr->x; i++) 
			for (int j = 0; j < this->arr->y; j++)
				if (this->mask->arr[i][j] == true) 
					this->arr->arr[i][j] = e;
    return *this;
    }
    ~MyMaskedArray(){
        arr = nullptr;
        mask = nullptr;
    }
};
