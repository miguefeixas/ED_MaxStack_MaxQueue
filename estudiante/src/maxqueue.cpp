/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author María del Mar Martinez Robles
 * @author José Miguel Feixas Galdeano
 */
#include "maxqueue.h"

void MaxQueue::push(int n) {
    int maxValInQueue = INT32_MAX;
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

        /*if (n >= front().maximum) {
            while (!data.empty()) {
                auxElement.value = data.top().value;
                auxElement.maximum = n;
                aux.push(auxElement);
                data.pop();
            }
        } else {
            while (!data.empty()) {
                aux.push(data.top());
                data.pop();
            }
        }*/

        aux.push(newElement);

        while (!aux.empty()) {
            data.push(aux.top());
            aux.pop();
        }
    }


    /*data<element> aux;
    element toInsert;

    toInsert.ele = num;
    if (empty()) {
        toInsert.max = num;
        data.poner(toInsert);
    } else {
        if (toInsert.ele > getMax()) {
            setMax(toInsert.ele);
            toInsert.max = toInsert.ele;
        }
        else
            toInsert.max = getMax();

        while (!data.vacia()) {
            aux.poner(data.tope());
            data.quitar();
        }

        aux.poner(toInsert);

        while (!aux.vacia()) {
            data.poner(aux.tope());
            aux.quitar();
        }
    }*/
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

ostream& operator<<(ostream & flow, MaxQueue cola) {
    while (!cola.empty()) {
        cout << "[" << cola.front().value << ", " << cola.front().maximum << "]" << endl;
        cola.pop();
    }
    return flow;
}

