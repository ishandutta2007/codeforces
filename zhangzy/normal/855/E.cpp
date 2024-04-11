#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll l,r,f[11][66][2055];
int T,n,w[66],g;

ll dfs(int p,int lim,int now,int fir){
	if (p<=0) return now==0?1:0;
	if (!lim&&!fir&&f[n][p][now]!=-1) return f[n][p][now];
	ll res=0;
	for (int i=fir;i<n;i++){
		if (lim&&i>w[p]) break;
		res+=dfs(p-1,lim&&(i==w[p]),now^(1<<i),0);
	}
	return (!lim&&!fir)?f[n][p][now]=res:res;
}

ll doit(ll x){
	for (g=0;x;x/=n) w[++g]=x%n;
	ll ans=0;
	for (int i=1;i<=g;i++) ans+=dfs(i,i==g,0,1);
	return ans;
}

int main(){
	memset(f,-1,sizeof f);
	for (scanf("%d",&T);T--;){
		scanf("%d%I64d%I64d",&n,&l,&r);
		printf("%I64d\n",doit(r)-doit(l-1));
	}
}