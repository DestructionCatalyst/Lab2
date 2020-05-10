#include <iostream>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "ArraySequence.hpp"
#include "ListSequence.hpp"
#include "Test.h"

using namespace std;
using namespace DynArray;
using namespace List;
using namespace Sequences;

int main() {
	
	testArraySequence();
	testListSequence();
	TestPolynom();
	
	return 0;
}