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

	TEST_TITLE ("enqueue");
	q1.enqueue (1);
	q1.enqueue (2);

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
	q3.enqueue (4);
	q2.enqueue (4);
	cout << (q2 == q3) << endl;

	TEST_TITLE ("clear");
	cout << q3.empty() << endl;
	q3.clear();
	cout << q3.empty() << endl;

	TEST_TITLE ("dequeue");
	*q2 = 5;
	int tmp = q2.dequeue();
	cout << tmp << endl;
	q2.enqueue (tmp);
	while (!q2.empty()) {
		q3.enqueue (*q2);
		cout << q2.dequeue() << " ";
	}
	cout << endl;
	cout << q2.empty() << endl;
	while (!q3.empty()) {
		cout << q3.dequeue() << " ";
	}
	cout << endl;

	TEST_TITLE ("QueueIsEmpty exception");
	try {
		q3.dequeue();
	} catch (QueueIsEmpty &e) {
		cout << "caught: " << e.what() << endl;
	}

	return 0;
}
