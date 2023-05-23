#include <iostream>
#pragma once

template<typename T>
class Vector
{
    static const size_t DEFAULT_CAPACITY = 8;
    T* collection = nullptr;
    size_t count = 0;
    size_t capacity = DEFAULT_CAPACITY;

    private:

        void CopyMemberData(const Vector<T>& vector)
        {
            capacity = vector.capacity;
            count = vector.count;
            collection = new T[capacity];
            for (size_t i = 0; i < count; i++)
                collection[i] = vector.collection[i];      
        }

        void MoveMemberData(Vector<T>&& vector)
        {
            this->capacity = vector.capacity;
            this->count = vector.count;
            this->collection = vector.collection;
            vector.collection = nullptr;
        }

        void FreeMemberData()
        {
            delete[] collection;
            collection = nullptr;
        }

        void Resize(size_t size)
        {
            capacity = size;
            T* newCollection = new T[capacity];
            for (size_t i = 0; i < count; i++)
                newCollection[i] = collection[i];                
            FreeMemberData();
            collection = newCollection;
        }

    public:
        Vector()
        {
            collection = new T[capacity];
        }

        Vector(size_t capacity)
        {
            this->capacity = capacity;
            count = 0;
            collection = new T[capacity];
        }

        Vector(size_t count, const T& defaultValue)
        {
            if (count > capacity)
                capacity = count * 2;           
            this->count = count;
            collection = new T[capacity];
            for (size_t i = 0; i < count; i++)
                collection[i] = defaultValue;          
        }

        Vector(const T* collection, size_t count)
        {
            capacity = count * 2;
            this->count = count;
            this->collection = new T[capacity];
            for (size_t i = 0; i < count; i++)
                this->collection[i] = collection[i];      
        }

        Vector(const Vector<T>& vector)
        {
            CopyMemberData(vector);
        }

        Vector(Vector<T>&& vector)
        {
            MoveMemberData(vector);
        }

        const Vector<T>& operator=(const Vector<T>& vector)
        {
            if (this != &vector)
            {
                FreeMemberData();
                CopyMemberData(vector);
            }
            return *this;
        }

        const Vector<T>& operator=(Vector<T>&& vector)
        {
            if (this != &vector)
            {
                FreeMemberData();
                MoveMemberData(vector);
            }
            return *this;
        }

        const T& operator[] (unsigned index) const
        {
            if (index >= capacity)
                throw 0;
            
            return collection[index];
        }

        T& operator[] (unsigned index)
        {
            if (index >= capacity)
                throw 0;
            
            return collection[index];
        }

        
        void PushBack(const T& item)
        {
            if (count == capacity)
                throw 0;
            if (count == capacity)
                Resize(capacity * 2);
            
            collection[count++] = item;
        }

        void InsertAt(unsigned index, const T& item)
        {
            if (index >= count)
                throw 0;
            if (count == capacity)
                Resize(capacity * 2);
            
            for (int i = count; i > index; i--)
                collection[i] = collection[i - 1];

            count++;
            collection[index] = item;
        }

        void InsertAt(unsigned index, T&& item)
        {
            if (index >= count)
                throw 0;
            
            if (count == capacity)
                Resize(capacity * 2);     

            for (int i = count; i > index; i--)
                collection[i] = collection[i - 1];
            
            count++;
            collection[index] = std::move(item);
        }

        void RemoveAt(unsigned index)
        {
            if (index >= count)
                throw 0;
            if (count <= capacity / 4)
                Resize(capacity / 2);
            for (unsigned i = index; i < count - 1; i++)
                collection[i] = collection[i+1];
            count--;
        }

        void RemoveBack()
        {
            if (count <= capacity / 4)
                Resize(capacity / 2);  
            count--;
        }

        void Clear()
        {
            count = 0;
        }

        friend std::ostream& operator <<(std::ostream& stream, const Vector<T>& vector)
        {
            stream <<"{ ";
            for (size_t i = 0; i < vector.count; i++)
                stream << vector.collection[i] << (i != vector.count - 1 ? ", ":"");
            stream <<" }"<< std::endl;
            return stream;
        }

        ~Vector()
        {
            FreeMemberData();
        }
};
