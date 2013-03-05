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
class TypeTest {
public:
	//explicit TypeTest() = delete;
};

int main() {
	TEST_TITLE ("default c-tor");
	List<int> n;

	TEST_TITLE ("insert");
	auto ii = n.begin();
	n.insert (ii , 1);
	n.insert (ii, 2);
	n.insert (ii, 3);
	n.insert (ii - 1, 4);

	TEST_TITLE ("loop and print");
for (auto & j: n) {
		cout << j << " ";
	}
	cout << endl;

	TEST_TITLE ("copy c-tor, insert item after first");
	List<int> n2 (n);
	n2.insert (n2.begin() + 1, 5);
for (auto & j: n2) {
		cout << j << " ";
	}
	cout << endl;

	TEST_TITLE ("assignment");
	n2 = n;
for (auto & j: n2) {
		cout << j << " ";
	}
	cout << endl;

	TEST_TITLE ("compare lists");
	cout << (n == n2) << " " << (n != n2) << endl;

	TEST_TITLE ("add item and print");
	n2.insert (n2.end() - 2, 6);
for (auto & j: n2) {
		cout << j << " ";
	}
	cout << endl;

	TEST_TITLE ("compare lists");
	cout << (n == n2) << " " << (n != n2) << endl;

	TEST_TITLE ("erase first item");
	n2.erase (n2.begin());
for (auto & j: n2) {
		cout << j << " ";
	}
	cout << endl;

	TEST_TITLE ("erase last item");
	n2.erase (n2.end() - 1);
for (auto & j: n2) {
		cout << j << " ";
	}
	cout << endl;

	TEST_TITLE ("print original");
for (auto & j: n) {
		cout << j << " ";
	}
	cout << endl;

	//TEST_TITLE ("static assertion");
	//List<TypeTest> n3;

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

	TEST_TITLE ("out of bounds");
	ii = n2.begin();
	ii += n2.size();
	try {
		cout << *ii << endl;
	} catch (DataStructureException &e) {
		cout << "caught exception: " << e.what() << endl;
	}

	TEST_TITLE ("iterator arithmetics");
	ii -= 2;
	cout << *ii << endl;
	cout << * (ii - 1) << endl;
	cout << * (ii + 1) << endl;

	TEST_TITLE ("clear");
	cout << n.empty() << endl;
	n.clear();
	cout << n.empty() << endl;

	TEST_TITLE ("proper comparison");
	cout << (n == n2) << endl;
	n2 = n;
	cout << (n == n2) << endl;

	TEST_TITLE ("int* comparison");
	List<int *> pl;
	pl.insert (pl.begin(), nullptr);
	pl.insert (pl.begin(), (int *) &n);
	auto pl2 = pl;
	cout << (pl == pl2) << endl;
	pl2.insert (pl2.end(), (int *) &ii);
	cout << (pl == pl2) << endl;
	pl.insert (pl.end(), * (pl2.end() - 1));
	cout << (pl == pl2) << endl;

	return 0;
}
