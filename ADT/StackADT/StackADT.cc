#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class StackADT {
private:
    std::vector<T> data_;

public:
    void push(const T& value) {
        data_.push_back(value);
    }

    T pop() {
        if (is_empty()) {
            throw std::out_of_range("pop from empty stack");
        }
        T top_element = data_.back();
        data_.pop_back();
        return top_element;
    }

    T& top() {
        if (is_empty()) {
            throw std::out_of_range("top from empty stack");
        }
        return data_.back();
    }
    
    // Alias for top()
    T& peek() {
        return top();
    }

    bool is_empty() const {
        return data_.empty();
    }

    int size() const {
        return data_.size();
    }
    
    // Clears the stack.
    void clear() {
        data_.clear();
    }
    
    // Returns the capacity of the underlying vector.
    int get_capacity() const {
        return data_.capacity();
    }


    const T& operator[](int index) const {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }
    T& operator[](int index) {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Index out of bounds");
        }
        return data_[index];
    }
};