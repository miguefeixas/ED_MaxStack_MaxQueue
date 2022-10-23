/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author María del Mar Martinez Robles
 * @author José Miguel Feixas Galdeano
 */

#include <queue>
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
 * @brief TDA MaxStack
 *
 * Un objeto del tipo TDA MaxStack implementa una cola similar a la de la STL con las operaciones básicas
 * de la misma, push(), pop(), front(), size() y empty() pero con la particularidad de que,
 * en su representación interna, se usa un objeto del tipo Queue de la STL.
 *
 * Este TDA almacena objetos de tipo element de forma que, en cada elemento de la cola, vamos a encontrar
 * dos valores, el valor propio y el valor máximo que hay en la cola.
 *
 * @author María del Mar Martinez Robles
 * @author José Miguel Feixas Galdeano
 * @date 23/10/2022
 */

class MaxStack {
private:
    /**
     * @brief Objeto del tipo cola de la STL que almacena el contenido de la pila
     *
     * Únicamente usando este tipo de dato y su repertorio de operaciones se va a construir
     * nuestra pila con máximo.
     *
     */
    queue<element> data;
public:
    /**
     * @brief Introduce un valor en el objeto de MaxStack que llama a la función
     * respetando la filosofía LIFO propia del tipo de dato stack.
     * @param n Número que queremos introducir en la pila.
     * @pre n es un número entero.
     * @post El objeto de tipo MaxStack que llama a la función se ve modificado
     * al incluirse el elemento @p n.
     */
    void push(int n);

    /**
     * @brief Elimina el elemento del top de la pila, es decir, el más nuevo.
     * @pre La pila no está vacía.
     * @post La pila se ve modificada al haberse eliminado el elemento que estaba en el
     * top.
     */
    void pop();

    /**
     * @brief Devuelve el elemento en el top de la pila, es decir, el elemento más
     * antiguo de la misma.
     * @return El objeto de tipo element que se encontraba en el top.
     * @pre La pila no está vacía.
     * @post La pila no se ve modificada.
     */
    element top() const;

    /**
     * @brief Devuelve el número de elementos que hay en la pila.
     * @return Un dato de tipo unsigned que representa el número de elementos en la pila.
     * @post La pila no se ve modificada.
     */
    unsigned size() const;

    /**
     * @brief Informa de si la pila está o no vacía.
     * @return True si la pila está vacía, false en caso contrario.
     * @post La pila no se ve modificada.
     */
    bool empty() const;

    // TODO eliminar sobrecarga de << para MaxStack
    friend ostream& operator<<(ostream& os, MaxStack pila);

};