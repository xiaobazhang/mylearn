/**
 * Created by suli on 18/2/4.
 */

#ifndef ALGO_BASE_SORT_H
#define ALGO_BASE_SORT_H

#include <iostream>

namespace Base {
template<typename T, typename Compare>
class Base_Sort {
 public:
	Base_Sort(T &begin, T &end, Compare compare);
	Base_Sort(T &begin, T &end);

 private:
	bool quick_sort(T &begin, T &end);

};
}

#endif //ALGO_BASE_SORT_H
