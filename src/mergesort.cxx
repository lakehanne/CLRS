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
#include <climits>

int sz = 10;		//an example length of array to be sorted

std::array<int,10> merge_algo(std::array<int,10> array)
{
	std::cout << "here";
	int p = 0; 
	int q = 5;
	int r = array.size();

	std::cout << p << ", " << q << ", " << r ;
	//split the array into two equal subarrays
	int n1= q-p+1;
	int n2 = r-q;

	std::array<int, 5> L {array[p], array[p+1],array[p+2],array[p+3],array[p+4]};
	std::array<int, 5> R;

	for(auto i = 0; i < n1; ++i)
	{
		L[i] = array[p+i-1];
	} 

	for(auto i = 0; i < n2; ++i)
		R[i] = array[q+i];

	auto inf = 1e6; //static_cast<int>(1.0/0.0); //std::numeric_limits<int>::max();
	L[n1] = inf;
	R[n2] = inf;

	auto i= 1, j = 1;

	for(auto k = p; p < r; ++k)
	{
		if(L[i] <= R[j])
		{
			array[k] = L[i];
			i = i +1;			
		}
		else
		{
			array[k] = R[j];
			j = j + 1;	
		} 
	}

	return array;
}

int main()
{
	std::array<int, 10> A {2,4,5,7,1,2,3,6,10,9};

	for(auto el : A) {std::cout << el << " ";}

	auto merged = merge_algo(A);

	std::cout << "merge sorted array is " << std::endl;

	for(auto cit = merged.cbegin(); cit!=merged.cend(); ++cit)
		std::cout << *cit << " "; 
	std::cout << "\n";

	return EXIT_SUCCESS;
}