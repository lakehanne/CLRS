#include <iostream>
#include <vector>
#include <cassert>

#define OUT_INFO(__O__) std::cout<<__O__<<std::endl

void process_copy(std::vector<int> const& vec_)
{
	std::vector<int> vec(vec_);
	// vec.push_back(42);
	// vec.push_back(43);
	// vec.push_back(44);
	// vec.push_back(45);

	for(auto x : vec_) OUT_INFO(x);
}

int main()
{
	int&& var=42;
	int& ref=var;
	ref=99;
	assert(var==99);

	std::vector<int> vec;

	vec.push_back(42);
	vec.push_back(43);
	vec.push_back(44);
	vec.push_back(45);

	process_copy(vec);

	OUT_INFO("var " << var << " | ref: " << ref);
	return 0;
}


