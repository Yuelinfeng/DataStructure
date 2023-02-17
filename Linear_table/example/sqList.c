#include <stdlib.h>
#include <stdio.h>
#include "sqList.h"

SqList *createSqList(int n) {
	SqList *seq = (SqList *)malloc(sizeof(SqList));
	if (seq == NULL) {
		printf("malloc error!\n");
		return NULL;
	}
	// 初始化顺序表里的每个元素
	seq->elem = (Element *)malloc(sizeof(Element) * n);
	for (int i = 0; i < n; ++i) {
		seq->elem[i] = 0;
	}
	seq->len = 0;
	seq->capacity = n;
	return seq;
}

void releaseSqList(SqList *seq) {
	if (seq) {
		if (seq->elem) {
			free(seq->elem);
		}
		free(seq);
	}
}

/* [1 2 ... seq->len]  pos的用户访问范围
 * */
int getSqList(SqList *seq, int pos, Element *ele) {
	if (pos < 1 || pos > seq->len) {
		printf("pos invalid!\n");
		return -1;
	}
	*ele = seq->elem[pos - 1];
	return 0;
}

int locateSqList(SqList *seq, Element ele) {
	for (int i = 0; i < seq->len; ++i) {
		if (seq->elem[i] == ele) {
			return i + 1;
		}
	}
	return 0;
}

/* 插入操作：
 * 外部范围：[1 2 ... seq->len]，插入行为，范围最后 seq->len+1
 * */
int insertSqList(SqList *seq, int pos, Element ele) {
	if (pos < 1 || pos > seq->len + 1) {
		printf("pos invalid!\n");
		return -1;
	}
	// 是否容量满足
	if (seq->len + 1 > seq->capacity) {		// 容量越界，就扩容
		printf("enlarger!\n");
		Element *tmp = (Element *) malloc(sizeof(Element) * seq->capacity * 2);
		if (tmp == NULL) {
			printf("malloc error!\n");
			return -1;
		}
		// 把老空间的值拷贝给新空间
		for (int i = 0; i < seq->len; ++i) {
			tmp[i] = seq->elem[i];
		}
		seq->capacity = seq->capacity * 2;
		free(seq->elem);
		seq->elem = tmp;
	}
	// 将pos位置后面的元素往后移，从seq->len逐步靠近pos的位置
	for (int i = seq->len - 1; i >= pos - 1; --i) {
		seq->elem[i + 1] = seq->elem[i];
	}
	seq->elem[pos - 1] = ele;
	seq->len++;
	return 0;
}

void showSqList(SqList *seq) {
	for (int i = 0; i < seq->len; ++i) {
		printf("%d\t", seq->elem[i]);
	}
	printf("\n");
}

int deleteSqList(SqList *seq, int pos) {
	if (pos < 1 || pos > seq->len) {
		printf("pos invalid!\n");
		return -1;
	}
	// 从pos+1开始到最后的位置处，往前赋值
	for (int i = pos; i < seq->len; ++i) {
		seq->elem[i - 1] = seq->elem[i];
	}
	seq->len--;
	return 0;
}
