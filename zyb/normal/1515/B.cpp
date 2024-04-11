#include<bits/stdc++.h>
using namespace std;
#define N 200005
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		int n;
		scanf("%d",&n);
		if (!(n&1)) {
			int p=sqrt(n);
			if (p*p==n) {
				puts("YES");
				continue;
			}
			p=sqrt(n*2);
			if (p*p==n*2) {
				puts("YES");
				continue;
			}
		}
		puts("NO");
	}
}