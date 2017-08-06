/**
 * Created by suli on 8/6/17.
 */

#include <stdio.h>

int function1(int a, int b) {
	int c = a;
	return 1;
}

void function2(int a) {
	int first = 5;
	int second = 6;
	int ret = function1(first, second);
}

int main(void) {
	int tmp = 1;
	int ret = function2(tmp);
	return 0;
}