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
#include <cassert>
#include <cstring>
  
 
int do_atoi(char *input)
{
    unsigned temp = 0;
    for(unsigned i= 0; input[i] != '\0'; ++i )
    {
        temp = temp*10 + input[i]-'0'; 
    }
    return temp;
}

// Driver program to test atoi function
int main(int argc, char** argv)
{
    //note that char** is a pointer to an array of chars

    assert(argc==2);

    char *input = argv[1];
    std::cout << "input is " << input << std::endl;
    std::cout << "length of input is: " << strlen(input) + 1 << std::endl;
    int res = do_atoi(input);

    std::cout << "integer value is: " << res << std::endl;

    return 0;
}