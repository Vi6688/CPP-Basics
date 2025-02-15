#include <iostream>

namespace v
{
    using namespace std;
    template <typename T>
    class Vector
    {
    private:
        T *data;
        /* data */
        size_t capacity;
        size_t size;

    public:
        Vector() : data(nullptr)
        {
        }
        Vector(std::initializer_list<T> list)
        {
            data = new T[list.size()];
            size = list.size();
            capacity = size;
            auto it = list.begin();
            for (size_t i = 0; i < size; i++)
            {
                data[i] = *it;
                it++;
            }
        }
        void resize(size_t newCapacity)
        {
            T *newData = new T[newCapacity];
            for (size_t i = 0; i < size; ++i)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
            
        }
        ~Vector()
        {
            delete[] data;
        }
        Vector(const Vector &other) : data(nullptr), size(0), capacity(0)
        {
            data = new T[other.capacity];
            capacity = other.capacity;
            size = other.size;
            for (size_t i = 0; i < size; ++i)
            {
                data[i] = other.data[i];
            }
        }
        Vector(const size_t newCapacity)
        {
            data = new T[newCapacity];
            capacity = newCapacity;
            size = newCapacity;
        }
        Vector &operator=(const Vector &other)
        {
            if (this != &other)
            {
                delete[] data;
                data = new T[other.capacity];
                capacity = other.capacity;
                size = other.size;
                for (size_t i = 0; i < size; ++i)
                {
                    data[i] = other.data[i];
                }
            }
            return *this;
        }

        void push_back(const T &value)
        {
            if (size >= capacity)
            {
                resize(capacity == 0 ? 1 : capacity * 2); // Double the capacity
            }
            data[size++] = value;
        }
        void pop_back()
        {
            if (size > 0)
            {
                --size;
            }
            else
            {
                throw std::out_of_range("Vector is empty");
            }
        }
        T &operator[](size_t index)
        {
            if (index >= size)
            {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }
        const T &operator[](size_t index) const
        {
            if (index >= size)
            {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }
        size_t getSize() const
        {
            return size;
        }
        size_t getCapacityy() const
        {
            return capacity;
        }
        bool isEmpty() const
        {
            return size == 0;
        }
        // friend std::ostream &operator<<(std::ostream &os,const T &value)
        // {
        //     os << value;
        //     return os;
        // }
        friend std::ostream &operator<<(std::ostream &os, const Vector &vec)
        {
            for (size_t i = 0; i < vec.size; ++i)
            {
                os << vec.data[i] << " ";
            }
            return os;
        }
        // friend std::istream &operator<<(std::ostream &os,const Vector &vec)
        // {
        //     os >> vec.data;
        //     return os;
        // }
        void print() const
        {
            for (size_t i = 0; i < size; ++i)
            {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        }
    };
    template <typename T>
    using AnyArray =  Vector<T>;
}