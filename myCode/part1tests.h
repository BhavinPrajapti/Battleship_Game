#ifndef PART1TESTS_H_
#define PART1TESTS_H_
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
void assertTrue(bool condition, string failedMessage);

void part1tests();



#endif /* PART1TESTS_H_ */
