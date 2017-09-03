/**
 * Created by suli on 8/31/17.
 */

#include <setjmp.h>
#include <stdio.h>

jmp_buf g_jum_buf;//全局buff,用于记录当时上下文

void test() {
	printf("Enter test ...\n");
	longjmp(g_jum_buf, 8);//如下代码不会被执行
	printf("test::can't see");
}

int main() {
	int ret;
	if (ret = setjmp(g_jum_buf)) {
		printf("Main: return after calling longjmp, ret = %d.\n", ret);
	}
	else {
		printf("Main: first time return from setjmp, ret = %d\n", ret);
		test();
	}
	return 0;
}
