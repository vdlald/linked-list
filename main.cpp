#include <iostream>
#include "LinkedList.cpp"

int main() {
    auto *list = LinkedList<int>::of(
            (const int[]) {1, 2, 3, 4, 5, 7},
            6
    );

    list->to_vector();

    std::cout << "size: " << list->get_size() << std::endl;

    std::cout << "preview: " << *list << std::endl;

    std::cout << "pop: " << list->pop() << std::endl;

    std::cout << *list << std::endl;

    std::cout << "get: " << list->get(4) << std::endl;

    list->set(4, 9);

    std::cout << "set: " << *list << std::endl;

    list->add(2, 99);
    std::cout << "add: " << *list << std::endl;

    list->remove(1);
    std::cout << "remove: " << *list << std::endl;

    return 0;
}

