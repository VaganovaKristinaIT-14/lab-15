//ListWork61. Дан текстовый файл, в первой строке которого хранится число N, а во второй
//строке N целых чисел.Необходимо создать упорядоченный по возрастанию список, в который
//поместить все эти элементы, при этом очередной элемент вставлять в список так, чтобы не
//нарушалась его упорядоченность.
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
using namespace std;

struct Node{
	int x;
	Node* next;
};
void insert(Node*& head, int data) {
	Node* newnode = new Node{ data,nullptr };
	if (head == nullptr || head->x>=data) {
		newnode->next = head;
		head = newnode;
		return;
	}
	Node* temp = head;
	while (temp->next!= nullptr && temp->next->x < data) {
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;
}
void show(Node* head) {
	Node* mynode = head;
	while (mynode != nullptr) {
		cout << mynode->x << " ";
		mynode = mynode->next;
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	string p = "C:\\Users\\kseNari\\Desktop\\лаб15\\lwork61\\lw.txt";
	int n;
	ifstream file(p);
	file >> n;
	Node* head = nullptr;
	cout << "Числа из файла: " << endl;
	for (int i = 0; i < n; i++) {
		int num;
		file >> num;
		cout << num << " ";
		insert(head, num);
	}
	cout << endl;
	cout << "упорядоченный список:" << endl;
	show(head);
	return 0;
}
