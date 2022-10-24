/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author María del Mar Martinez Robles
 * @author José Miguel Feixas Galdeano
 */
#include "maxqueue.h"

void MaxQueue::push(int n) {
    stack<element> aux;
    element newElement, auxElement;
    newElement.value = newElement.maximum = n;

    if (empty())
        data.push(newElement);
    else {
        while (!data.empty()) {
            auxElement.value = data.top().value;
            if (data.top().maximum >= n)
                auxElement.maximum = data.top().maximum;
            else if (data.top().maximum < n)
                auxElement.maximum = n;
            aux.push(auxElement);
            data.pop();
        }

        aux.push(newElement);

        while (!aux.empty()) {
            data.push(aux.top());
            aux.pop();
        }
    }
}

void MaxQueue::pop() {
    if (!empty())
        data.pop();
}

element MaxQueue::front() const {
    assert(!empty());
    return data.top();
}

unsigned MaxQueue::size() const {
    return data.size();
}

bool MaxQueue::empty() const {
    return data.empty();
}

ostream& operator<<(ostream & os, MaxQueue cola) {
    while (!cola.empty()) {
        os << cola.front() << endl;
        cola.pop();
    }
    return os;
}


