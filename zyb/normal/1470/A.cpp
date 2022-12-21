#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define N 3000005
int i,j,k,l,s,n,m,test;
#define pb push_back
multiset<int,greater<int>>C;
int a[N],b[N],A[N];
int main() {
	scanf("%d",&test);
	while (test--) {
		long long ans=0;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++) A[i]=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),A[a[i]]++;
		for (int i=1;i<=m;i++) scanf("%d",&b[i]);
		C.clear();
		for (int i=m;i;i--) {
			for (int j=1;j<=A[i];j++) ans+=b[i],C.insert(b[i]);
			if (C.size()>=1) {
				ans-=(*C.begin());
				ans+=b[i];
				C.erase(C.begin());
				C.insert(b[i]);
			}
		}
		printf("%lld\n",ans);
	}
}