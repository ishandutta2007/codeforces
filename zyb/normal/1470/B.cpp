#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define N 1000005
int i,j,k,l,s,n,m,test;
#define pb push_back
multiset<int,greater<int>>C;
int vis[N],a[N],b[N],A[N],B[N],T[N];
inline void doit() {
	for (int i=1;i<=1000000;i++) A[i]=1;
	for (int i=2;i<=1000000;i++) {
		if (!vis[i]) {
			for (int j=i;j<=1000000;j+=i) {
				vis[j]=1;
				if (T[j]!=i) T[j]=i,B[j]=0;
				if (!B[j]) A[j]*=i;
				if (1ll*j*i<=1000000ll) T[j*i]=i,B[j*i]=B[j]^1;
			}
		}
	}
}
int main() {
	scanf("%d",&test);
	doit();
	while (test--) {
		int ans1=0,ans2=0,ans3=0,ans4=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d",&b[i]);
			a[A[b[i]]]++;
			ans1=max(ans1,a[A[b[i]]]);
		}
		ans2=a[1];
		for (int i=1;i<=n;i++) {
			if (A[b[i]]==1) continue;
			if (a[A[b[i]]]>=2) {
				if (a[A[b[i]]]&1) ans3=max(ans3,a[A[b[i]]]);
				else ans2+=a[A[b[i]]];
			}
			a[A[b[i]]]=0;
		}
		a[1]=0;
		scanf("%d",&m);
		for (int i=1;i<=m;i++) {
			long long x;
			scanf("%lld",&x);
			if (x==0) printf("%d\n",ans1);
			else printf("%d\n",max(max(ans1,ans2),ans3));
		}
	}
}