/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author María del Mar Martinez Robles
 * @author José Miguel Feixas Galdeano
 */

#include <stack>
#include <iostream>
#include <assert.h>

using namespace std;

struct element {
    int value;
    int maximum;
};

inline ostream& operator<<(ostream & os, const element &e) {
    return os << e.value << "," << e.maximum;
}

/**
 * @brief TDA MaxQueue
 *
 * Un objeto del tipo TDA MaxQueue implementa una cola similar a la de la STL con las operaciones básicas
 * de la misma, push(), pop(), front(), size() y empty() pero con la particularidad de que,
 * en su representación interna, se usa un objeto del tipo Stack de la STL.
 *
 * Este TDA almacena objetos de tipo element de forma que, en cada elemento de la cola, vamos a encontrar
 * dos valores, el valor propio y el valor máximo que hay en la cola.
 *
 * @author María del Mar Martinez Robles
 * @author José Miguel Feixas Galdeano
 * @date 20/10/2022
 */

class MaxQueue {
private:
    /**
     * @brief Objeto del tipo pila de la STL que almacena el contenido de la cola
     *
     * Únicamente usando este tipo de dato y su repertorio de operaciones se va a construir
     * nuestra cola con máximo.
     *
     */
    stack<element> data;
public:
    /**
     * @brief Introduce un valor en el objeto de MaxQueue que llama a la función
     * respetando la filosofía FIFO propia del tipo de dato queue.
     * @param n Número que queremos introducir en la cola.
     * @pre n es un número entero.
     * @post El objeto de tipo MaxQueue que llama a la función se ve modificado
     * al incluirse el elemento @p n.
     */
    void push(int n);

    /**
     * @brief Elimina el elemento del front de la pila, es decir, el más antiguo.
     * @pre La cola no está vacía.
     * @post La cola se ve modificada al haberse eliminado el elemento que estaba en el
     * front.
     */
    void pop();

    /**
     * @brief Devuelve el elemento en el front de la cola, es decir, el elemento más
     * antiguo de la misma.
     * @return El objeto de tipo element que se encontraba en el front.
     * @pre La cola no está vacía.
     * @post La cola no se ve modificada.
     */
    element front() const;

    /**
     * @brief Devuelve el número de elementos que hay en la cola.
     * @return Un dato de tipo unsigned que representa el número de elementos en la cola.
     * @post La cola no se ve modificada.
     */
    unsigned size() const;

    /**
     * @brief Informa de si la cola está o no vacía.
     * @return True si la cola está vacía, false en caso contrario.
     * @post La cola no se ve modificada.
     */
    bool empty() const;
    // TODO eliminar sobrecarga de << para MaxQueue
    friend ostream& operator<<(ostream& os, MaxQueue cola);
};


