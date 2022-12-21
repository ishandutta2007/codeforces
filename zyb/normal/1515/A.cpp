#include<bits/stdc++.h>
using namespace std;
#define N 100005
int a[N];
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		int n,m;
		scanf("%d%d",&n,&m);
		long long s=0;
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			s+=a[i];
		}
		if (s==m) {
			puts("NO");
			continue;
		}
		sort(a+1,a+1+n);
		s=0;
		for (int i=1;i<=n;i++) {
			s+=a[i];
			if (s==m) swap(a[i],a[n]);
		}
		puts("YES");
		for (int i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");
		
	}
}