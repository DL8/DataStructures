#include <iostream>
#include "list.h"
using std::cout;
using std::endl;
using namespace DataStructures;


int main() {
	List<int> n;
	auto ii = n.begin();
	n.insert (ii , 1);
	n.insert (ii, 2);
	n.insert (ii, 3);
	n.insert (ii - 1, 4);
for (auto & j: n) {
		cout << j << " ";
	}
	cout << endl;

	List<int> n2 (n);
	n2.insert (n2.begin() + 1, 5);
for (auto & j: n2) {
		cout << j << " ";
	}
	cout << endl;

	n2 = n;
	n2.insert(n2.end()-2, 6);
for (auto & j: n2) {
		cout << j << " ";
	}
	cout << endl;
	
	for (auto & j: n) {
		cout << j << " ";
	}
	cout << endl;

	return 0;
}


