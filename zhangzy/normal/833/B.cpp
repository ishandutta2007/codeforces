#include<bits/stdc++.h>
using namespace std;
int dp[55][35555],n,m,a[35555],las[35555],pre[35555],now;

struct LT{
	int mx,lazy;
}tr[517171];

void U(int x){
	tr[x].mx=max(tr[x<<1].mx,tr[x<<1|1].mx);
}

void D(int x){
	tr[x<<1].lazy+=tr[x].lazy;
	tr[x<<1].mx+=tr[x].lazy;
	tr[x<<1|1].lazy+=tr[x].lazy;
	tr[x<<1|1].mx+=tr[x].lazy;
	tr[x].lazy=0;
	U(x);
}

void rebuild(int x,int l,int r){
	tr[x].lazy=0;
	if (l==r){
		tr[x].mx=dp[now][l-1];
		return;
	}
	int mid=(l+r)>>1;
	rebuild(x<<1,l,mid);rebuild(x<<1|1,mid+1,r);
	U(x);
}

void C(int x,int l,int r,int st,int en){
	if (l==st&&r==en){
		tr[x].mx++;
		tr[x].lazy++;
		return;
	}
	D(x);
	int mid=(l+r)>>1;
	if (st<=mid) C(x<<1,l,mid,st,min(en,mid));
	if (en>mid) C(x<<1|1,mid+1,r,max(st,mid+1),en);
	U(x);
}

int Q(int x,int l,int r,int st,int en){
	if (l==st&&r==en){
		return tr[x].mx;
	}
	D(x);
	int t=0,mid=(l+r)>>1;
	if (st<=mid) t=max(t,Q(x<<1,l,mid,st,min(en,mid)));
	if (en>mid) t=max(t,Q(x<<1|1,mid+1,r,max(st,mid+1),en));
	return t;
}

int main(){
	scanf("%d%d",&n,&m);
	memset(las,0,sizeof(las));
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=las[a[i]];
		las[a[i]]=i;
	}
	memset(dp,0,sizeof(dp));
	
	for (int i=1;i<=m;i++){
		now=i-1;
		rebuild(1,1,n);
		for (int j=1;j<=n;j++){
			C(1,1,n,pre[j]+1,j);
			dp[i][j]=Q(1,1,n,1,j);
		}
	}
	printf("%d",dp[m][n]);
}