﻿//Дан указатель P1 на вершину непустого стека. Извлечь из стека первый (верхний)
//элемент и вывести его значение D, а также адрес P2 новой вершины стека.Если после
//извлечения элемента стек окажется пустым, то положить P2 = nullptr.После извлечения
//элемента из стека освободить память, занимаемую этим элементом.

#include <iostream>
using namespace std;

class stack {
private:
	struct Node {
		int d;
		Node* next;
		Node(int val) :d(val), next(nullptr) {}
	};
	Node* p1; //вершина
	int cnt;
public:
	stack() : p1(nullptr),cnt(0){}
	void add(int x) {
		Node* newnode = new Node(x);
		newnode->next = p1;
		p1 = newnode;
		cnt++;
	}
	void topdel() { //извлечение 1 элемента и его удаление
		Node* temp = p1;
		cout << "Первый элемент стека:" << endl;
		cout << p1->d << endl;
		if (p1->next == nullptr) {
			p1 = nullptr;
		}
		else {
			p1 = p1->next;
		}
		cout << "адрес новой вершины p2" << endl;
		cout << p1 << endl;
		cout << p1->d;
		delete temp;
		cnt--;
	}
	void show() {
		Node* temp = p1;
		while (temp != nullptr) {
			cout << temp->d << endl;
			temp = temp->next;
		}
	}

};
int main() {
	stack stack;
	setlocale(LC_ALL, "RU");
	cout << "Введите количество элементов стека" << endl;
	int n;
	cin >> n;//размер стека
	for (int i = 0; i < n; i++) {
		int num;
		cout << "Введите элемент стека" << endl;
		cin >> num;
		stack.add(num);
	}
	cout << "Стек:" << endl;
	stack.show();
	stack.topdel();
return 0;

}