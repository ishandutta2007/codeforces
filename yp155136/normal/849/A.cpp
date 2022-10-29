#include <iostream>
#include <cstdio>
using namespace std;

int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0;n>i;i++) {
		cin >> a[i];
	}
	if (n%2 == 0 || a[0]%2==0 || a[n-1]%2==0) puts("No");
	else puts("Yes");
}