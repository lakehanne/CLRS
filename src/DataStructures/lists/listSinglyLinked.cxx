#include <iostream>
#include <memory>
#include <cassert>

//helper function for printing
#define INFO(__o__) std::cout << __o__ << std::endl;

//single linked list node
template<typename T> 
struct node
{
	T value;			//value for the node
	node *next; 		//pointer to next node in the list

	//constructors
	node(const T& val, node* nextval= nullptr)
	: value(val), next(nextval)
	{ }

	node(node* nextval = nullptr)
	{
		next = nextval;
	}
};

//linked list implementation
template <typename T>
class SLList 
{
private:
	node<T>* head;   //pointer to list header
	node<T>* tail;   //pointer to list's last value
	node<T>* curr;   //access to current value
	int count;	//size of list

	void init()
	{
		curr = tail = head = new node<T>;
		count = 0;
	}

	void eraseall()			//O(n)
	{
		while(head != nullptr)
		{
			curr = head;
			head = head->next;
			delete curr;
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
		INFO( "current values of the list: " );
		begin();   //set curr to beginning
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

 	/*Insert value at current position */ //theta(1)
 	void insert(const T& elem) 	{
 		curr->next = new node<T> (elem, curr->next);
 		if(tail == curr){
 			tail = curr -> next; //new tail
 		}
 		++count ;
 	}

 	void append(const T& elem)
 	{
 		tail->next = new node<T>(elem, nullptr);
 		tail = tail->next;
 		++count;
 	}

 	//remove and return current value
 	T remove()// if delete takes constant time, this is also theta(1) time
 	{
 		while(curr->next!=nullptr){
 			T elem = curr->next->value;
 			node<T>* ltemp = curr->next;		//remember node

 			if(tail == curr->next)
 				tail == curr ;   				//remove from list
 			delete ltemp;
 			--count;
 			return elem;
 		}
 	}

 	void begin()
 	{
 		curr = head;
 	}

 	void end()
 	{
 		curr = tail;
 	}

 	void prev()
 	{
 		if(curr == head)
 			return;
 		node<T>* temp = head;
 		while(temp->next !=curr)     //march down list until we find curr
 			temp = temp->next;
 		curr = temp;
 	}

 	void next()
 	{
 		if(curr==tail)
 			return;
 		curr = curr->next;
 	}

 	int size() const 	{
 		return count;
 	}

 	int currPos() const 	{
 		node<T>* temp = head;
 		unsigned i;
 		for(i=0; curr!=temp; ++i)
 			temp = temp->next;
 		return i;
 	}

 	void setPos(int pos) //theta(i) time since we have to march down from head node to current position
 	{
 		assert((pos>=0) && (pos<=count));
 		curr = head;

 		for(int i = 0; i <=pos; ++i)
 			curr = curr->next;
 	}

 	const T& getCurElem()
 	{
 		while(curr->next != nullptr){
 			return curr->next->value;
 		}
 	}
};

int main()
{
	SLList<int> ll(5000);

	ll.insert(200);

	ll.insert(1); ll.insert(10); 
	ll.insert(100);


	ll.print();

	ll.clear();
	// OUT_INFO("current value: " << ll.getCurElem());

	// ll.print();

	return 0;
}