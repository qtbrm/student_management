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
	printf("����\t����\t�Ա�\t�绰\n");
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
		printf("�޷�ɾ��������Ϊ��\n");
		return;
	}
	while (strcmp(posNode->data.name,name)) {
		preNode = posNode;
		posNode = posNode->next;
		if (posNode == NULL) {
			printf("�Ҳ������ݣ�\n");
			return;
		}
	}
	preNode->next = posNode->next;
	free(posNode);
}

struct Node* find_node(struct Node* headNode,  char* name) {
	struct Node* postNode = headNode;
	if (postNode == NULL) {
		printf("û���ҵ���λ�ã�\n");
		return NULL;
	}
	while (strcmp(postNode->data.name, name)) {
		postNode = postNode->next;
	}
	return postNode;
}
//���ļ�
void readInfoFromList(struct Node* headNode, const char *filename) {
	//1.���ļ�
	FILE *fp;
	struct student data;
	fp = fopen(filename, "r");//���ᴴ���ļ���
	if (fp == NULL) {
		fp = fopen(filename, "w+");//�ɴ����ļ�
	}

	//2.���ļ�
	while (fscanf(fp, " % s\t % d\t % s\t % s\n", data.name, data.age, data.sex, data.tel) != EOF) {
		inserNodeByHead(headNode, data);
	}

	//3.�ر��ļ�
	fclose(fp);
}


//�ļ�д����
void writeInfoFromList(struct Node* headNode, const char *filename) {
	FILE* fp;
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("�ļ���ʧ�ܣ�\n");
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