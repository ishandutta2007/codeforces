#include<bits/stdc++.h>
#define N 100005
using namespace std;
char c[N];
#define pb push_back
#define lowbit(x) x&-x
struct pa {
	int l,r;
}q[N];
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		int n;
		scanf("%d",&n);
		scanf("%s",c);
		sort(c,c+n);
		printf("%s\n",c);
	}
}