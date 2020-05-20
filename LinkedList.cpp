#include <iostream>
#include "LinkedList.h"
#include "List.h"
#include "Vectorable.h"

template<typename T>
class LinkedList : public List<T>, Vectorable<T> {
private:
    struct Node;

    size_t size{};
    Node *first;
    Node *last;

public:
    LinkedList() {
        this->size = 0;
        this->first = NULL;
        this->last = NULL;
    }

    ~LinkedList() {
        Node *next = first;
        for (Node *node = next; node != NULL;) {
            next = node->next;
            delete node;
            node = next;
        }
    }

    static LinkedList<T>* of(const T *array, size_t size) {
        auto *list = new LinkedList<T>();
        for (size_t i = 0; i < size; ++i)
            list->push(array[i]);
        return list;
    }

    size_t get_size() override {
        return size;
    }

    bool is_empty() override {
        return size == 0;
    }

    void add(size_t index, T object) override {
        this->validate_index(index);
        if (index == this->size) {
            this->link_last(object);
        }
        {
            this->link_before(object, this->get_node(index));
        }
    }

    T remove(size_t index) override {
        this->validate_index(index);
        return this->unlink(this->get_node(index));
    }

    void push(T object) override {
        this->link_first(object);
    }

    T pop() override {
        return this->remove_first();
    }

    T get(size_t index) override {
        this->validate_index(index);
        return this->get_node(index)->value;
    }

    void set(size_t index, T object) override {
        this->validate_index(index);
        this->get_node(index)->value = object;
    }

    std::vector<T> to_vector() override {
        std::vector<T> vector;
        for (Node *node = this->first; node != NULL; node = node->next) {
            vector.push_back(node->value);
        }
        return vector;
    }

    friend std::ostream &operator<<(std::ostream &out, const LinkedList<T> &list) {
        out << "LinkedList[ ";
        for (Node *node = list.first; node != NULL; node = node->next)
            out << node->value << " ";
        out << "]";
        return out;
    }

private:
    struct Node {
        T value;
        Node *next;
        Node *prev;

        Node() {
            this->prev = NULL;
            this->value = NULL;
            this->next = NULL;
        }

        Node(Node *prev, T value, Node *next) {
            this->prev = prev;
            this->value = value;
            this->next = next;
        }

        ~Node() {
            this->prev = NULL;
            this->value = NULL;
            this->next = NULL;
        }
    };

    void link_first(T object) {
        Node *f = this->first;
        Node *newNode = new Node((Node *) NULL, object, f);
        this->first = newNode;
        if (!f) {  // if null
            this->last = newNode;
        } else {
            f->prev = newNode;
        }
        ++this->size;
    }

    T remove_first() {
        Node *f = this->first;
        if (!f) {  // if null
            throw std::runtime_error("no such element");
        } else {
            return this->unlink_first(f);
        }
    }

    T unlink_first(Node *f) {
        T value = f->value;
        Node *next = f->next;
        delete f;
        this->first = next;
        if (next == NULL) {
            this->last = NULL;
        } else {
            next->prev = NULL;
        }
        --this->size;
        return value;
    }

    Node *get_node(size_t index) {
        Node *x;
        if (index < this->size >> 1) {
            x = this->first;

            for (size_t i = 0; i < index; ++i)
                x = x->next;

            return x;
        } else {
            x = this->last;

            for (size_t i = this->size - 1; i > index; --i)
                x = x->prev;

            return x;
        }
    }

    void validate_index(size_t index) {
        if (index > this->size)
            throw std::invalid_argument("index must be smaller than size");
    }

    void link_last(T object) {
        Node *l = this->last;
        Node *newNode = new Node(l, object, (Node *) NULL);
        this->last = newNode;
        if (!l) {  // if null
            this->first = newNode;
        } else {
            l->next = newNode;
        }
        ++this->size;
    }

    void link_before(T object, Node *succ) {
        Node *pred = succ->prev;
        Node *newNode = new Node(pred, object, succ);
        succ->prev = newNode;
        if (!pred) {  // if null
            this->first = newNode;
        } else {
            pred->next = newNode;
        }
        ++this->size;
    }

    T unlink(Node *x) {
        T value = x->value;
        Node *next = x->next;
        Node *prev = x->prev;
        if (!prev) {  // if null
            this->first = next;
        } else {
            prev->next = next;
        }

        if (!next) {  // if null
            this->last = prev;
        } else {
            next->prev = prev;
        }

        delete x;
        --this->size;
        return value;
    }
};
