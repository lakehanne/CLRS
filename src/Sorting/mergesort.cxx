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
#include <cmath>
#include <limits>

using namespace std;

template<typename T>
T* merge(T A[], T start, T mid, T end)
{
	T n1 = mid-start+1;
	T n2 = end-mid;
	//initialize the two sub-arrays
	T L[n1+1] = {};
	T R[n2+1] = {};

	for(T i = 0; i < n1; ++i)
	{
		L[i] = A[start+i-1];
	}
	
	for(T j = 0; j < n2; ++j)
	{
		R[j] = A[mid+j];
	}
	//allocate sentinels
	L[n1+1] = std::numeric_limits<T>::max();
	R[n1+1] = std::numeric_limits<T>::max();
	T i = 1; 
	T j = 1;
	for(T k = start; j < end; ++k){
		if(L[i] <= R[i]){
			A[k] = L[i];
			i = i+1;
		}
		else{
			A[k] = R[j];
			j = j + 1;
		}
	}
	return A;
}

template<typename T>
T* mergesort(T A[], T start, T end)
{	
	T *B;
	if(start < end)
	{
		//mid is the midpoint between start and end
		int mid = floor((start + end)/2);
		// cout << "mid: " << mid << endl;
		mergesort(A, start, mid);
		mergesort(A, mid+1, end);
		B = merge(A, start, mid, end);		
	}
	return B;
}

int main(int argc, char** argv){
	int num;
	int n = 5;
	int A[n] = {};
	std::cout << "please enter the array elemets one after the other" << std::endl;
	for(int i = 0; i < n; ++i){
		std::cin>>A[i];
	}

	std::cout << "\n\nYou have entered the array: " << std::endl;
	for(int i = 0; i < n; ++i)
	{		
		cout << A[i] << " ";
	}
	
	int* B = mergesort(A, 0, n-1);
	std::cout << "\n\nsorted array is " << std::endl;
	// std::cout << B << std::endl;
	for(int i = 0; i < n; ++i)
	{
		std::cout << B[i] << " " ;		
	}
}