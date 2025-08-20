#include <iostream>
#include <vector>

class QueueADT
{
private:
    std::vector<int> data;
    int front;
    int rear;
    int capacity;
    int count;
    const bool isCircular; 

public:
    explicit QueueADT(int size = 100, bool circular = true)
        : data(size), front(0), rear(0), capacity(size), count(0), isCircular(circular) {}

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }

    void enqueue(int val)
    {
        if (isFull())
        {
            std::cout << "Queue is full!\n";
            return;
        }
        data[rear] = val;

        if (isCircular)
            rear = (rear + 1) % capacity; // circular increment
        else
            rear++; // linear increment

        count++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty!\n";
            return -1;
        }

        int val = data[front];

        if (isCircular)
            front = (front + 1) % capacity; // circular increment
        else
            front++; // linear increment

        count--;
        return val;
    }

    int peek() const
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty!\n";
            return -1;
        }
        return data[front];
    }

    int size() const { return count; }
    bool circular() const { return isCircular; }
};
