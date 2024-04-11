#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 + 6;

int a[MAX_N];

int main () {
	int n;
	while (cin >> a[0]>> a[1] >> a[2]) {
		sort(a,a+3);
		cout<<a[1]-a[0]+a[2]-a[1]<<endl;
	}
}