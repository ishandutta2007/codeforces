#include<bits/stdc++.h>
using namespace std;
long long n;
int main() { 
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%lld",&n);
		if (n<=14) {
			puts("NO");
			continue;
		}
		n=n%14;
		while (n<=14) 
		n+=14;
		if (n>=15&&n<=20) puts("YES");
		else puts("NO");
	}
}