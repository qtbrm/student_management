#pragma once
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
using namespace std;

struct student {
	char name[20];
	int age=0;
	char sex[5];
	char tel[20];
};

struct Node
{
	//int data;
	struct student data;
	struct Node* next;
};

struct Node* createList() {
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
struct Node* createNode(struct student data) {
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->data = data;
	headNode->next = NULL;
	return headNode;
}
void printList(struct Node* headNode) {
	struct Node* pMove = headNode->next;
	printf("姓名\t年龄\t性别\t电话\n");
	while (pMove) {
		printf("%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.age, pMove->data.sex, pMove->data.tel);
		pMove = pMove->next;
	}
	printf("\n");
}

void inserNodeByHead(struct Node* headNode, struct student data) {
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}

void modify_node(struct Node *headNode, struct student data) {
	//headNode->data.name = data.name;
	headNode->data.age = data.age;
	strcpy(headNode->data.sex, data.sex);
	strcpy(headNode->data.tel, data.tel);

}

void deleteNode(struct Node* headNode, char* name) {
	struct Node* posNode = headNode->next;
	struct Node* preNode = headNode;
	if (posNode == NULL) {
		printf("无法删除！数据为空\n");
		return;
	}
	while (strcmp(posNode->data.name,name)) {
		preNode = posNode;
		posNode = posNode->next;
		if (posNode == NULL) {
			printf("找不到数据！\n");
			return;
		}
	}
	preNode->next = posNode->next;
	free(posNode);
}

struct Node* find_node(struct Node* headNode,  char* name) {
	struct Node* postNode = headNode;
	if (postNode == NULL) {
		printf("没有找到该位置！\n");
		return NULL;
	}
	while (strcmp(postNode->data.name, name)) {
		postNode = postNode->next;
	}
	return postNode;
}
//读文件
void readInfoFromList(struct Node* headNode, const char *filename) {
	//1.打开文件
	FILE *fp;
	struct student data;
	fp = fopen(filename, "r");//不会创建文件的
	if (fp == NULL) {
		fp = fopen(filename, "w+");//可创建文件
	}

	//2.读文件
	while (fscanf(fp, " % s\t % d\t % s\t % s\n", data.name, data.age, data.sex, data.tel) != EOF) {
		inserNodeByHead(headNode, data);
	}

	//3.关闭文件
	fclose(fp);
}


//文件写操作
void writeInfoFromList(struct Node* headNode, const char *filename) {
	FILE* fp;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("文件打开失败！\n");
		return;
	}
	struct Node* pMove = headNode->next;
	while (pMove) {
		fprintf_s(fp, " % s\t % d\t % s\t % s\n", pMove->data.name, pMove->data.age, pMove->data.sex, pMove->data.tel);
		pMove = pMove->next;
	}
	printf("\N");
	fclose(fp);
}