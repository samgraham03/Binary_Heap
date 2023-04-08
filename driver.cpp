#include "Heap.hpp"
#include <iostream>
#include <string>

void welcome() {
    std::cout << "Commands are:" << std::endl;
    std::cout << " 1. MAKE {UNSIGNED_INTEGER:capacity} {BOOLEAN:min/max}" << std::endl;
    std::cout << " 2. SIZE" << std::endl;
    std::cout << " 3. CAPACITY" << std::endl;
    std::cout << " 4. TYPE" << std::endl;
    std::cout << " 5. INSERT {INTEGER:element}" << std::endl;
    std::cout << " 6. DELETE {INTEGER:element}" << std::endl;
    std::cout << " 7. SORT {BOOLEAN:descending/ascending}" << std::endl;
    std::cout << " 8. PRINT" << std::endl;
    std::cout << " 9. DESTROY" << std::endl;
    std::cout << "10. EXIT" << std::endl;
}

int main() {
    Heap<int>* heap = nullptr;

    std::string cmd;

    welcome();

    while (std::cin >> cmd) {
        if (!heap && cmd == "MAKE") {
            unsigned int cap;
            bool max_heap;
            std::cin >> cap >> max_heap;
            heap = new Heap<int>(cap, max_heap);
            std::cout << (max_heap ? "Max" : "Min") << " heap created of capacity " << cap << std::endl;
        }
        else if (heap && cmd == "INSERT") {
            int el;
            std::cin >> el;
            if (heap->insert(el))
                std::cout << "Success" << std::endl;
            else
                std::cout << "Failure" << std::endl;
        }
        else if (heap && cmd == "DELETE") {
            int el;
            std::cin >> el;
            if (heap->remove(el))
                std::cout << "Success" << std::endl;
            else
                std::cout << "Failure" << std::endl;
        }
        else if (heap && cmd == "SIZE") {
            std::cout << "Size is " << heap->size() << std::endl;
        }
        else if (heap && cmd == "CAPACITY") {
            std::cout << "Capacity is " << heap->capacity() << std::endl;
        }
        else if (heap && cmd == "TYPE") {
            std::cout << (heap->type() ? "Max Heap" : "Min Heap") << std::endl;
        }
        else if (heap && cmd == "SORT") {
            bool ascending;
            std::cin >> ascending;

            int size = heap->size();

            while (heap->size())
                heap->remove((*heap)[0]);

            if (ascending != heap->type())
                for (int i = size - 1; i >= 0; i--)
                    std::cout << (*heap)[i] << (i > 0 ? "," : "");
            else
                for (int i = 0; i < size; i++)
                    std::cout << (*heap)[i] << (i < (size - 1) ? "," : "");

            for (int i = 0; i < size; i++)
                heap->insert((*heap)[i]);

            std::cout << std::endl;
        }
        else if (heap && cmd == "PRINT") {
            for (int i = 0; i < heap->size(); i++)
                std::cout << (*heap)[i] << (i < heap->size() - 1 ? "," : "");
            std::cout << std::endl;
        }
        else if (heap && cmd == "DESTROY") {
            delete heap;
            heap = nullptr;
            std::cout << "Success" << std::endl;
            welcome();
        }
        else if (cmd == "EXIT") {
            break;
        }
    }

    delete heap;
    heap = nullptr;

    return 0;
}