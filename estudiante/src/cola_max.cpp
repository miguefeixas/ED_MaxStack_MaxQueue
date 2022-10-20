#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "maxqueue.h"

using namespace std;

int main(int argc, char *argv[]){

   /* MaxQueue cola;

    cola.push(1);
    cola.push(2);
    cola.push(3);
    cola.push(4);

    cout << cola.size() << endl;

    if (!cola.empty())
        cout << "La cola no está vacía" << endl;
    else
        cout << "La cola está vacía" << endl;


    cout << cola << endl;

    cola.push(5);
    cout << cola << endl;

    cola.push(1);
    cout << cola << endl;

    cola.push(3);
    cout << cola << endl;

    cout << cola.front() << endl;

    cola.pop();
    cout << cola.front() << endl;
    cout << cola << endl;

    cola.pop();
    cout << cola << endl;

    cola.pop();
    cout << cola << endl;

    cola.pop();
    cout << cola << endl;

    cola.pop();
    cout << cola << endl;

    cola.pop();
    cout << cola << endl;

    cola.push(27);
    cout << cola << endl;

    cola.pop();
    cout << cola << endl;

    cout << "Fin" << endl;

    cout << cola << endl;
    cola.pop();

    if (!cola.empty())
        cout << "La cola no está vacía" << endl;
    else
        cout << "La cola está vacía" << endl;

    cout << cola.size() << endl;

    cola.push(3);
    cola.push(4);
    cola.push(4);
    cola.push(3);

    cout << cola << endl;

    cola.push(4);

    cout << cola << endl;*/

    // // Run the current exercise
    MaxQueue queue;

    for(int i = 1; i < argc; i++){
         if (argv[i][0] == '.'){
             cout << queue.front() << endl;
             queue.pop();
         } else {
             queue.push(atoi(argv[i]));
         }
    }
    return 0;
}
