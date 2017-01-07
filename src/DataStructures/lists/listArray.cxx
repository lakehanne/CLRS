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

#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>

#define OUT(__x__)	std::cout << __x__ << std::endl;
#define OUTL(__x__)	std::cout << __x__ << " ";

//List implementation
template<typename T>
class arrayList 
{
private:
	//a dynamic arrayList wouldn't need sizeLimit
	int sizeLimit;					//maximum list size
	int currentSize;				//current list size now
	int currentPos;					//position of current element
	T*	listArray;					//array holding list elements

	void clear(){
		delete [] listArray;
		currentSize = currentPos = 0;
		listArray = new  T[sizeLimit];
	}

	int size() const{
		return currentSize;
	}

	/*resize should cost O(2n) due to the doubling*/
	inline void resize(){
		sizeLimit *= 2;
		T* tempListArray = new T[sizeLimit];		//allocate new memory
		/*copy all contents to temp listArray*/
		std::copy(listArray, listArray+sizeLimit, tempListArray);	

		delete [] listArray;							//reset previous elements	
		listArray = new T[sizeLimit];					//allocate new array listArray
		std::copy(tempListArray, tempListArray+sizeLimit, listArray);	//transfer elements to listArray

		delete [] tempListArray;				//delete newly allocated array memory
		OUT("array size reset: " << sizeLimit << "| current Size: " << currentSize);

		OUT("listArray elems: ")
		for(auto i = 0; i < currentSize; ++i){
			OUTL(listArray[i] << " ");
		}
	}

public:
	/*Constructor*/
	arrayList(int defaultSize=5) 
	: sizeLimit(defaultSize), currentPos(0), currentSize(0), listArray(new T[sizeLimit])
	{	}
	/*destructor*/
	~arrayList()
	{ 
		delete [] listArray;
	}

	arrayList(arrayList const&)=delete;			//prevent compiler copy constructor
	arrayList& operator=(arrayList const&) = delete;		//prevent assigment copies

	void insert(const T& elem){
		/*We'll copy all the elements of the old array into a new array and insert*/
		if(isFull()){	resize();	}
		/*shift elements up to make room*/
		for(int i = currentSize; i > currentPos  ; --i)
		{
			listArray[i] = listArray[i-1];    
			OUT("listArray[i]: " << listArray[i]);
		}
		listArray[currentPos] = elem;
		++currentSize;
		++currentPos;
		OUT("inserted: " << elem << " into array");
		OUT("currentPos: " << currentPos << " | currentSize: " << currentSize << " | sizeLimit: " << sizeLimit);
	}

	bool isFull(){
		if (currentSize == sizeLimit)
		{
			return true;
		}
		else{
			return false;
		}
	}

	void append(const T& elem)
	{
		listArray[currentSize++] = elem;
	}

	T remove()
	{
		assert(currentPos >= 0 && currentPos <= currentSize);
		T elem = listArray[currentPos]; 	//copy the element
		for (auto i = currentPos; i < currentSize; ++i)
		{
			listArray[i] = listArray[i+1];
		}
		--currentSize;
		return elem;
		OUT("removed: " << elem);
	}

	T find(const T& elem){
		for(auto i = 0; i < currentSize; ++i)
		{
			if(elem == listArray[i])
			{
				OUT("Found " << elem);
				return listArray[i];
			}
		}
		OUT("element not in list");
		return 0;
	}

	void print() const{
		OUT("\nprinting array elements");
		for(auto i = 0; i < currentSize; ++i){
			OUT(listArray[i] << " ");
		}
	}
};

int main(void)
{
	int maxSize;
	OUT("enter initial array maxSize");
	std::cin>>maxSize;
	arrayList<int> arrayObj(maxSize);

	int num;

	OUT("Please enter a number to insert into the list.\n Type \"-0\" to stop.");
	for(;;){
		std::cin>>num;
		if(num==-0) break;
		arrayObj.insert(num);
	}

	OUT("enter an item to find");
	std::cin>>num;
	arrayObj.find(num);

	arrayObj.append(20);
	// arrayObj.remove();
	arrayObj.print();



	return 0;
}