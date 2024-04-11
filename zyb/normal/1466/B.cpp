#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define P 1000000007
int tot,n,m,k,ans[N],fa[N],a[N],cnt[N];
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		scanf("%d",&n);
		for (int i=0;i<=3*n;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++; 
		int rt=0,ans=0;
		for (int i=1;i<=3*n;i++) {
			if (rt+cnt[i]>0) ans++;
			rt=max(0,(rt>0?cnt[i]:cnt[i]-1));
		}
		printf("%d\n",ans);
	}
}