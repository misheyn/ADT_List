#ifndef ADT_LIST_MYLIST_H
#define ADT_LIST_MYLIST_H

#include "Node.h"

template<typename T>
class MyList {
public:
    friend class Node<T>;

    class Iterator {
    public:
        Iterator(Node<T> *array_, int ind_) {
            array = array_;
            ind = ind_;
        }

        T &operator*() {
            return array[ind].value;
        }

        Iterator operator++(int) {
            ind = array[ind].next;
            return *this;
        }

        friend bool operator==(const Iterator &f, const Iterator &s) {
            return f.ind = s.ind;
        }

        friend bool operator!=(const Iterator &f, const Iterator &s) {
            return f.ind != s.ind;
        }

        friend class MyList<T>;

    private:
        Node<T> *array;
        int ind;
    };

    Iterator begin() {
        return Iterator(array, beginInd);
    }

    Iterator end() {
        return Iterator(array, -1);
    }

    explicit MyList(int len);

    MyList(MyList<T> &obj);

    ~MyList();

    bool push(T val);

    bool push(T val, int ind);

    bool pop(T val);

    bool popByInd(int ind);

    T readValue(int ind);

    bool changeValue(int ind, T val);

    int getIndByValue(T val);

    void clear();

    void print();

    int sizeOfList();

    bool isEmpty();

    bool isExist(T val);

    int stat;

private:
    int size;
    Node<T> *array;
    int beginInd;
    int freeBeginInd;
    int count;

    void resize();
};


#endif //ADT_LIST_MYLIST_H
