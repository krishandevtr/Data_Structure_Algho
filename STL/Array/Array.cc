#include <iostream>
#include <stdexcept>
#include <utility> 

template <typename T>
class Array
{
private:
    int size_;
    int capacity_;
    T *data_;

public:
    // Constructor
    Array(int initial_capacity = 1) : size_(0) {
        if (initial_capacity <= 0) {
            initial_capacity = 1;
        }
        capacity_ = initial_capacity;
        data_ = new T[capacity_];
    }


    Array(const Array& other) : size_(other.size_), capacity_(other.capacity_) {
        data_ = new T[capacity_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    // Destructor
    ~Array() {
        delete[] data_;
    }

    // Copy Assignment Operator (using copy-and-swap idiom)
    Array& operator=(Array other) {
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
        std::swap(data_, other.data_);
        return *this;
    }

    void append(const T& value) {
        if (size_ == capacity_) {
            int new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            T* new_data = new T[new_capacity];

            for (int i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }

            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
        }
        data_[size_] = value;
        size_++;
    }

    T pop_back() {
        if (size_ == 0) {
            throw std::out_of_range("pop from empty array");
        }
        size_--;
        return data_[size_];
    }

    int size() const {
        return size_;
    }

    int capacity() const {
        return capacity_;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }
};