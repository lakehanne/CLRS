<<<<<<< HEAD

#include <iostream>
#include <cassert>

#include <list_adt.hpp>


#define OUT_INFO(__o__) std::cout << __o__ << std::endl;
//single linked list node
template<typename T> 
class Link
{
public:
	T element;		//value for the node
	Link *next; 	//pointer to next node in the list

	//constructors
	Link(const T& elemval, Link* nextval= nullptr)
	: element(elemval), next(nextval)
	{ }

	Link(Link* nextval = nullptr)
	{
		next = nextval;
	}
};

//linked list implementation
template <typename T>
class LList : public List <T>
{
private:
	Link<T>* head;   //pointer to list header
	Link<T>* tail;   //pointer to list's last element
	Link<T>* curr;   //access to current element
	int cnt;		//size of list

	void init()
	{
		curr = tail = head = new Link<T>;
		cnt = 0;
	}

	void removeall()
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
		removeall();
	}

	void print()
	{
		std::cout << "current elements of the list: " << std::endl;
		begin();   //set curr to beginning
		for(unsigned i = 0; i <= cnt; ++i)
		{			
			setPos(i);
			T val = getCurElem();
			std::cout << val << std::endl;
		}	

		std::cout << "size of list" << size() << std::endl;	
	}

	void clear() 	//clear all list contents
	{ 
		removeall(); 
		init();
 	}

 	/*Insert element at current position */
 	void insert(const T& elem)
 	{
 		curr->next = new Link<T> (elem, curr->next);
 		if(tail == curr)
 			tail = curr -> next; //new tail

 		++cnt;
 	}

 	void append(const T& elem)
 	{
 		tail->next = new Link<T>(elem, nullptr);
 		tail = tail->next;
 		cnt++;
 	}

 	//remove and return current element
 	T remove()
 	{
 		if(curr->next==nullptr)
 			std::cout<< "no element to remove" << std::endl;

 		T elem = curr->next->element;
 		Link<T>* ltemp = curr->next;		//remember link node

 		if(tail == curr->next)
 			tail == curr ;   				//remove from list
 		delete ltemp;
 		cnt--;
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
 		return cnt;
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
 		assert((pos>=0) && (pos<=cnt));
 		curr = head;

 		for(int i = 0; i <=pos; ++i)
 			curr = curr->next;
 	}

 	const T& getCurElem()
 	{
 		assert(curr->next != nullptr);
 		return curr->next->element;
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
	// OUT_INFO("current element: " << ll.getCurElem());

	// ll.print();

	return 0;
=======
#include <iostream>
#include <memory>

struct node{
	int x;
	std::shared_ptr<node> next;
};

int main(void)
{
	std::shared_ptr<node> root(new node);
	
	root->next = 0;
	root->x = 5;
	std::shared_ptr<node> conductor(root);

	if(conductor!=0)
	{
		while(conductor->next != 0)
		{
			std::cout << "conductor " << conductor->x << std::endl;
			conductor = conductor->next;
		}
	}
	conductor->next.reset(new node);
	conductor = conductor->next;
	conductor->next = 0;
	conductor->x = 42;
			std::cout << "conductor " << conductor->x << std::endl;
>>>>>>> 37ed7e71c752705a49d2f7d57b5e1c5a6f1e8302
}