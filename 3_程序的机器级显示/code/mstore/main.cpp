/*
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2022-01-19 20:23:28
 * @LastEditors: sch
 * @LastEditTime: 2022-03-28 09:52:04
 */
#include <iostream>
#include <stdlib.h

void multipy(long&, long&, long&);


int main(int argc, char **argv) {
	int value1 = std::atoi(argv[1]);
	int value2 = std::atoi(argv[2]);
	int result = multipy(value1, value2);
	std::cout << result << std::endl;
	return EXIT_SUCCESS;
}