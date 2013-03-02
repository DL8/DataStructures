#include <iostream>
#include "list.h"
using std::cout;
using std::endl;
using namespace DataStructures;

int main() {
	List<int> n (10);
	//List<int> n2(n);
	auto i = n.begin();
	cout << *i << endl;
	return 0;
}
