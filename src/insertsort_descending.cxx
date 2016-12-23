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

/*
*  Descending order insert sort
* Pseudocode
* for j = 1 to n
*    key = A[j]
* 	 i = j - 1
*    //insert A[j] into sorted array A[j-1, ..., 1]
*	 while(i>=0 and A[i] < key )
*		A[i+1]	 = A[i]
*			i = i - 1
*	 A[i+1] = key
*/

#include <array>
#include <typeinfo>
#include <iostream>

using std::cout;
using std::endl;

constexpr int param = 6;

template <typename arrayType>
std::array<arrayType,param> insertsort(std::array<arrayType,param> nums)
{
	auto arraylength = nums.size();                    //cost= 1

	for(auto j = 1; j < arraylength; ++j)              //cost= c1*n
	{
		auto key = nums[j];                           // cost= c2 * (n-1) 
		auto i = j - 1;								 // cost= c3 * (n-1) 
		//insert nums[j] into sorted array nums[j-1, ..., 1]
		while(i >=0 && nums[i] < key)                   // cost= c4 * sum_(j=1)^(n) *t_j 
		{
			nums[i+1] = nums[i];                         //cost= c5* sum_(j=1)^(n) * (t_j - 1)
			i = i - 1;									//cost= c6* sum_(j=1)^(n) * (t_j - 1)
		}
		nums[i+1] = key;								//cost= c7*n-1
	}
	return nums;                                      //cost = 1
}

int main()
{

	std::array<int, param> nums {31,41,59,26,41,58};
	auto array = insertsort(nums);

	cout << "sorted array is \n" ;

	for(auto cit=array.cbegin(); cit!=array.cend(); ++cit)
		cout << *cit << " " ;
	cout << "\n" << endl;

}