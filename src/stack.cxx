
#include <iostream>
#include <vector>

#define INFO(__o__)	std::cout << __o__ << std::endl;
#define ERROR(__o__)	std::cerr << __o__ << std::endl;
 
template<typename T>
class stack{
private:
	unsigned top, maxSize;
	T* elem;  				//this holds the elements of the stack
public:
	//constructor
	stack(unsigned size)
	: maxSize(size), top(-1), elem(new T[size])
	{}

	//destructor
	~stack()
	{
		delete [] elem;
	}

	bool isEmpty()
	{
		if(top == 0)
		{
			return true;
		}
		else
			return false;
	}

	void push(T&& x)
	{
		if(top >= maxSize){
			ERROR("Stack overflow");
		}
		top += 1;
		elem[top] = x;
		INFO("Pushed " << x << " to Stack");
	}

	T pop()
	{
		if (isEmpty()){
			ERROR("Stack underflow");
			return -1;
		}
		else
		{
			top -= 1;
			return elem[top+1];
			INFO("removed " << elem[top+1] << " from stack");
		}
	}
};

int main(void)
{
	stack<unsigned> s(200);
	s.push(1);
	s.push(25);
	s.push(50);
	s.push(500);
	s.pop();

	return 0;
}