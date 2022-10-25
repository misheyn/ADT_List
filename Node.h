#ifndef ADT_LIST_NODE_H
#define ADT_LIST_NODE_H

template<typename T>
class Node {
public:
    T value;
    int next;

    Node() : next(-1) {}
};

#endif //ADT_LIST_NODE_H
