#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
	long long n, k, n1, n2;
	cin >> n >> k;
	n1=n/2+(n&1); n2=n/2;
	if (k>n1) {
		k-=n1;
		cout << 2ll*k << endl;
	}
	else cout << 2ll*k-1 << endl;
	return 0;
}