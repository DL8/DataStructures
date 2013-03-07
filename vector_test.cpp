#include "vector.h"
#include "test_utils.h"
#include <iostream>
using namespace DataStructures;
using std::cout;
using std::endl;

int main() {
	TEST_TITLE ("default c-tor");
	Vector<char> v;

	TEST_TITLE ("size & empty");
	cout << v.size() << " " << v.empty() << endl;

	TEST_TITLE ("illegal index access");
	try {
		v.at (-1);
	} catch (OutOfBounds &e) {
		cout << "caught: " << e.what() << endl;
	}

	TEST_TITLE ("append");
	v.append ('h');

	TEST_TITLE ("[] access");
	cout << v[0] << endl;

	TEST_TITLE ("[] reference edit");
	v[0]++;
	cout << v[0] << endl;

	TEST_TITLE ("at() access (edit)");
	v.at (0) = 'b';

	TEST_TITLE ("iterator insert");
	v.insert (v.begin(), 'n');
	v.insert (v.end(), 't');
	v.insert (v.end() - 1, 'y');

	TEST_TITLE ("loop");
for (auto & j: v) {
		cout << j << " ";
	}
	cout << endl;

	TEST_TITLE ("iterator access");
	auto ci = v.begin();
	cout << *ci << " " << * (ci + 1) << endl;
	*ci = 'r';
	cout << *ci << endl;
	ci++;

	TEST_TITLE ("erase");
for (auto j: v) {
		cout << j << " ";
	}
	cout << endl;
	v.erase (ci+1);
for (auto j: v) {
		cout << j << " ";
	}
	cout << endl;

	TEST_TITLE ("size & clear");
	cout << v.size() << endl;
	v.clear();
	cout << v.size() << endl;
	return 0;
}
