#include <iostream>
#include <cassert>

//helper function for printing
#define INFO(__o__) std::cout << __o__ << std::endl;

/*single linked list node*/
template<typename T> 
struct node
{
	/*the static decl means all Link class objects share the same freelist ptr var
	we use freelist to allow a controlled pattern for memory access to reduce expense 
	of using free-store objects in  */
	static node<T>* freelist;   //reference to freelist head
	T value;			//value for the node
	node *next; 		//pointer to next node in the list

	//constructors
	node(const T& val, node* nextp= nullptr)
	: value(val), next(nextp)
	{ }

	node(node* nextp = nullptr)
	{
		next = nextp;
	}

	/*overloaded new operator*/
	void* operator new(size_t){
		/*make space. not using the double colon here would 
		use the derived new operator and set up an infinite recursion
		*/
		if(freelist==nullptr) return ::new node; 
		node<T>* temp = freelist;   //can grab from freelist
		freelist = freelist->next;
		return temp;
	}
	/*overloaded delete operator*/
	void operator delete(void* ptr){
		((node<T>*)ptr)->next = freelist;   //put on freelist
		freelist = (node<T>*)ptr;
	}
};

//create the freelist head pointer
template <typename T>
node<T>* node<T>::freelist = nullptr;

//linked list implementation
template <typename T>
class SLList 
{
private:
	node<T>* head;   //pointer to list header
	node<T>* tail;   //pointer to list's last value
	node<T>* current;   //access to currentent value
	int count;	//size of list

	void init()
	{
		current = tail = head = new node<T>;
		count = 0;
	}

	void eraseall()			//O(n)
	{
		while(head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}

public:
	SLList( )
	{
		init();
	}

	~SLList()
	{
		eraseall();
	}

	void print()
	{
		INFO( "currentent values of the list: " );
		begin();   //set current to beginning
		for(unsigned i = 0; i <=count; ++i)
		{			
			setPos(i);
			T val = getCurElem();
			INFO( val );
		}	

		INFO( "size of list" << size() );
	}

	void clear() 	//clear all list contents
	{ 
		eraseall(); 
		init();
 	}

 	/*Insert value at currentent position */ //theta(1)
 	void insert(const T& elem) 	{
 		current->next = new node<T> (elem, current->next);
 		if(tail == current){
 			tail = current -> next; //new tail
 		}
 		++count ;
 	}

 	void append(const T& elem)
 	{
 		tail->next = new node<T>(elem, nullptr);
 		tail = tail->next;
 		++count;
 	}

 	//remove and return currentent value
 	T remove()// if delete takes constant time, this is also theta(1) time
 	{
 		while(current->next!=nullptr){
 			T elem = current->next->value;
 			node<T>* ltemp = current->next;		//remember node

 			if(tail == current->next)
 				tail == current ;   				//remove from list
 			delete ltemp;
 			--count;
 			return elem;
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

 	void prev()
 	{
 		if(current == head)
 			return;
 		node<T>* temp = head;
 		while(temp->next !=current)     //march down list until we find current
 			temp = temp->next;
 		current = temp;
 	}

 	void next()
 	{
 		if(current==tail)
 			return;
 		current = current->next;
 	}

 	int size() const 	{
 		return count;
 	}

 	int currentPos() const 	{
 		node<T>* temp = head;
 		unsigned i;
 		for(i=0; current!=temp; ++i)
 			temp = temp->next;
 		return i;
 	}

 	void setPos(int pos) //theta(i) time since we have to march down from head node to currentent position
 	{
 		assert((pos>=0) && (pos<=count));
 		current = head;

 		for(int i = 0; i <=pos; ++i)
 			current = current->next;
 	}

 	const T& getCurElem()
 	{
 		while(current->next != nullptr){
 			return current->next->value;
 		}
 	}
};

int main()
{
	SLList<int> ll(5000);

	ll.insert(200);

	ll.insert(1); ll.insert(10); 
	ll.insert(100);
	ll.remove();


	ll.print();

	ll.clear();
	// OUT_INFO("currentent value: " << ll.getCurElem());

	// ll.print();

	return 0;
}