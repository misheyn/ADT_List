#include "MyList.h"
#include <iostream>

using namespace std;

template<typename T>
MyList<T>::MyList(int len) {
    size = len;
    array = new Node<T>[size];
    clear();
}

template<typename T>
void MyList<T>::clear() {
    beginInd = -1;
    freeBeginInd = 0;
    count = 0;
    stat = 0;
    for (int i = 0; i < size; ++i) {
        array[i].next = i + 1;
    }
    array[size - 1].next = -1;
}

template<typename T>
MyList<T>::MyList(MyList<T> &obj) {
    size = obj.size;
    beginInd = obj.beginInd;
    freeBeginInd = obj.freeBeginInd;
    count = obj.count;
    array = new Node<T>[size];
    for (int i = 0; i < size; ++i) {
        array[i] = obj.array[i];
    }
}

template<typename T>
MyList<T>::~MyList() {
    delete[] array;
}

template<typename T>
bool MyList<T>::push(T val) {
    bool f = true;
    if (count == size - 1) resize();
    if (size != 0) {
        int tmpInd = array[freeBeginInd].next;
        array[freeBeginInd].value = val;
        array[freeBeginInd].next = beginInd;
        beginInd = freeBeginInd;
        freeBeginInd = tmpInd;
        count++;
    } else f = false;
    return f;
}

template<typename T>
bool MyList<T>::push(T val, int ind) {
    bool f = true;
    stat = 0;
    if (ind == 0) {
        stat++;
        push(val);
    } else {
        if (count == size - 1) resize();
        if (ind >= 0 && ind < count && size != 0) {
            auto it1 = begin();
            it1++;
            int i = 1;
            for (auto it2 = begin(); it1 != end(); it1++, it2++, i++) {
                stat++;
                if (i == ind) {
                    int cInd = freeBeginInd;
                    int pInd = it2.ind;
                    int tmpInd = array[cInd].next;

                    array[cInd].value = val;
                    array[cInd].next = it1.ind;
                    array[pInd].next = cInd;

                    freeBeginInd = tmpInd;
                    count++;
                    break;
                }
            }

        } else f = false;
    }
    return f;
}

template<typename T>
void MyList<T>::resize() {
    auto *tmp = new Node<T>[size * 2];
    for (int i = 0; i < size; ++i) {
        tmp[i] = array[i];
    }
    delete array;
    array = tmp;
    for (int i = size; i < 2 * size; ++i) {
        array[i].next = i + 1;
    }
    array[size - 1].next = size;
    size = 2 * size;
    array[size - 1].next = -1;
}

template<typename T>
bool MyList<T>::pop(T val) {
    bool f = false;
    Iterator it1 = begin();
    int cInd = it1.ind;
    if (*it1 == val) {
        beginInd = array[cInd].next;
        array[cInd].next = freeBeginInd;
        freeBeginInd = cInd;
        count--;
        f = true;
    } else {
        it1++;
        for (auto it2 = begin(); it1 != end(); it1++, it2++) {
            if (*it1 == val) {
                int pInd = it2.ind;
                cInd = it1.ind;
                array[pInd].next = array[cInd].next;
                array[cInd].next = freeBeginInd;
                freeBeginInd = cInd;
                count--;
                f = true;
                break;
            }
        }
    }
    return f;
}

template<typename T>
bool MyList<T>::popByInd(int ind) {
    bool f = false;
    Iterator it1 = begin();
    int cInd = it1.ind;
    stat = 0;
    if (ind == 0) {
        beginInd = array[cInd].next;
        array[cInd].next = freeBeginInd;
        freeBeginInd = cInd;
        count--;
        stat++;
        f = true;
    } else {
        int i = 1;
        it1++;
        for (auto it2 = begin(); it1 != end(); it1++, it2++, i++) {
            stat++;
            if (ind == i) {
                int pInd = it2.ind;
                cInd = it1.ind;
                array[pInd].next = array[cInd].next;
                array[cInd].next = freeBeginInd;
                freeBeginInd = cInd;
                count--;
                f = true;
                break;
            }
        }
    }
    return f;
}

template<typename T>
T MyList<T>::readValue(int ind) {
    T val = 0;
    if (ind < count && ind >= 0) {
        int i = 0;
        for (auto it = begin(); it != end(); it++, i++) {
            if (i == ind) {
                val = *it;
                break;
            }
        }
    }
    return val;
}

template<typename T>
bool MyList<T>::changeValue(int ind, T val) {
    bool f = false;
    if (ind < count && ind >= 0) {
        int i = 0;
        for (auto it = begin(); it != end(); it++, i++) {
            if (i == ind) {
                array[it.ind].value = val;
                f = true;
                break;
            }
        }
    }
    return f;
}

template<typename T>
int MyList<T>::getIndByValue(T val) {
    int j = -1;
    int i = 0;
    for (auto it = begin(); it != end(); it++, i++) {
        if (*it == val) {
            j = i;
            break;
        }
    }
    return j;
}

template<typename T>
void MyList<T>::print() {
    for (auto it = begin(); it != end(); it++) {
        cout << array[it.ind].value << " ";
    }
}

template<typename T>
int MyList<T>::sizeOfList() {
    return count;
}

template<typename T>
bool MyList<T>::isExist(T val) {
    bool f = false;
    stat = 0;
    for (auto it = begin(); it != end(); it++) {
        stat++;
        if (*it == val) {
            f = true;
            break;
        }
    }
    return f;
}

template<typename T>
bool MyList<T>::isEmpty() {
    bool f = true;
    if (beginInd != -1) f = false;
    return f;
}


template
class MyList<int>;

template
class MyList<char>;