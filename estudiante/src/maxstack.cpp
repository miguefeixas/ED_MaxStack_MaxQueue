/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * @author María del Mar Martinez Robles
 * @author José Miguel Feixas Galdeano
 */
#include "maxstack.h"

void MaxStack::push(int n) {
    queue<element> tmp;
    element nuevo{}, temporal{};
    nuevo.value=n;
    if(!data.empty() && data.front().maximum > nuevo.value ) {
        // maximo del ultimo elemento>nuevo
        nuevo.maximum = data.front().maximum;
    }
    else
        nuevo.maximum=n;
    tmp.push(nuevo); // meto el nuevo, que debería estar arriba
    while(!data.empty()){
        temporal.value = data.front().value;
        temporal.maximum = data.front().maximum;
        data.pop();
        tmp.push(temporal);
    }
    // ahora que tmp tiene lo que necesita data, se lo meto
    while(!tmp.empty()){
        temporal.value= tmp.front().value;
        temporal.maximum = tmp.front().maximum;
        tmp.pop();
        data.push(temporal);
    }
}

void MaxStack::pop() {
    if (!empty())
        data.pop();
}

element MaxStack::top() const {
    assert(!empty());
    return data.front();
}

unsigned MaxStack::size() const {
    return data.size();
}

bool MaxStack::empty() const {
    return data.empty();
}

ostream& operator<<(ostream & flow, MaxStack pila) {
    while (!pila.empty()) {
        cout << "[" << pila.top().value << ", " << pila.top().maximum << "]" << endl;
        pila.pop();
    }
    return flow;
}

