#include <iostream>
#include "node.h"
#include "linkedlist.h"

using namespace std;

int main()
{
	//Se declara un objeto de clase LinkedList
	LinkedList l1;
	
	//Se declaran cinco objetos de Node y
	// se inicializan con valores
	Node n1 (60);
	Node n2 (50);
	Node n3 (30);
	Node n4 (80);
	Node n5 (70);

	
	//Se insertan los elementos en l1
	l1.insert(n1);
	l1.insert(n2);
	l1.insert(n3);
	l1.insert(n4);
	l1.insert(n5);

	cout<< "La lista de elementos es: "<<endl;
	l1.print();
	
	//Se elimina los elementos de los indices 4 y 2 (3 y 1 para el computador)
	l1.remove(3);
	l1.remove(1);
	cout<<"Los elementos numero 4 y 2 han sido eliminados "<<endl;
	cout<< "La nueva lista de elementos es: "<<endl;
	l1.print();	
	
		
	return 0;
}
