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
class queue{
private:
	int maxSize, qtail, qhead;
	std::unique_ptr<T[]> Q;
	// std::shared_ptr<T[]> delElem;

public:
	//constructors
	queue(int size)
	: maxSize(size), qhead(1), qtail(1), 
		Q(new T[maxSize])//, [](T* elemp){ delete[] elemp; })
	{
	}

	//destructor
	~queue()
	{
		// std::default_delete<int>[]() elem;
	}

	//another way of deleting new[] shared ptr
	// auto delElem = [](T* elemp){ delete[] elemp;}

	bool isEmpty()
	{
		if(qhead == qtail)
		{
			INFO("Queue is empty");
			return true;
		}
		else
		{
			// INFO("Queue undeflow");
			return false;
		}
		// return ;
	}

	void enqueue(T&& x)				//this is the insert op
	{
		INFO("inserted: " << x << " into queue");
		Q[qtail] = x;
		if (qtail == maxSize)
		{
			qtail = 1;	 //reset
		}
		else	 
		{			
			qtail += 1;
		}
	}

	T dequeue()
	{
		T x = Q[qhead];
		if (qhead == maxSize)
		{
			qhead = 1;			//reset
		}
		else
		{
			qhead += 1;
			INFO("removed " << x << " from queue");
		}
		return x;
	}

	void print() const 
	{
		if(qtail != qhead)
		{
			for(int i = qhead; i < qtail; ++i)
			{
				std::cout << Q[i] << " ";
			}
			std::cout << std::endl;
		}
		else  if(qhead == (qtail+1))
		{
			ERROR("Queue overflow");
		}
		else
		{
			ERROR("Queue undeflow");
		}
	}
};

int main(void)
{
	queue<int> Q(10);
	Q.enqueue(10);
	Q.enqueue(100);
	Q.enqueue(1000);
	Q.enqueue(10000);
	Q.enqueue(100000);
	Q.dequeue();
	Q.dequeue();
	Q.dequeue();
	Q.dequeue();
	Q.dequeue();
	Q.dequeue();
	Q.dequeue();

	Q.print();

}