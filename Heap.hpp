#ifndef HEAP_HPP
#define HEAP_HPP

template<typename T>
class Heap {
    public:
        Heap(unsigned int size, bool max_heap = true);
        ~Heap();
        bool insert(T el);
        bool remove(T el);
        void print();
        T& operator[](unsigned int i);
        unsigned int size();
        unsigned int capacity();
        bool type();
    private:
        unsigned int get_parent(unsigned int i);
        unsigned int get_left(unsigned int i);
        unsigned int get_right(unsigned int i);
        bool swap(unsigned int i, unsigned int j);
        bool heapified(unsigned int i, unsigned int j);
        bool max_heap;
        T* heap;
        unsigned int size_;
        unsigned int capacity_;
};

#include "Heap.tpp"

#endif