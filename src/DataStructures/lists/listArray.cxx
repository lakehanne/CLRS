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

#include <cassert>
#include <iostream>
#include <algorithm>

#define OUT(__x__)	std::cout << __x__ << std::endl;

//List implementation
template<typename T>
class arrayList 
{
private:
	//a dynamic arrayList wouldn't need sizeLimit
	int sizeLimit;				//maximum list size
	int currentSize;			//current list size now
	int currentPos;				//position of current element
	T*	listArray;					//array holding list elements

	void clear()
	{
		delete [] listArray;
		currentSize = currentPos = 0;
		listArray = new  T[sizeLimit];
	}

	/*resize should cost O(2n) due to the doubling*/
	inline void resize(){
		sizeLimit *= 2;
		int tempCurPos = currentPos;  			//keep track of current position
		int tempListSize = currentSize;		//keep track of current currentSize
		T* tempListArray = new T[sizeLimit];		//allocate new memory
		std::copy(listArray, listArray+sizeLimit, tempListArray);	//copy all contents to temp listArray
		this->clear();							//reset previous elements	
		listArray = new T[sizeLimit];				//allocate new array listArray
		currentSize = tempListSize;				//assign the current size of the list
		currentPos = tempCurPos;					//reassign currentPos
		setPos(currentPos);							//reset new position
		delete [] tempListArray;				//delete newly allocated array memory
		OUT("array size now: " << sizeLimit << "current Size: " << currentSize);
	}
protected:
	/*these functions are not used in the program*/
	inline void begin()
	{
		currentPos = 0;
	}

	inline void end()
	{
		currentPos = currentSize;
	}

	inline void prev()	{
		if(currentPos !=0 )
		{
			--currentPos;
		}
	}

	inline void next()	{
		// if(currentPos != currentSize )
			++currentPos;
	}

	const T& getCurElem() const
	{
		return listArray[currentPos];
	}

public:
	arrayList(int defaultSize=5) 
	: sizeLimit(defaultSize), currentPos(0), currentSize(0), listArray(new T[sizeLimit])
	{
		OUT("currentSize: " << currentSize << " maxSize: " << sizeLimit);
	}
	//destructor
	~arrayList()
	{ 
		delete [] listArray;
	}

	arrayList(arrayList const&)=delete;			//prevent compiler copy constructor
	arrayList& operator=(arrayList const&) = delete;		//prevent assigment copies

	void insert(const T& elem)
	{
		/*We'll copy all the elements of the old array into a new array and insert*/
		OUT("currentSize: " << currentSize << " sizeLimit: " << sizeLimit);
		// if(currentSize < sizeLimit)	{
			for(int i = currentSize; i < currentPos; i--)
			{
				listArray[i] = listArray[i-1];    //shift elements up to make room
				OUT("listArray[i]: " << listArray[i]);
			}
				OUT("here");
		// }
		listArray[currentPos] = elem;
		++currentSize;
		OUT("inserted: " << elem << " into array: | size: " << size());
	}

	void append(const T& elem)
	{
		listArray[currentSize++] = elem;
	}

	T remove()
	{
		assert(currentPos >= 0 && currentPos < currentSize);
		T elem = listArray[currentPos]; 	//copy the element
		for (auto i = currentPos; i < currentSize-1; ++i)
		{
			listArray[i] = listArray[i+1];
		}
		--currentSize;
		return elem;
	}

	void print() const{
		OUT("\nprinting array elements");
		for(auto i = 0; i < currentSize; ++i){
			OUT(listArray[i] << " ");
		}
	}

	int size() const
	{
		return currentSize;
	}

	void setPos(int pos)
	{
		if(currentPos > currentSize)
			resize();
		currentPos = pos;
	}
};

int main(void)
{
	arrayList<int> arrayObj(10);

	int num;

	OUT("Please enter a number to insert into the list.\n Type \"-0\" to stop.");
	for(;;){
		std::cin>>num;
		if(num==-0) break;
		arrayObj.insert(num);
	}

	// arrayObj.setPos(20);
	arrayObj.print();


	return 0;
}