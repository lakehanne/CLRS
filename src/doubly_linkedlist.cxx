#include <iostream>
#include <string>

using std::cout;
using std::endl;

/*doubly linked list implementation*/

template<typename T>
class Link
{
private: 
	static Link<T>* freelist;             //ref to freelist head
public:
	Link<T>* next;			//pointer to next node in list
	Link<T>* prev;			//pointer to previous node in list
	T value;				//value for the node

	//Constructors
	Link(const T& val, Link* prevp, Link* nextp)
	: value(val), prev(prevp), next(nextp)
	{}

	Link(Link* prevp = nullptr, Link* nextp = nullptr)
	{
		prev = prevp;
		next = nextp;
	}

	/*overload the new operator*/
	void* operator new(size_t)
	{
		if(freelist == nullptr)
			return ::new Link; //create extra space
		
		Link<T>* temp = freelist;
		freelist = freelist->next;
		return temp;			//return the link
	}

	/*overload the delete operator*/
	void operator delete(void *ptr)
	{
		((Link<T>*)ptr)->next = freelist;  //put on freelist
		freelist = (Link<T>*)ptr;
	}
};

//create the freelist hea dpointer 
template <typename T>
class DLList
{
private:
	Link<T>* head;   //pointer to list header
	Link<T>* next, prev;
	Link<T>* curr;   //access to current value
	// Link<T>* \
	Link<T>::freelist = nullptr;  //freelist to hold header of nodes
	Link<T>* tail;   //pointer to list's last value
	unsigned iter;


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

	//insert element at the present position
public:
	//constructors
	DLList() {};
	~DLList() {}

	void insert(const T& elem)
	{
	  curr->next = curr->next->prev = new Link<T>(elem, curr, curr->next);
		++iter;
	}

	void append(const T& elem)
	{
		tail->prev = tail->prev->next \
				   = new Link<T>(elem, tail->prev, tail);
				   ++iter;
	}

	T remove()
	{
		if(curr->next==tail)
			return nullptr;
		T elem = curr->next->elem;   //remember value
		Link<T>* ltemp = curr->next; //remember link node
		curr->next->next->previous = curr;
		curr->next = curr->next->next; //remove from list
		delete ltemp;
		--iter;

		return elem;
	}

	void previous()
	{
		if(curr != head)
		{
			curr = curr->prev;
		}
	}
};

int main(void)
{
	DLList<std::string> dll;

	std::string greet = "hello";
	dll.append(greet);
	return 0;
}