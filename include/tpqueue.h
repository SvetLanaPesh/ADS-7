// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>
template<typename T>
class TPQueue {
 private:
    struct Item {
        T value;
        Item* next;
    };
    Item* head, * tail;
    TPQueue::Item* create(const T&);
 public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    void push(const T&);
    const T& pop();
    ~TPQueue() {}
};
template <typename T>
typename TPQueue<T>::Item* TPQueue<T>::create(const T& value) {
    Item* temp = new Item;
    temp->value = value;
    temp->next = nullptr;
    return temp;
}
template <typename T>
void TPQueue<T>::push(const T& value) {
    Item* cur = create(value);
    Item* prev = nullptr;
    Item* tmp = head;
    while (tmp != nullptr && cur->value.prior <= tmp->value.prior) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (prev == nullptr) {
        cur->next = head;
        head = cur;
    } else {
        prev->next = cur;
        cur->next = tmp;
    }
}
template <typename T>
const T& TPQueue<T>::pop() {
    if (!head) {
        throw std::string("Empty!");
    } else {
        Item* temp = head->next;
        T value = head->value;
        delete head;
        head = temp;
        return value;
    }
}
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
