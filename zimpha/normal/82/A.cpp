#include <cstdio>
#include <cstdlib>
typedef long long LL;

int main() {
	int n; scanf("%d", &n);
	LL ret=0, p=0;
	for (; ; p++) {
		ret+=5ll*(1ll<<p);
		if (ret>=n) break;
	}
	ret-=5ll*(1ll<<p); n-=ret;
	int t=(n-1)/(1<<p);
	if (t==0) puts("Sheldon");
	else if (t==1) puts("Leonard");
	else if (t==2) puts("Penny");
	else if (t==3) puts("Rajesh");
	else if (t==4) puts("Howard");
	return 0;
}