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

template<typename T>        //make type of the array elements deducible
T summer(std::array<T,4> A)
{
	auto sum = 0;                 //auto type deduction; c++ 11
	/*Note the use of const iterator since what we are pointing to is not changing*/
	for(auto elem = A.cbegin(); elem!=A.cend(); ++elem)
		sum += *elem;
	
	return sum;
} 

//now an example in the main thread  
int main()
{
	double n1,n2,n3,n4; 
	//initialize n1, n2,n3,n4 to some values here	
    /*std::initializer_list c++11*/
  	std::array<double,4> array {1,2,3,4}; 
	auto sum = summer(array);
	auto avg = sum/array.size(); 

	std::cout << "sum of array elements is " << sum 
              << " \n average is " << avg << std::endl; 
	return EXIT_SUCCESS; 
}
