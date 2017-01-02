/*  
*  Copyright December 2016
*  Author: Lekan Ogunmolu
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

#include <memory>
#include <cassert>
#include <algorithm>
#include <iostream>

#include "list_adt.hpp"

//List implementation
template<typename T>
class ListImpl : public List<T>
{
private:
	unsigned maxSize;			//maximum list size
	unsigned listSize;			//current list size now
	unsigned curPos;				//position jof current element
	T*	listArray;			//array holding list elements

public:
	ListImpl(unsigned defaultSize) 
	: maxSize(defaultSize), curPos(0), listSize(curPos), listArray(new T[maxSize])
	{}
	//destructor
	~ListImpl()
	{ 
		delete [] listArray;
	}

	void clear()
	{
		delete [] listArray;
		listSize = curPos = 0;
		listArray = new  T[maxSize];
	}

	void insert(const T& elem)
	{
		if(listSize > maxSize)
			std::cerr << "list capacity exceeded" << std::endl;

		for(auto i = listSize; i > curPos; --i)
		{
			listArray[i] = listArray[i-1];    //shift elements up to make room
			listArray[curPos] = elem;
			++listSize;
		}
	}

	void append(const T& elem)
	{
		// assert(listSize < maxSize);
		listArray[listSize++] = elem;

	}

	T remove()
	{
		assert(curPos >= 0 && curPos < listSize);
		T elem = listArray[curPos]; 	//copy the element
		for (int i = curPos; i < listSize-1; ++i)
		{
			listArray[i] = listArray[i+1];
		}
		--listSize;
		return elem;
	}

	void begin()
	{
		curPos = 0;
	}

	void end()
	{
		curPos = listSize;
	}

	void prev()
	{
		if(curPos !=0 )
		{
			--curPos;
		}
	}

	void next()
	{
		if(curPos != listSize )
			++curPos;
	}

	int size() const
	{
		return listSize;
	}

	int currPos() const
	{
		return curPos;
	}

	void setPos(int pos)
	{
		if(curPos<0 || curPos > listSize)
			std::cerr << "the index you have specified is out of range " << std::endl;
		curPos = pos;
	}

	const T& getCurElem()
	{
		return listArray[curPos];
	}
};

int main(void)
{
	ListImpl<int> limp(500);
	// ListImpl(5) limp;
	// limp.append(10);
	limp.setPos(2);
	std::cout << "current position: " << limp.currPos() <<"\n"
			  << "size: " << limp.size()<< std::endl;

	limp.end();
	std::cout << "current position after moveToEnd: " << limp.currPos() <<"\n";

	limp.begin();
	std::cout << "current position after moveToStart: " << limp.currPos() <<"\n";
/*
	for(auto el : limp)
		std::cout << el << " " ;

*/	const int i = 5;
	limp.insert(i);
	std::cout << "insert 50" << limp.getCurElem() << "\n";


	return 0;
}