#include <iostream>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Test.h"

//using namespace std;
using namespace DynArray;
using namespace List;
using namespace Sequences;

int main() {
	
	std::string command{""};
	int arg1{0};
	int arg2{0};

	std::cin >> command >> arg1;
	std::cin >> arg2;

	testArraySequence();
	testListSequence();
	TestPolynom();
	
	return 0;
}