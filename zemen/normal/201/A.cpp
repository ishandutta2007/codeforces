#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int x;
	cin >> x;
	if (x == 3) {
		cout << 5;
		return 0;
	}
	for (int i = 1; ; i += 2)
		if ((i * i) / 2 + 1 >= x) {
			cout << i;
			return 0;
		}
}