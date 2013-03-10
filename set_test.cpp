#include "set.h"
#include "test_utils.h"
#include "exceptions.h"
#include <iostream>
using std::cout;
using std::endl;
using namespace DataStructures;

int main() {
	TEST_TITLE ("default c-tor");
	Set<int> s1;

	TEST_TITLE ("empty & size");
	cout << s1.empty() << " " << s1.size() << endl;

	TEST_TITLE ("insert");
	s1.insert (1);
	s1 = s1.insert (2);

	TEST_TITLE ("empty & size");
	cout << s1.empty() << " " << s1.size() << endl;

	TEST_TITLE ("assignment");
	auto s2 = s1;

	TEST_TITLE ("comparison");
	cout << (s1 <= s2) << " " << (s1 >= s2) << " " << (s1 < s2) << " " << (s2 < s1) << " " << (s1 == s2) << " " << (s1 != s2) << endl;

	TEST_TITLE ("erase");
	try {
		s2.erase (1);
		s2.erase (3);
	} catch (ElementDoesNotExist &e) {
		cout << "caught: " << e.what() << endl;
	}

	TEST_TITLE ("empty & size");
	cout << s2.empty() << " " << s2.size() << endl;

	TEST_TITLE ("comparison");
	cout << (s1 <= s2) << " " << (s1 >= s2) << " " << (s1 < s2) << " " << (s2 < s1) << " " << (s1 == s2) << " " << (s1 != s2) << endl;


	TEST_TITLE ("re-insert erased element");
	s2.insert (1);

	TEST_TITLE ("comparison");
	cout << (s1 <= s2) << " " << (s1 >= s2) << " " << (s1 < s2) << " " << (s2 < s1) << " " << (s1 == s2) << " " << (s1 != s2) << endl;

	TEST_TITLE ("copy c-tor");
	auto s3 (s2);
	cout << (s2 == s3) << endl;
	s3.insert (4);
	s2.insert (4);
	s2.insert (4);
	cout << (s2 == s3) << endl;

	TEST_TITLE ("iterate");
for (auto & i: s1) {
		cout << i << " ";
	}
	cout << endl;
for (auto & i: s2) {
		cout << i << " ";
	}
	cout << endl;

	TEST_TITLE ("union");
	s3.insert (7);
	auto un = s1.unite (s3);
for (auto & i: un) {
		cout << i << " ";
	}
	cout << endl;
	cout << (s1 <= un) << " " << (s3 <= un) << endl;

	TEST_TITLE ("intersection");
	auto in = s3.intersect (s1);
for (auto & i: in) {
		cout << i << " ";
	}
	cout << endl;
	cout << (in <= s1) << " " << (s3 >= in) << endl;

	TEST_TITLE ("clear");
	cout << s3.empty() << endl;
	s3.clear();
	cout << s3.empty() << endl;

	return 0;
}
