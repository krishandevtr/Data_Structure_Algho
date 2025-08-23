#include <iostream>
#include <vector>
#include <algorithm> // For std::lower_bound and std::find

template <typename T>
class SetADT
{
private:
    std::vector<T> data_;

public:
    void add(const T &value)
    {

        auto it = std::lower_bound(data_.begin(), data_.end(), value);

        // Check if the element already exists
        if (it == data_.end() || *it != value)
        {
            // Insert the new element at the correct sorted position
            data_.insert(it, value);
        }
    }

    // Removes an element from the set.
    bool remove(const T &value)
    {
        // Use std::lower_bound for a fast binary search
        auto it = std::lower_bound(data_.begin(), data_.end(), value);

        // Check if the element was found and if it's the right one
        if (it != data_.end() && *it == value)
        {
            // Erase the element
            data_.erase(it);
            return true;
        }
        return false;
    }

    // Checks if an element exists in the set.
    bool contains(const T &value) const
    {
        auto it = std::lower_bound(data_.begin(), data_.end(), value);
        return (it != data_.end() && *it == value);
    }

    // Returns the number of elements in the set.
    int size() const
    {
        return data_.size();
    }

    // Checks if the set is empty.
    bool is_empty() const
    {
        return data_.empty();
    }

    // Clears all elements from the set.
    void clear()
    {
        data_.clear();
    }

    // Imitating custom begin
    // Nothing crazy the const_interator is method inside the std::vector , using this method we are returning the first memory address of the block
    //  auto it = std::find(my_set.begin(), my_set.end(), 20); this is the goal
    typename std::vector<T>::const_iterator begin() const
    {
        return data_.begin();
    }
    // Demonstration of end ,
    typename std::vector<T>::const_iterator end() const
    {
        return data_.end();
    }
};