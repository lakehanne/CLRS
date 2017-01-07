#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec;
int j;

int main()
{
	for(int i = 5; i < 5*3; ++i)
	{
		vec.push_back(i);
	}

	using std::cout;

	for(int i : vec)
	{
		cout << "vector content, " << j <<": " << i << "\n";
		++j;		
	}

	j = 0 ; //reset j to zero;

	//try std iterator
	std::vector<int>::const_iterator citer;
	for(citer=vec.cbegin(); citer!=vec.cend(); ++citer)
		cout << "citer: " << ++j << ": " << *citer << "\n";




	// test for each
	std::for_each(vec.begin(), vec.end(), bind1st(operator<<, std::cout)
	{
		std::cout << "this is " << i << "\n";
	}
	
	return 0;
}