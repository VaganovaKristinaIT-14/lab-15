//ListWork24. Дан односвязный линейный список и указатель на голову списка P1. Необходимо
//вставить значение M после каждого четвертого элемента списка, и вывести ссылку на последний
//элемент полученного списка P2.
#include <iostream>
using namespace std;

struct Node {
	int x;
	Node* next;
};
void add(int data, Node*& head, Node*& last) {
	Node* temp;
	if (head == nullptr) {
		head = new Node;
		last = head;
		head->next = nullptr;
	}
	else {
		temp = new Node;
		last->next = temp;
		last = temp;
		last->next = nullptr;
	}
	last->x = data;
}
void show(Node* head) {
	Node* mynode = head;
	while (mynode != nullptr) {
		cout << mynode->x << " ";
		mynode = mynode->next;
	}
}
void addafter(Node* p, int data) {
	Node* newnode;
	newnode = new Node;
	newnode->x = data;
	newnode->next = p->next;
	p->next = newnode;
}
int main() {
	Node* head = nullptr;
	Node* last = nullptr;
	Node* p2 = nullptr;
	setlocale(LC_ALL, "RU");
	cout << "Введите количество элементов списка(не меньше 5)" << endl;
	int n, k, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Введите элемент:" << endl;
		cin >> k;
		add(k, head, last);
	}
	cout << "Наш список:" << endl;
	show(head);
	cout << endl;
	cout << "Введите М " << endl;
	cin >> m;
	Node* temp = head;
	int cnt = 1;
	while (temp != nullptr) {
		if (cnt % 4 == 0) {
			addafter(temp, m);
			temp = temp->next;
		}
		temp = temp->next;
		cnt++;
	}
	p2 = head;
	while (p2->next!= nullptr) {
		p2 = p2->next;
	}
	cout << "Наш новый список:" << endl;
	show(head);
	cout << endl;
	cout << "Указатель р2 " << p2 << endl;
	cout <<"Элемент " << p2->x;

	return 0;
}