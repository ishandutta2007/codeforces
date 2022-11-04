#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

int n,m,l,ans[2][N*10];
ll t[N],x[N],y[N];
bool v[2];
struct node{
	ll t,x,s;
}a[N];
bool cmp(node a,node b){
	return a.t<b.t;
}
void GG(){
	puts("NO");
	exit(0);
}
void work(ll *t,ll *x,int *ans){
	v[0]=v[1]=1; m=0;
	for (int i=1;i<=n;i++)
		a[++m]=(node){t[i]%l,x[i],-t[i]/l};
	a[++m]=(node){0,0,0}; a[++m]=(node){l,0,1};
	sort(a+1,a+m+1,cmp);
	ll Q=1ll<<60,P=-Q;
	for (int i=1;i<m;i++){
		ll dt=a[i+1].t-a[i].t;
		ll dx=a[i+1].x-a[i].x;
		ll ds=a[i+1].s-a[i].s;
		ll Dn=-dt-dx,Up=dt-dx;
		if (ds&1) v[(Up&1)^1]=0;
		else if (Up&1) GG();
		if (!ds){
			if (Dn>Up) GG();
			continue;
		}
		if (ds<0){
			Up*=-1,Dn*=-1,ds*=-1;
			swap(Up,Dn);
		}
		if (Up>=0) Q=min(Q,Up/ds);
		else Q=min(Q,-(-Up-1)/ds-1);
		if (Dn>0) P=max(P,(Dn-1)/ds+1);
		else P=max(P,Dn/ds);
	}
	if (!v[0]&&!v[1]) GG();
	if (!v[P&1]) P++;
	if (P>Q) GG();
	for (int i=1;i<m;i++){
		ll t=(a[i+1].x+a[i+1].s*P)-(a[i].x+a[i].s*P);
		for (int j=a[i].t+1;j<=a[i+1].t;j++)
			ans[j]=(t>0?1:-1),t-=ans[j];
	}
}
int main(){
	scanf("%d%d",&n,&l);
	for (int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&t[i],&x[i],&y[i]);
		x[i]-=y[i]; y[i]+=x[i]+y[i];
	} 
	work(t,x,ans[0]);
	work(t,y,ans[1]);
	for (int i=1;i<=l;i++){
		if (ans[0][i]==-1&&ans[1][i]==-1) putchar('L');
		if (ans[0][i]==-1&&ans[1][i]==1) putchar('U');
		if (ans[0][i]==1&&ans[1][i]==-1) putchar('D');
		if (ans[0][i]==1&&ans[1][i]==1) putchar('R');
	}
}