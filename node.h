
using namespace std;

class Node
{
	int elem;
		
	public:
		Node *next;
		
		Node();
		Node(int elem);
		Node(const Node &copia);
		int getElem() const;
		void setElem(const int elemento);
		
};

Node::Node()
{
	elem = 0;
	next = NULL;
}

Node::Node(int elemento)
{
	elem = elemento;
	next = NULL;
}

Node::Node(const Node &copia)
{
	elem = copia.elem;
	next = NULL;
}


int Node::getElem() const
{
	return elem;
}

void Node::setElem(const int elemento) 
{
	elem = elemento;
}





