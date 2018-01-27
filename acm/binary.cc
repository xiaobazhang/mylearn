/**
 * Created by suli on 18/1/16.
 */

#include "binary.h"

int algo::binary(int *array, int start, int end, int target) {
	if ((end - start) < 0) {
		return -1;
	}
	while (start <= end) {
		int mid = (start + end + 1) / 2;
		if (array[mid] > target) {
			end = mid - 1;
		} else if (array[mid] < target) {
			start = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}

void algo::binary_test() {
	int array[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
	int target = 19;
	int i = binary(array, 0, 9 - 1, target);
	printf("i=%d,array[i]=%d\n", i, array[i]);
}

