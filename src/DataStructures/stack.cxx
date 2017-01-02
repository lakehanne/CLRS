/*  
*  Copyright December 2016
*  Author: Olalekan P. Ogunmolu
*
* Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* 
* See the License for the specific language governing permissions and
* limitations under the License.
* 
*/

//Questions 10.1-1
#include <iostream>
#include <memory>

#define INFO(__o__)	std::cout << __o__ << std::endl;
#define ERROR(__o__) std::cerr << __o__ << std::endl;
 
template<typename T>
class stack{
private:
	int top, maxSize;
	std::unique_ptr<T[]> elem;  	//this holds the elements of the stack
public:
	//constructor
	stack(int size)
	: maxSize(size), top(-1), elem(new T[maxSize])
	{
		INFO("top: " << top << " | maxSize: " << maxSize);
	}

	//destructor
	~stack()
	{
		// delete [] elem;
	}

	void print() const 
	{
		INFO("Stack elements are: ");
		for(auto i = 0; i <= top; ++i)
		{
			INFO(elem[i]);
		}
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
		if (!isEmpty())
		{
			top -= 1;
			INFO("popped " << elem[top+1] << " from stack");
		}
		return elem[top+1];
	}
};

int main(void)
{
	stack<int> s(6);
	//Question 10.1
	s.push(4);
	s.push(1);
	s.push(3);
	s.pop();
	s.push(8);
	s.pop();

	s.print();

	return 0;
}