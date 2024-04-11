#include<stdio.h>
#define inf 10000000000000ll
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#define lowbit(o) o&(-o)
#define pb push_back
#define N 100005
using namespace std;
long long i,j,k,l,s,n,m,n1,n2;
long long A[N],B[N],ans,Ans,d,x,y,v,vis[N],T[N];
struct node {
	long long id,x,d,v;
}a[N],b[N];
vector<long long>G[N];
inline bool cmp(const node x,const node y) {
	return x.d<y.d;
}inline bool cmp1(const node x,const node y) {
	return x.v>y.v;
}
int main() {
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for (i=1;i<=n;i++) A[i]=B[i]=inf,ans+=inf;
	for (i=1;i<=m;i++) {
		scanf("%I64d%I64d%I64d%I64d",&d,&x,&y,&v);
		if (x) a[++n1].x=x,a[n1].d=d,a[n1].v=v;
		else b[++n2].x=y,b[n2].d=d,b[n2].v=v;
	}
	sort(a+1,a+1+n1,cmp);
	sort(b+1,b+1+n2,cmp1);
	T[0]=inf;
	for (i=1;i<=n;i++) G[i].pb(0);
	for (i=1;i<=n2;i++) G[b[i].x].pb(i),T[i]=b[i].v,b[i].id=i;
	for (i=1;i<=n;i++) B[i]=T[G[i][G[i].size()-1]],ans+=B[i];
	sort(b+1,b+1+n2,cmp);
	i=1,j=1; Ans=inf;
	while (i<=n1) {
		ans-=A[a[i].x];
		A[a[i].x]=min(A[a[i].x],a[i].v);
		ans+=A[a[i].x];
		while (j<=n2&&b[j].d<=a[i].d+k) {
			vis[b[j].id]=1;
			while ((vis[G[b[j].x][G[b[j].x].size()-1]])) G[b[j].x].pop_back();
			ans-=B[b[j].x],B[b[j].x]=T[G[b[j].x][G[b[j].x].size()-1]],ans+=B[b[j].x];
			j++;
		}
		Ans=min(Ans,ans);
		i++;
	}
	if (Ans>=inf) Ans=-1;
	printf("%I64d\n",Ans);
	
}