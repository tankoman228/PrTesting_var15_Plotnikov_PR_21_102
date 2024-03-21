#pragma once

template <class T> class Array {

private:

	T* array;
	int length;

public:
	
	Array() {
		length = 0;
	}

	Array(T* array, int length) {
		this->array = array;
		this->length = length;
	}

	int size();

	T get(int index);
	T operator[](int index) {
		return get(index);
	}

	void set(int index, T value);

	~Array() {
		delete[] array;
	}

private:

	void free_memory();
};