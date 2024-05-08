#ifndef PART2TESTS_H_
#define PART2TESTS_H_
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
void assert2True(bool condition, string failedMessage);

void part2tests();




#endif /* PART2TESTS_H_ */
