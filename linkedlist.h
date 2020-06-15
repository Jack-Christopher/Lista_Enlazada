
class LinkedList
{
	int size;
	Node *head;
	
	public:
		
		LinkedList();
		LinkedList(const LinkedList &copia);

		void insert(const Node &n);
		void remove(const int pos);
		void print();
		~LinkedList();
					
};


//Constructor por defecto
LinkedList::LinkedList()
{
	head = NULL;
	size = 0;
}

//Constructor copia
LinkedList::LinkedList(const LinkedList &copia)
{
	size = copia.size;
	head  = copia.head;
}


//Eliminar un nodo de cualquier posición del arreglo:
void LinkedList::remove(const int pos)
{
	int posicion = pos;
	
	if(posicion == 0 )
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;//Para no ejecutar los demás pasos
    }
    
    Node *puntero = head;
    while(puntero->next!=NULL && --posicion)
       	puntero = puntero->next;
		
    if(puntero->next==NULL)  return;
	    
    Node *temp = puntero->next;
    puntero->next = puntero->next->next;
    delete temp;
	
    size--;

}




void LinkedList::print()
{
	//Se itera sobre todos los elementos y se imprimen sus datos miembro
	Node *puntero = head;
	int k = 1;
	while(puntero)
    {
    	cout<< "Elemento "<< k<< ": "<< puntero->getElem()<<endl;
        puntero = puntero->next;
        k++;
    }
}


//Insertar un nodo en la posición adecuada (para que esté ordenado)
void LinkedList::insert(const Node &n)
{
	Node *new_node = new Node(n);
	
	if (size == 0) 
	{
		head = new_node;
	}
	
	int status = -1;
	Node *puntero = head;
	Node *aux_puntero = head;
	
	int new_value = new_node->getElem();
	int pointer_value = puntero->getElem();
	
	if ( new_value < pointer_value ) { status = 1; }
	
	for (int k = 0; k < size; k++)
	{
		aux_puntero = puntero;
		puntero = puntero->next;
		pointer_value = puntero->getElem();
		
		if ( new_value < pointer_value) 
		{
			break; 
		}
		
		if ( k == size - 1 && new_value > pointer_value ) { status = 3; }
	
	}
	
	if(status == 1)
	{
		new_node->next = head;
		head = new_node; 
	}
	
	else if (status == 3)
	{
		puntero->next = new_node;
		new_node->next = NULL;
	}
	
	else
	{
		aux_puntero->next = new_node;
		new_node->next = puntero;
	}
	
	size++;
}


//Destructor
LinkedList::~LinkedList()
{
	Node *puntero = head;
	Node *siguiente2 = NULL;
	
	//Se libera la memoria asignada con new
	while(puntero != NULL)
    {
        siguiente2 = puntero->next;
        delete puntero;
        puntero = siguiente2;
    }
}




