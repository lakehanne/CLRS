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
#include <sstream>
#include <algorithm>
#include <string>

void reverse(char *str)
{	
	char * end = str;

	char tmp;		
		
	if (str) 
	 {	
		while (*end) 
	 	{				
	 		++end;			
	 	}			
		--end;
			
		while (str < end) 
		{
					
		 	tmp = *str;
					
		 	*str++ = *end;
					
		 	*end-- = tmp;			
	 	}		
	 }
}

int main()
{
	char* orig = "lekan";
	reverse(orig);

	return 0;
}