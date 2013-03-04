#ifndef _TEST_UTILS_H_
#define _TEST_UTILS_H_

#include <iostream>

/**
 * @brief prints the line number in a formatted manner
 */
#define LINE_NUMBER() \
	std::cout << "line #" << __LINE__ << std::endl;

#endif
