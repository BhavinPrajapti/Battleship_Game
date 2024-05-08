#ifndef PART3TESTS_H_
#define PART3TESTS_H_
#include <iostream>

using std::string;
using std::cout;
using std::endl;

#include "Board.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assert3True(bool condition, string failedMessage);

void part3tests();



#endif /* PART1TESTS_H_ */
