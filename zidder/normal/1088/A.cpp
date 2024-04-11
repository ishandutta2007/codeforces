#include <iostream>
#include <vector>
#include <string>

using namespace std;

void A() {
	int x;
	cin >> x;
	int a, b;
	if (x == 1) {
		cout << -1;
	}
	else {
		cout << x << " " << x;
	}
}
void B() {

}
void C() {

}
void D() {

}
void E() {

}
int main() {
	char problem = 'A';
	switch (problem)
	{
	case 'A':
		A();
		break;
	case 'B':
		B();
		break;
	case 'C':
		C();
		break;
	case 'D':
		D();
		break;
	case 'E':
		E();
		break;
	}
	return 0;
}