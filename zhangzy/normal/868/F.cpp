#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k,a[101000],now,cur=0;
ll f[22][101000],g[101000],inf,lp,rp,ans;
int cnt[101000];

ll Q(int s,int e){
	if (s>e) return inf;
	for (;rp<e;) ans+=cnt[a[++rp]]++;
	for (;lp>s;) ans+=cnt[a[--lp]]++;
	for (;rp>e;) ans-=--cnt[a[rp--]];
	for (;lp<s;) ans-=--cnt[a[lp++]];
	return ans;
}

void doit(int l,int r,int st,int en){
	if (l>r) return;
	int mid=(l+r)>>1,mnw=st;
	for (int i=st;i<=en;i++){
		g[i]=Q(i,mid)+f[cur][i-1];
		if (g[i]<g[mnw]) mnw=i;
	}
	f[now][mid]=g[mnw];
	doit(l,mid-1,st,mnw);
	doit(mid+1,r,mnw,en);
}

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;scanf("%d",&a[i++]));
	memset(f,33,sizeof f);
	inf=f[0][0]; f[0][0]=0;
	for (now=1;now<=k;cur=now++){
		lp=1; rp=0; ans=0; memset(cnt,0,sizeof cnt);
		doit(now,n,now,n);
	}
	cout<<f[k][n];
}