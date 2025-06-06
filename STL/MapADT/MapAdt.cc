#include <iostream>

template <typename K, typename V>
struct Node
{
    K Key;
    V Val;
};
template <typename K, typename V>
class MapAdt
{
private:
    Node<K, V> *data;
    int _size;
    int capacity;

public:
    MapAdt()
    {
        this->capacity = 2;
        this->_size = 0;
        data = new Node<K, V>[capacity];
    }

    void insert(K key, V value)
    {
        // Check if key already exists; if yes, update and return
        for (int i = 0; i < _size; i++)
        {
            if (data[i].Key == key)
            {
                data[i].Val = value;
                return;
            }
        }

        // If capacity is full, resize the array
        if (_size == capacity)
        {
            capacity *= 2;
            Node<K, V> *tempArr = new Node<K, V>[capacity];
            for (int i = 0; i < _size; i++)
            {
                tempArr[i] = data[i];
            }
            delete[] data;
            data = tempArr;
        }

        // Insert the new key-value pair
        data[_size].Key = key;
        data[_size].Val = value;
        _size++;
    }

    bool find(K key)
    {
        for (int i = 0; i < _size; i++)
        {
            if (data[i].Key == key)
                return true;
        }
        return false;
    }

    V get(K key)
    {
        for (int i = 0; i < _size; i++)
        {
            if (data[i].Key == key)
            {
                return data[i].Val;
            }
            return;
        }
    }

void remove(K key)
{
    for (int i = 0; i < _size; i++)
    {
        if (data[i].Key == key)
        {
            // Shift all elements after i to the left
            for (int j = i; j < _size - 1; j++)
            {
                data[j] = data[j + 1];
            }
            _size--; // Decrease the size
            return;
        }
    }
    std::cout << "Key not found: " << key << std::endl;
}

bool isEmpty(){
    return _size==0;
}

}