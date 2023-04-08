#ifndef HEAP_TPP
#define HEAP_TPP

template<typename T>
Heap<T>::Heap(unsigned int cap, bool max_heap) : max_heap(max_heap), size_(0), capacity_(cap), heap(new T[cap]) {}

template<typename T>
Heap<T>::~Heap() {
    delete[] this->heap;
}

template<typename T>
bool Heap<T>::insert(T el) {
    if (this->size_ == this->capacity_)
        return false;

    this->heap[this->size_] = el;
    
    // "Bubble up"
    for (unsigned int i = this->size_; !this->heapified(this->get_parent(i), i); i = this->get_parent(i))
        swap(i, this->get_parent(i));
    
    this->size_++;

    return true;
}

template<typename T>
T& Heap<T>::operator[](unsigned int i) {
    return this->heap[i];
}

template<typename T>
bool Heap<T>::remove(T el) {
    for (unsigned int i = 0; i < this->size_; i++) {
        if (this->heap[i] == el) {
            
            this->size_--;
            this->swap(i, this->size_);

            // "Bubble down"
            while ( !this->heapified(i, this->get_left(i)) || !this->heapified(i, this->get_right(i)) ) {
                if (this->heapified(this->get_left(i), this->get_right(i))) {
                    this->swap(i, this->get_left(i));
                    i = this->get_left(i);
                }
                else {
                    this->swap(i, this->get_right(i));
                    i = this->get_right(i);
                }
            }

            return true;
        }
    }
    return false;
}

template<typename T>
unsigned int Heap<T>::size() {
    return this->size_;
}

template<typename T>
unsigned int Heap<T>::capacity() {
    return this->capacity_;
}

template<typename T>
bool Heap<T>::type() {
    return this->max_heap;
}

template<typename T>
unsigned int Heap<T>::get_parent(unsigned int i) {
    return (i > 0) ? (i - 1)/2 : i;
}

template<typename T>
unsigned int Heap<T>::get_left(unsigned int i) {
    return (2*i + 1 < this->size_) ? 2*i + 1 : i;
}

template<typename T>
unsigned int Heap<T>::get_right(unsigned int i) {
    return (2*i + 2 < this->size_) ? 2*i + 2 : i;
}

template<typename T>
bool Heap<T>::swap(unsigned int i, unsigned int j) {
    if (i == j)
        return false;

    T temp = this->heap[i];
    this->heap[i] = this->heap[j];
    this->heap[j] = temp;

    return true;
}

template<typename T>
bool Heap<T>::heapified(unsigned int i, unsigned int j) {
    if (this->max_heap)
        return this->heap[i] >= this->heap[j];
    return this->heap[i] <= this->heap[j];
}

#endif