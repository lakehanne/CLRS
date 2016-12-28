#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

// using array = int*[];
// template<typename T>
std::vector<int> add2bits(int* A[], int* B[])
{
	auto n = sizeof(A);
	std::vector<int> C(n);

	auto carry = 0;

	for(unsigned i = 0; i < n; ++i)
	{
		C[i] = (*A[i] + *B[i] + carry) % 2;
	}
	C[n] = carry;

	return C;
}


int main(int argc, char** argv)
{
	std::vector<int> A; 
	std::vector<int> B;

	char* temp[256]; //temporary buffer to hold arrays A and B

	for(int i = 0; i < argc; ++i)
	{
		temp[i] = argv[i];
		std::cout << temp[i] << std::endl;
	}


/*	
	std::string Atemp, Btemp;		//A is the array containing the first bin

	std::cout << "Please enter the elements of array A" << "\n";
	std::getline(std::cin, Atemp);

	auto Asize = Atemp.size();
	int A[Asize] = {};  //allocate memory for A matrix
	std::cout << "A matrix is" << "\n";

	// std::stringstream ss(Atemp);
	// A = reinterpret_cast<int>(ss >> Atemp);
	for(unsigned elem = 0; elem < Asize; ++elem)
	{
		std::cout << (Atemp[elem]) << std::endl;
		// A[elem] = reinterpret_cast<unsigned>(Atemp.substr(elem, std::find(, )));
	}

	//Do the same for array B
	std::cout << "Please enter the elements of array B" << "\n";
	std::getline(std::cin, Btemp);

	auto Bsize = Btemp.size();
	int B[Bsize] = {};  //allocate memory for A matrix
	std::cout << "B matrix is" << "\n";

	for(auto elem =0; elem < Bsize; ++elem)
	{
		std::cout << Btemp[elem] << std::endl;
		// B[elem] = atoi(Btemp[elem]);
	}

	std::vector<int> C = add2bits(A, B);

	std::cout << "C = A + B: " << std::endl;
	for(auto el : C)
		std::cout << el << " " << std::endl;*/

	return 0;
}