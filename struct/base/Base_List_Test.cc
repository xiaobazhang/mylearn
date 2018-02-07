/**
 * Created by suli on 18/1/27.
 */

#include "Base_List.h"
#include <iostream>

using namespace Base;

int main(void) {

	List<int> test;
	for (int i = 0; i < 10; i++) {
		test.push_back(i);
		printf("size=%d\n", test.size());
	}
	for (int i = 0; i < test.size(); i++) {
		printf("value=%d\n", test[i]);
	}
	test.reverse();
	test.pri();
	/*List<int>::iterator iter = test.begin();
	for (; iter != test.end(); iter++) {
		printf("iter value=%d\n", *iter);
	}*/
	for (int i = 0; i < test.size(); i++) {
		printf("invert value=%d\n", test[i]);
	}
	test.clear();
	printf("size = %d\n", test.size());

	return 1;
}



