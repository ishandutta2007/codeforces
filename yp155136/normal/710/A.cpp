#include <iostream>
using namespace std;
int main () {
	string i;
	while (cin >> i) {
		if (i=="a1" || i=="a8" || i=="h1" || i=="h8") puts("3");
		else if (i[0]=='a' || i[0]=='h' || i[1]=='1' || i[1]=='8') puts("5");
		else puts("8");
	}
}