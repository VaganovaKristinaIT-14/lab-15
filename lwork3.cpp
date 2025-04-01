//ListWork3. Дан односвязный линейный список и указатель на голову списка P1. Необходимо
//вывести указатель на четвертый элемент этого списка P4.Известно, что в исходном списке не
//менее 5 элементов.
#include <iostream>
using namespace std;

struct Node{
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
int main() {
	Node* head = nullptr;
	Node* last = nullptr;
	setlocale(LC_ALL, "RU");
	cout << "Введите количество элементов списка(не меньше 5)" << endl;
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Введите элемент:" << endl;
		cin >> k;
		add(k, head, last);
	}
	cout << "Наш список:" << endl;
	show(head);
	cout << endl;
	Node* temp = head;
	int cnt = 1;
	while (cnt<4 && temp!=nullptr) {
		temp= temp->next;
		cnt++;
	}
	cout << "4 Элемент: " << temp->x << endl;
	cout << "Указатель на 4 Элемент: " << temp;
	return 0;
}