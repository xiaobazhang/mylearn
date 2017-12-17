/**
 * Created by suli on 17/12/11.
 */

#ifndef MYLEARN_RC4_H
#define MYLEARN_RC4_H
#include <iostream>
#include <stdio.h>

class RC4 {
 public:
	RC4();
	~RC4() {};
	void rc4_init(unsigned char *key, unsigned long Len);

	// 加/解 密
	void do_crypt(unsigned char *Data, unsigned long Len);

 private:

	int m_box[256]; // 对称加密中的置换盒 S盒
	int m_index_i;
	int m_index_j;
};

#endif //MYLEARN_RC4_H
