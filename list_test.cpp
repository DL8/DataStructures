#include <iostream>
#include "list.h"
#include "test_utils.h"
using std::cout;
using std::ostream;
using std::endl;
using namespace DataStructures;

/**
 * @brief used for static assertion tests
 */
class StaticAssertTest {
public:
	//explicit StaticAssertTest() = delete;
};

int main() {
	LINE_NUMBER();
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

	LINE_NUMBER();
	List<int> n2 (n);
	n2.insert (n2.begin() + 1, 5);
for (auto & j: n2) {
		cout << j << " ";
	}
	cout << endl;

	LINE_NUMBER();
	n2 = n;
for (auto & j: n2) {
		cout << j << " ";
	}
	cout << endl;

	LINE_NUMBER();
	n2.insert (n2.end() - 2, 6);
for (auto & j: n2) {
		cout << j << " ";
	}
	cout << endl;

	LINE_NUMBER();
	n2.erase (n2.begin());
for (auto & j: n2) {
		cout << j << " ";
	}
	cout << endl;

	LINE_NUMBER();
	n2.erase (n2.end() - 1);
for (auto & j: n2) {
		cout << j << " ";
	}
	cout << endl;

	LINE_NUMBER();
for (auto & j: n) {
		cout << j << " ";
	}
	cout << endl;

	TEST_TITLE ("static assertion");
	List<StaticAssertTest> n3;

	TEST_TITLE ("empty list assignment");
	n = List<int>();

	TEST_TITLE ("empty() and size()");
	cout << n.size() << " " << n.empty() << endl;
	n.insert (n.end(), 2);
	n.insert (n.end(), 4);
	cout << n.size() << " " << n.empty() << endl;

	TEST_TITLE ("increment/decrement");
	ii = n.begin();
	cout << *++ii << endl;
	cout << *ii-- << endl;

	return 0;
}
