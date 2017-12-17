/**
 * Created by suli on 17/12/11.
 */

#include "rc4.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

RC4::RC4() {
	m_index_i = 0;
	m_index_j = 0;
}

// 初始化算法
void RC4::rc4_init(unsigned char *key, unsigned long Len) {
	if (key == NULL || Len == 0) {
		printf("rc4 key or len is 0, return! ");
		return;
	}

	// for循环将0到255的互不重复的元素装入S盒
	for (int i = 0; i < 256; i++) {
		m_box[i] = i;
	}

	// for循环根据密钥打乱S盒
	int j = 0;
	unsigned char tmp;
	for (int i = 0; i < 256; i++) {
		j = (j + m_box[i] + key[i % Len]) % 256;

		tmp = m_box[i];
		m_box[i] = m_box[j]; //交换m_box[i]和m_box[j]
		m_box[j] = tmp;
	}
}

void RC4::do_crypt(unsigned char *Data, unsigned long Len) {
	// 每收到一个字节，就进行while循环。通过一定的算法（(a),(b)）定位S盒中的一个元素，并与输入字节异或，得到k。循环中还改变了S盒（(c)）。如果输入的是明文，输出的就是密文；如果输入的是密文，输出的就是明文。
	unsigned char tmp;
	for (unsigned long k = 0; k < Len; k++) {
		m_index_i = (m_index_i + 1) % 256;    // a
		m_index_j = (m_index_j + m_box[m_index_i]) % 256; // b

		tmp = m_box[m_index_i];
		m_box[m_index_i] = m_box[m_index_j]; //交换m_box[x]和m_box[y]
		m_box[m_index_j] = tmp;

		// 生成伪随机数
		int r = (m_box[m_index_i] + m_box[m_index_j]) % 256;
		Data[k] ^= m_box[r];
	}

}

void getdir(const string &path, vector<string> &files) {
	struct dirent *ptr;
	DIR *dir;
	dir = opendir(path.c_str());
	while ((ptr = readdir(dir)) != NULL) {
		if (ptr->d_name[0] == '.')
			continue;
		files.push_back(path + ptr->d_name);
	}
	closedir(dir);
}

void getfile(const string &path, vector<string> &files) {
	DIR *pDir;
	struct dirent *ent;
	int i = 0;
	char childpath[512];
	pDir = opendir(path.c_str());
	memset(childpath, 0, sizeof(childpath));
	while ((ent = readdir(pDir)) != NULL) {
		if (ent->d_type & DT_DIR) {
			if (ent->d_name[0] == '.' || ent->d_name[0] == '..')
				continue;
			//sprintf(childpath,"%s/%s",path,ent->d_name);
			//printf("path:%s/n",childpath);
			getfile(path.c_str(), files);
		}
		else {
			files.push_back(path + ent->d_name);
		}
	}
}

int getAbsoluteFiles(string directory, vector<string> &filesAbsolutePath) //参数1[in]要变量的目录  参数2[out]存储文件名
{
	DIR *dir = opendir(directory.c_str()); //打开目录   DIR-->类似目录句柄的东西
	if (dir == NULL) {
		cout << directory << " is not a directory or not exist!" << endl;
		return -1;
	}

	struct dirent *d_ent = NULL;       //dirent-->会存储文件的各种属性
	char fullpath[128] = {0};
	char dot[3] = ".";                //linux每个下面都有一个 .  和 ..  要把这两个都去掉
	char dotdot[6] = "..";

	while ((d_ent = readdir(dir)) != NULL)    //一行一行的读目录下的东西,这个东西的属性放到dirent的变量中
	{
		if ((strcmp(d_ent->d_name, dot) != 0)
			&& (strcmp(d_ent->d_name, dotdot) != 0))   //忽略 . 和 ..
		{
			if (d_ent->d_type == DT_DIR) //d_type可以看到当前的东西的类型,DT_DIR代表当前都到的是目录,在usr/include/dirent.h中定义的
			{

				string newDirectory = directory + string("/") + string(d_ent->d_name); //d_name中存储了子目录的名字
				if (directory[directory.length() - 1] == '/') {
					newDirectory = directory + string(d_ent->d_name);
				}

				if (-1 == getAbsoluteFiles(newDirectory, filesAbsolutePath))  //递归子目录
				{
					return -1;
				}
			}
			else   //如果不是目录
			{
				string absolutePath = directory + string("/") + string(d_ent->d_name);  //构建绝对路径
				if (directory[directory.length() - 1] == '/')  //如果传入的目录最后是/--> 例如a/b/  那么后面直接链接文件名
				{
					absolutePath = directory + string(d_ent->d_name); // /a/b/1.txt
				}
				filesAbsolutePath.push_back(absolutePath);
			}
		}
	}

	closedir(dir);
	return 0;
}
/**
 *
 * @param1 加密包路径
 * @param2 目的包路径
 * @param3 秘钥
 * @return
 */
int main(int argc, char *argv[]) {
	//char* key = "AAAAB3NzaC1yc2EAAAABIwAAAQEArk8etQ7S/Uj2QOrzhw54df6LQttJLvRR5qsLLrVxOE5mBG2tl6Q+A4Pj044VinCSRCCwTmUJZRHBOpfN3S1Iuj8teYwANMzffjkE";
	if (argc == 1 || argc > 4) {
		printf("param size error!!\nparam1 加密包路径\nparam2 目的包路径\nparam3 秘钥\n");
		return 1;
	}
	string src = argv[1];
	string des = argv[2];
	string secrte = argv[3];
	std::ifstream t;
	unsigned long length = 0;
	t.open(src);
	if (!t.is_open()) {
		printf("open src file error!!\n");
		return 1;
	}
	ofstream outf;
	outf.open(des, ios::binary);
	if (!outf.is_open()) {
		printf("open des file error!!\n");
		return 1;
	}
	t.seekg(0, std::ios::end);
	length = (unsigned long) t.tellg();
	t.seekg(0, std::ios::beg);
	char *buffer = new char[length];
	t.read(buffer, length);
	t.close();
	RC4 rc4;
	rc4.rc4_init((unsigned char *) secrte.c_str(), secrte.length());
	rc4.do_crypt((unsigned char *) buffer, length);
	outf.write(buffer, length);
	delete[] buffer;
	outf.close();
	return 1;
}