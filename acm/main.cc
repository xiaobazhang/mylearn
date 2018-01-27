/**
 * Created by suli on 18/1/16.
 */

#include "binary.h"
#include "threadpool.h"
#include "str.h"
#include <unistd.h>

int main(void) {
	/*List<int> tmp;
	for(int i=0;i<10;i++){
		tmp.push_back(i+1);
	}

	for(int i=0;i<tmp.size();i++){
		std::cout<<"i="<<tmp[i]<<std::endl;
	}

	ThreadPool tp(2);

	Task t1;
	Task t2;
	Task t3;
	tp.AddTask(&t1);
	tp.AddTask(&t2);
	tp.AddTask(&t3);
	tp.Run();
	sleep(4);*/   //等待调度器结束，不然会崩溃

	char s[10] = {'1', '2', '3', '4', '5'};
	str mstr;
	printf("s=%s\n", s);
	mstr.invertstr(s);
	printf("invert=%s\n", s);
	return 1;
}