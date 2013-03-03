#include <iostream>
#include "list.h"
using std::cout;
using std::endl;
using namespace DataStructures;

int main() {
	List<int> n (10);
	List<int> n2 (n);
	auto i = n.begin();
	cout << *i << endl;
	*i = 3;
	cout << *i << endl;
	i++;
	for (auto i = n2.begin(); i != n2.end(); ++i) {
		cout << *i << endl;
	}
	return 0;
}
