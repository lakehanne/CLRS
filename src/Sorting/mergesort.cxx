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

#include <iostream>
#include <array>
#include <limits>

using namespace std;

template<typename T>
void merge(T* A, T start, T mid, T end)
{
	auto n1 = mid-start+1;
	auto n2 = end-mid;
	//initialize the two sub-arrays
	T L[n1+1] = {};
	T R[n2+1] = {};
	// cout << "n1: " << n1 << "\tn2: " << n2 << endl;
	cout << "L[i]: " << "\t";
	for(auto i = 0; i < n1; ++i)
	{
		L[i] = A[start+i-1];
		cout << L[i] << " ";
	}
	std::cout << "\n";
	for(auto j = 0; j < n2; ++j)
	{
		R[j] = A[mid+j];
	}
	//allocate sentinels
	L[n1+1] = std::numeric_limits<T>::max();
	R[n1+1] = std::numeric_limits<T>::max();
	auto i = 1; 
	auto j = 1;
	for(auto k = start; j < end; ++k){
		if(L[i] < R[i]){
			A[k] = L[i];
			i = i+1;
		}
		else{
			A[k] = R[j];
			j = j + 1;
		}
		cout << A[k] << " ";
	}
	std::cout << "\n";

}

template<typename T>
void mergesort(T A[], T start, T end){
	if(start < end){
	//mid is the midpoint between start and end
	int mid = static_cast<int>(floor((start + end)/2));
	// cout << "mid: " << mid << endl;
	mergesort(A, start, mid);
	mergesort(A, mid+1, end);
	merge(A, start, mid, end);		
	}
}

int main(int argc, char** argv){
	if(argc<2){
		std::cerr<< "you need to enter the array elements" << "\n";
	}

	// std::cout << "Enter the elements of the array followed by RETURN key" << "\n" ;
	int A[10] = {};
	A[0] = atoi(argv[1]);

	std::cout << "\n\nYou have entered the array: " << std::endl;
	for(auto i = 0; i < 10; ++i)
	{		
		A[i] = atoi(argv[i+1]);
		cout << A[i] << " ";
	}
	cout << "\n";
	
	mergesort(A, 0, 9);

	std::cout << "\n\nsorted array is " << std::endl;
	for(auto i = 0; i < 10; ++i){
		std::cout << A[i] << " " ;		
	}
}