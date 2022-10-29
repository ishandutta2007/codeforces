#include <iostream>
#include <stdio.h>
using namespace std;

const int INF = 1e9 + 7;

int f(int mn,int mx) {
	if (mx==mn) {
		if (mn==1) return 0;
		else return INF;
	}
	else if (mn == 1) {
		return mx-1;
	}
	else {
		return f(min(mn,mx-mn),max(mn,mx-mn))+1;
	}
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		if (n==1) {
			puts("0");
			continue;
		}
		int mn=INF;
		for (int i=n-1;i>=1;i--) {
			mn = min(mn,f(i,n));
		}
		printf("%d\n",mn);
	}
}