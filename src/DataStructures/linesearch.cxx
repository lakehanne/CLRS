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
*  Line Search
*
*/

#include <iostream>
#include <vector>

int linesearch(std::vector<int> seq, int v)
{
	for(auto i = 0; i < seq.size(); ++i)
	{
		if (v == seq[i])
			return i;
		// else
	}	
		return 0;
}

int main(int argc, char** argv)
{
	std::vector<int> sequence(10, 10);
	for(auto i = 0; i < sequence.size(); ++i)
		sequence[i] = i*5;

	auto v = atoi(argv[1]); //14;
	std::cout << v << "'s index is "  << linesearch(sequence, v) << std::endl;

	return 0;
}