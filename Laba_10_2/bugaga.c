# define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
    struct node* next;
};

struct node* first = NULL;

void printList() {
	struct node* ptr = first;
	while (ptr != NULL) {
		printf("(%d)", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n\n");
}

void addToHead(int value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}

int deleteToHead() {
	int value = first->data;
	struct Node* delNode = first;
	first = first->next;
	free(delNode);
	return value;
}

int contains(int value) {
	struct node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

int clearList() {
	while (first != NULL) {
		struct node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int sum() {
	struct node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		s += ptr->data;
		ptr = ptr->next;
	}
	return s;
}

int chet() {
	struct node* ptr = first;
	int cnt = 0;
	while (ptr != NULL) {
		if (ptr->data % 2 == 0) cnt++;
		ptr = ptr->next;
	}
	return cnt;
}

void oddsX10() {
	struct node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data % 2 != 0) ptr->data = ptr->data * 10;
		ptr = ptr->next;
	}
}

void ElemX100(int ind) {
	struct node* ptr = first;
	for (int i = 0; i <= ind, ptr != NULL; i++) {
		if (i == ind) {
			ptr->data = ptr->data * 100;
		}
		ptr = ptr->next;
	}
}

void elemLeftX10(int ind) {
	struct node* ptr = first;
	for (int i = 0; i <= ind, ptr != NULL; i++) {
		ptr->data = ptr->data * 10;
		if (i == ind - 1) {
			return;
		}
		ptr = ptr->next;
	}
}

int main() {
	addToHead(10);
	printList();

	addToHead(20);
	printList();

	addToHead(30);
	printList();

	addToHead(40);
	printList();

	addToHead(7);
	printList();

	printf("!!!ElemX100!!!\n");
	ElemX100(3);
	printList();

	printf("!!!elemLeftX10!!!\n");
	elemLeftX10(3);
	printList();

	addToHead(7);
	printList();

	int x1 = contains(5);
	printf("5 in node:%d ", x1);
	x1 = contains(10);
	printf("10 in node:%d\n\n", x1);

	printf("!!!oddsX10!!!\n");
	oddsX10();


	deleteToHead();
	printList();

	printf("sum = %d\n", sum());
	printf("even numbers = %d\n", chet());

	clearList();
	printList();

	printf("even numbers = %d\n", chet());
	printf("sum = %d\n", sum());

	printf("test git text");

	return 0;
}
