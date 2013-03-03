#include <iostream>
#include "list.h"
using std::cout;
using std::endl;
using namespace DataStructures;


int main() {
	List<int> n;
	List<double> n2;
	auto ii = n.begin();
	n.insert (ii , 3);
	n.insert (ii, 4);
	n.insert (ii, 6);
	for (auto &j:n) {
		cout << j << " ";
	}
	cout << endl;
	return 0;
}


//commit test 3