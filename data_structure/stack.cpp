#include <iostream>
#include <algorithm>
using namespace std;

class Stack {
private:
	int _top = -1;
	int* arr;
	int cap = 5;

public:
	Stack() {
		arr = new int[cap];
	}

	int top() {
		if (_top >= 0) return arr[_top];
		else return _top;
	}

	int pop() {
		return arr[_top--];
	}

	void push(int item) {
		_top++;
		if (_top >= cap) {
			int* new_arr = new int[cap *2];
			copy(arr, arr + cap, new_arr);
			delete[] arr;
			arr = new_arr;
			cap *= 2;
		}
		arr[_top] = item;
	}

	bool empty() {
		return _top == -1;
	}

	int size() {
		return _top + 1;
	}
};

int main() {

	Stack s;
	cout << s.empty() << endl;

	s.push(1);
	s.push(2);
	s.push(3);

	s.pop();

	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);

	cout << s.size() << endl;
	cout << s.empty() << endl;
	cout << s.top() << endl;

	return 0;
}