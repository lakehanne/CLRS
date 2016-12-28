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

#include <array>
#include <typeinfo>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

constexpr int param = 6;

template <typename arrayType>
std::array<arrayType,param> insertsort(std::array<arrayType,param> nums)
{
	auto arraylength = nums.size();

	for(auto j = 1; j < arraylength; ++j)
	{
		auto key = nums[j];
		auto i = j - 1;
		// cout << typeid(j).name() << endl;
		//insert nums[j] into sorted array nums[1, ..., j-1]
		while(i >=0 && nums[i] > key)
		{
			nums[i+1] = nums[i];
			i = i - 1;
		}
		nums[i+1] = key;
	}
	return nums;
}

int main()
{
	//example
	std::array<int, param> nums {31,41,59,26,41,58};
	auto array = insertsort(nums);

	cout << "sorted array is \n" ;
	for(auto elems : array )
		cout << elems << " ";
	cout << "\n" << endl;

	//print with const iterator
	cout << "printed with const iterator" << endl;
	// std::array<int,param>::const_iterator cit;
	for(auto cit=array.cbegin(); cit!=array.cend(); ++cit)
		cout << *cit << " " ;
	cout << "\n" << endl;

	cout << "printed with for_each and lambda" << endl;
	std::for_each(array.cbegin(),array.cend(),[](int i){std::cout<<i<<" ";});
	std::cout << std::endl;

}