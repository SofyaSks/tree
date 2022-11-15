// бинарное дерево
#include <iostream>
#include <time.h>
using namespace std;

 // если элемент больше или равен родителю, укладываем вправо / меньше  влево

int tabs = 0;

struct Branch {
	int data;
	Branch* LB;
	Branch* RB;
};

void Add_(int _data, Branch*& _Branch) { // адрес на наш Branch

	if (!_Branch) {
		_Branch = new Branch;
		_Branch->data = _data;
		_Branch->LB = 0;
		_Branch->RB = 0;
		return;
	}
	if (_Branch->data > _data) {
		Add_(_data, _Branch->LB);
	}
	else {
		Add_(_data, _Branch->RB);
	}
} 

void Print(Branch*& _Branch) {
	if (!_Branch) return;
	tabs++;
	Print(_Branch->LB); 
	for (int i = 0; i < tabs; i++) cout << " ";
	
	cout << _Branch->data << endl;
	
	Print(_Branch->RB);
	tabs--;
	return;
}

void FreeTree(Branch*& _Branch) {
	if (!_Branch) return;
	FreeTree(_Branch->LB);
	FreeTree(_Branch->RB);
	delete _Branch;
	return;
}

int main() {
	srand(time(NULL));

	Branch* Root = 0;
	int arr[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "********************" << endl;
	for (int i = 0; i < 10; i++) {
		Add_(arr[i], Root);
	}
	Print(Root);
	FreeTree(Root);

	return 0;
}