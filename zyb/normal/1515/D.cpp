#include<bits/stdc++.h>
using namespace std;
#define N 200005
int b[N],c[N],l,r;
int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		int n;
		scanf("%d%d%d",&n,&l,&r);
		for (int i=1;i<=n;i++) b[i]=c[i]=0;
		for (int i=1;i<=n;i++) {
			int x;
			scanf("%d",&x);
			if (i<=l) b[x]++;
			else c[x]++;
		}
		int s1=0;
		int s2=0;
		int ans=0;
		if (r>l) {
			for (int i=1;i<=n;i++) swap(b[i],c[i]);
			swap(l,r);
		}
		int s=(l-r)/2;
		for (int i=1;i<=n;i++) {
			if (b[i]>c[i]) {
				int k=min(s,(b[i]-c[i])/2);
				ans+=k;
				s-=k;
				b[i]-=k;
				c[i]+=k;
			}
		}
		for (int i=1;i<=n;i++) if (b[i]>c[i]) ans+=b[i]-c[i];
		printf("%d\n",ans);
		
	}
}