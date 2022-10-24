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

/**
 * @brief TDA element
 *
 * Un objeto de tipo element almacena un par de valores @p value y @p maximum. La cola con máximo
 * que implementamos a continuación almacenará objetos de este tipo, de forma que el primer elemento
 * será el propio valor que almacena ese objeto y el segundo, el valor máximo de todos los objetos de tipo
 * @p element que hay en la cola.
 *
 */

struct element {
    int value;
    int maximum;
};

/**
 * @brief Sobrecarga del operador << para el struct @p element.
 * @param os Output stream.
 * @param e El elemento que se va a imprimir.
 * @return Output stream.
 * @post El objeto de @p element que se imprime no se ve modificado.
 */
inline ostream& operator<<(ostream & os, const element &e) {
    return os << e.value << "," << e.maximum;
}

/**
 * @brief TDA MaxQueue
 *
 * Un objeto del TDA @p MaxQueue implementa una cola similar a la de la STL con las operaciones básicas
 * de la misma, push(), pop(), front(), size() y empty() pero con la particularidad de que,
 * en su representación interna, se usa un objeto del tipo @p Stack de la STL.
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
     * @brief Introduce un valor en el objeto de MaxQueue que llama a la función.
     *
     * Este método se encarga de todos las operaciones necesarias para respetar la
     * filosofía FIFO natural de una cola, aún siendo implementada con una pila.
     * Para ello, nos apollamos en una pila auxiliar, de forma que cada vez que
     * llamemos a la función push() vamos a volcar nuestro objeto de la clase
     * @p MaxQueue en esta pila auxiliar, donde posteriormente también introduciremos
     * el nuevo elemento que queremos insertar. Tras esto, hacemos el proceso inverso
     * y llenamos nuestro objeto @p MaxQueue con el contenido de la pila auxiliar.
     *
     * También tenemos que llevar a cabo el control del máximo de la pila.
     * Para esto, consideramos tres casos:
     *
     * - El objeto donde hacemos el push() está vacío: Este caso es trivial, el elemento
     * que insertamos tiene el valor @p maximum a su mismo valor @p value.
     * - El elemento que vamos a introducir es menor o igual que el máximo actual de @p MaxQueue:
     * Respetamos el valor máximo que tenían los elementos ya existentes en la cola y el
     * máximo del nuevo elemento será él mismo en tanto que, aunque puede haber elementos
     * mayores que este, cuando accedamos a él es seguro que aquellos que tenían mayor valor
     * ya se han eliminado de la cola.
     * - El elemento que vamos a introducir es mayor que el máximo actual de @p MaxQueue:
     * Cuando realizamos el trasbase de @p MaxQueue a la pila auxiliar, modificamos los valores
     * @p maximum de todos los elementos para darles el nuevo valor que vamos a introducir.
     * Una vez más, el @p maximum del nuevo elemento es él mismo.
     *
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

    /**
     * @brief Sobrecarga del operador << para la clase MaxQueue.
     * @param os Output stream.
     * @param cola Objeto de la clase MaxQueue que se va a imprimir.
     * @return Output stream.
     * @post La cola que se imprime no se ve modificada.
     *
     */
    friend ostream& operator<<(ostream& os, MaxQueue cola);
};



