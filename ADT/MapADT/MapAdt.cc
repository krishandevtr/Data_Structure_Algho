#include <iostream>
#include <vector>
#include <optional> 

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
    std::vector<Node<K, V>> data;

public:
    MapAdt() = default; // no need for manual constructor

    void insert(const K& key, const V& value)
    {
        // Check if key already exists; if yes, update and return
        for (auto& node : data)
        {
            if (node.Key == key)
            {
                node.Val = value;
                return;
            }
        }

        // Insert new key-value pair
        data.push_back({key, value});
    }

    bool find(const K& key) const
    {
        for (const auto& node : data)
        {
            if (node.Key == key)
                return true;
        }
        return false;
    }

    std::optional<V> get(const K& key) const
    {
        for (const auto& node : data)
        {
            if (node.Key == key)
            {
                return node.Val; // return wrapped in optional
            }
        }
        return std::nullopt; // return empty if not found
    }

    void remove(const K& key)
    {
        for (auto it = data.begin(); it != data.end(); ++it)
        {
            if (it->Key == key)
            {
                data.erase(it); // vector handles shifting
                return;
            }
        }
        std::cout << "Key not found: " << key << std::endl;
    }

    bool isEmpty() const
    {
        return data.empty();
    }

    int size() const
    {
        return static_cast<int>(data.size());
    }
};
