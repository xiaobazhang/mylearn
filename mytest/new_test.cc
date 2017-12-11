/**
 * Created by suli on 17/11/9.
 */

#include <iostream>

int BinaryFind(int array[], int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (array[mid] > target) {
			end = mid - 1;
		} else if (array[mid] < target) {
			start = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int main(void) {
	int list[749] = {0};
	for (int i = 0; i < 749; i++) {
		list[i] = i;
	}
	int index = 0;
	index = BinaryFind(list, 0, 748, 616);
	std::cout << "index = " << index << " value :" << list[index] << "expect:616" << std::endl;

}

