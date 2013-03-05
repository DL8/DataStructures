#include "queue.h"
#include "test_utils.h"
#include "exceptions.h"
#include <iostream>
using std::cout;
using std::endl;
using namespace DataStructures;

int main() {
	TEST_TITLE ("default c-tor");
	Queue<int> q1;

	TEST_TITLE ("empty & size");
	cout << q1.empty() << " " << q1.size() << endl;

	TEST_TITLE ("push");
	q1.push (1);
	q1 = q1.push (2);

	TEST_TITLE ("empty & size");
	cout << q1.empty() << " " << q1.size() << endl;

	TEST_TITLE ("assignment");
	auto q2 = q1;

	TEST_TITLE ("comparison");
	cout << (q1 == q2) << " " << (q1 != q2) << endl;

	TEST_TITLE ("dereference");
	*q1 = 3;
	cout << (q1 == q2) << " " << (q1 != q2) << endl;

	TEST_TITLE ("copy c-tor");
	auto q3 (q2);
	cout << (q2 == q3) << endl;
	q3.push (4);
	q2.push (4);
	cout << (q2 == q3) << endl;

	TEST_TITLE ("clear");
	cout << q3.empty() << endl;
	q3.clear();
	cout << q3.empty() << endl;

	TEST_TITLE ("pop");
	*q2 = 5;
	int tmp = q2.pop();
	cout << tmp << endl;
	q2.push (tmp);
	while (!q2.empty()) {
		q3.push (*q2);
		cout << q2.pop() << " ";
	}
	cout << endl;
	cout << q2.empty() << endl;
	while (!q3.empty()) {
		cout << q3.pop() << " ";
	}
	cout << endl;

	TEST_TITLE ("Empty exception");
	try {
		q3.pop();
	} catch (Empty &e) {
		cout << "caught: " << e.what() << endl;
	}

	return 0;
}
