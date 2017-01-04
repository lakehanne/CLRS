#include <iostream>
#include <cassert>
#include <string>


//helper function for printing
#define INFO(__o__) std::cout << __o__ << std::endl;

/*doubly linked list implementation*/
template<typename T>
struct node
{
	static node<T>* freelist;             //ref to freelist head
	node<T>* next;			//pointer to next node in list
	node<T>* prev;			//pointer to previous node in list
	T value;				//value for the node

	//Constructors
	node(const T& val, node* prevp, node* nextp)
	: value(val), prev(prevp), next(nextp)
	{}

	node(node* prevp = nullptr, node* nextp = nullptr)
	:prev(prevp), next(nextp)
	{	}

	/*overload the new operator*/
	void* operator new(size_t)
	{
		if(freelist == nullptr){
			return ::new node; 			//create space
		}		
		node<T>* temp = freelist;		//can take from freelist
		freelist = freelist->next;
		return temp;					//return the node
	}

	/*overload the delete operator*/
	void operator delete(void *ptr)
	{
		((node<T>*)ptr)->next = freelist;  //put on freelist
		freelist = (node<T>*)ptr;
	}
};

//create the freelist head pointer 
template <typename T>
node<T>* node<T>::freelist = nullptr;

template<typename T>
class DLList
{
private:
	node<T>* head;   		//pointer to list header
	node<T>* current;   		//pointer to current node	
	node<T>* tail;   		//pointer to tail node
	unsigned counter;


	void init()
	{
		current = tail = head = new node<T>;
		counter = 0;
	}

	void eraseall()
	{
		while(head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}

public:
	//constructors
	DLList() 
	{
		init();
	};
	~DLList() 
	{
		eraseall();
	}

	//insert element at the present position
	void insert(const T& elem)
	{
		//the header and tailer nodes means we can do away with node checking
	  current->next = current->next->prev = new node<T>(elem, current, current->next);
		++counter;
	  INFO("inserted " << elem);
	}

	void append(const T& elem)
	{
		tail->prev = tail->prev->next \
				   = new node<T>(elem, tail->prev, tail);
				   ++counter;
	  INFO("appended " << elem);
	}

	T remove()
	{
		if(current->next==tail)			//nothing to remove
			return nullptr;
		T elem = current->next->elem;   	//remember value; create a copy
		node<T>* ltemp = current->next; 	//remember link node; create a copy of current node
		current->next->next->previous = current;
		current->next = current->next->next; //remove from list
		delete ltemp;
		--counter;

	  	INFO("removed " << elem);

		return elem;
	}

	void previous()
	{
		if(current != head)
		{
			current = current->prev;
		}
	}

	void begin()
	{
		current = head;
	}

	void end()
	{
		current = tail;
	}

	void setPos(int pos) //theta(i) time since we have to march down from head node to currentent position
	{
		assert((pos>=0) && (pos<=counter));
		current = head;

		for(int i = 0; i <=pos; ++i)
			current = current->next;
	}

	void print()
	{
		INFO( "currentent values of the list: " );
		begin();   //set current to beginning
		for(unsigned i = 0; i <=counter; ++i)
		{			
			setPos(i);
			T val = getCurElem();
			INFO( val );
		}	

		INFO( "size of list: " << size() );
	}

	int size() const 	{
		INFO("Size is " << counter);
		return counter;
	}

	const T& getCurElem()
	{
		while(current->next != nullptr){
			return current->next->value;
		}
	}

	void clear() 	//clear all list contents
	{ 
		eraseall(); 
		init();
 	}
};

int main(void)
{
	DLList<int> dll;
	INFO("Constructed object");
	auto a = 3;
	dll.append(50);
	dll.insert(a);
	dll.insert(40);
	dll.size();

	dll.append(a);
	dll.print();
	// return 0;
}