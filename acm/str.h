/**
 * Created by suli on 18/1/24.
 */

#ifndef ALGO_STR_H
#define ALGO_STR_H
#include <string.h>
#include <stdio.h>

class str {
 public:
	str() {}
	~str() {}
	void invertstr(char *p) {
		char *ptr1 = p;
		char *ptr2 = p;
		while (*ptr2) {
			ptr2++;
		}
		ptr2--;
		while (ptr1 < ptr2) {
			char t = *ptr1;
			*ptr1 = *ptr2;
			*ptr2 = t;
			ptr1++;
			ptr2--;
		}
	}

};

#endif //ALGO_STR_H
