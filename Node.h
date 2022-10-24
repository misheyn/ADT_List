#ifndef ADT_LIST_NODE_H
#define ADT_LIST_NODE_H

template<typename T>
class Node {
public:
    T value;
    int next;

    Node() : next(-1), value(0) {}
};

#endif //ADT_LIST_NODE_H
