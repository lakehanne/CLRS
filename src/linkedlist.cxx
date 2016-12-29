#include <iostream>
#include <cassert>

#include <list_adt.hpp>


#define OUT_INFO(__o__) std::cout << __o__ << std::endl;
//single linked list node
template<typename T> 
class Link
{
private:
	static Link<T>* freelist; 		//ref to freelist head
public:
	T value;		//value for the node
	Link *next; 	//pointer to next node in the list

	//constructors
	Link(const T& val, Link* nextval= nullptr)
	: value(val), next(nextval)
	{ }

	Link(Link* nextval = nullptr)
	{
		next = nextval;
	}

	// void* operator new(size_t)   //overload the new operator
	// {
	// 	if(freelist == nullptr)
	// 		return ::new Link;   //create space

	// 	Link<T>* temp = freelist;   //can take from a freelist
	// 	freelist = freelist->next;
	// 	return temp;
	// }

	// /*overload the delete operator*/
	// void operator delete(void* ptr)
	// {
	// 	static_cast<Link<T>*>(ptr)->next = freelist; //put on freelist
	// 	freelist = static_cast<Link<T>*>(ptr);
	// }
};

//linked list implementation
template <typename T>
class LList : public List <T>
{
private:
	Link<T>* head;   //pointer to list header
	Link<T>* tail;   //pointer to list's last value
	Link<T>* curr;   //access to current value
	int iter;		//size of list

	void init()
	{
		curr = tail = head = new Link<T>;
		iter = 0;
	}

	void eraseall()
	{
		while(head != nullptr)
		{
			curr = head;
			head = head->next;
			delete curr;
		}
	}

public:
	LList(int size=500)
	{
		init();
	}

	~LList()
	{
		eraseall();
	}

	void print()
	{
		std::cout << "current values of the list: " << std::endl;
		begin();   //set curr to beginning
		for(unsigned i = 0; i <= iter; ++i)
		{			
			setPos(i);
			T val = getCurElem();
			std::cout << val << std::endl;
		}	

		std::cout << "size of list" << size() << std::endl;	
	}

	void clear() 	//clear all list contents
	{ 
		eraseall(); 
		init();
 	}

 	/*Insert value at current position */
 	void insert(const T& elem)
 	{
 		curr->next = new Link<T> (elem, curr->next);
 		if(tail == curr)
 			tail = curr -> next; //new tail

 		++iter;
 	}

 	void append(const T& elem)
 	{
 		tail->next = new Link<T>(elem, nullptr);
 		tail = tail->next;
 		iter++;
 	}

 	//remove and return current value
 	T remove()
 	{
 		if(curr->next==nullptr)
 			std::cout<< "no value to remove" << std::endl;

 		T elem = curr->next->value;
 		Link<T>* ltemp = curr->next;		//remember link node

 		if(tail == curr->next)
 			tail == curr ;   				//remove from list
 		delete ltemp;
 		iter--;
 		return elem;

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
 		Link<T>* temp = head;
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

 	int size() const
 	{
 		return iter;
 	}

 	int currPos() const
 	{
 		Link<T>* temp = head;
 		unsigned i;
 		for(i=0; curr!=temp; ++i)
 			temp = temp->next;
 		return i;
 	}

 	void setPos(int pos)
 	{
 		assert((pos>=0) && (pos<=iter));
 		curr = head;

 		for(int i = 0; i <=pos; ++i)
 			curr = curr->next;
 	}

 	const T& getCurElem()
 	{
 		assert(curr->next != nullptr);
 		return curr->next->value;
 	}
};

int main()
{
	LList<int> ll(5000);

	ll.insert(200);

	ll.insert(1); ll.insert(10); 
	ll.insert(100);


	ll.print();

	ll.clear();
	// OUT_INFO("current value: " << ll.getCurElem());

	// ll.print();

	return 0;
}