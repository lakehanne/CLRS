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

int main()
{
	const char name[] = "Olalekan Ogunmolu";

	const char* ptrToName = name;
	//print elements of array
	for(char n : name){	std::cout << n << "";	}

	//print name itself
	std::cout << "\n\nname itself: " << name << std::endl;
	std::cout << "\n\nptrToName: " << ptrToName << std::endl;
	std::cout << "\n\nsize of name: " << sizeof(name) << std::endl;
}