#include<bits/stdc++.h>
#define N 300005
#define M 10000005
using namespace std;
int i,j,k,l,d,n,m,a[N],x,A[50],rs[M],ls[M],root,tot,ans,si[M];
inline void add(int x) {
	int gt=root;
	for (int i=29;i>=0;i--) {
		if (x>=A[i]) {
			if (!rs[gt]) rs[gt]=++tot;
			gt=rs[gt]; si[gt]++;
			x-=A[i];
		}
		else {
			if (!ls[gt]) ls[gt]=++tot;
			gt=ls[gt]; si[gt]++;
		}
	}
}
inline void ask(int x) {
	int gt=root;
	int ans=0;
	for (int i=29;i>=0;i--) {
		if (x<A[i]) {
			if (si[ls[gt]]) gt=ls[gt],si[gt]--;
			else gt=rs[gt],si[gt]--,ans+=A[i];
		}
		else {
			if (si[rs[gt]]) gt=rs[gt],si[gt]--;
			else gt=ls[gt],si[gt]--,ans+=A[i];
			x-=A[i];
		}
	}
	printf("%d ",ans);
}
int main() {
	scanf("%d",&n);
	for (i=0;i<30;i++) A[i]=1<<i;
	root=tot=1;
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++) scanf("%d",&x),add(x);
	for (i=1;i<=n;i++) ask(a[i]);
}