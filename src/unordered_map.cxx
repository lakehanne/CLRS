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

// unordered_map::swap

//adapted from cpp reference

#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string>
     first = {{"Star Wars","G. Lucas"},{"Alien","R. Scott"},{"Terminator","J. Cameron"}},
     second  = {{"Inception","C. Nolan"},{"Donnie Darko","R. Kelly"}};

  first.swap(second);

  std::cout << "first: ";
  for (auto x: first) std::cout << x.first << " (" << x.second << "), ";
  std::cout << std::endl;

  std::cout << "second: ";
  for (auto& x: second) std::cout << x.first << " (" << x.second << "), ";
  std::cout << std::endl;

  return 0;
}