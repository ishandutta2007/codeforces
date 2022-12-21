#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define P 1000000007
int tot,n,m,k,ans[N],fa[N],a[N],deg[N],w[N],x,y,i,j;
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		long long cnt=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%d",&w[i]),deg[i]=0,cnt+=w[i];
		for (i=1;i<n;i++) {
			scanf("%d%d",&x,&y);
			deg[x]++,deg[y]++; 
		}
		a[0]=0;
		for (i=1;i<=n;i++)
		for (j=1;j<deg[i];j++) a[++a[0]]=w[i]; 
		sort(a+1,a+a[0]+1);
		printf("%lld",cnt);
		for (i=1;i<n-1;i++) {
			cnt+=a[a[0]-i+1];
			printf(" %lld",cnt);
		}
		puts("");
	}
}