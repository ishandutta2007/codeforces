#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;
int n;
int a,two=0,one=0;
int main() {
	cin >> n;
	for (size_t i = 0; i < n; i++){
		cin >> a;
		if (a == 1)
			one++;
		else
			two++;
	}
	if (two >= one) {
		cout << one;
	}
	else
		cout << two + (one - two) / 3;
	return 0;
}