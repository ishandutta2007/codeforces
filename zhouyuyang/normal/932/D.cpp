#include<bits/stdc++.h>
#define ll long long
#define N 400005
using namespace std;
int f[N][22],fa[N],dep[N];
ll g[N][22],V[N];
void add(int x,int y,ll v){
	fa[x]=y; dep[x]=dep[y]+1;
	V[x]=g[x][0]=v; f[x][0]=y;
	for (int i=1;i<=19;i++){
		f[x][i]=f[f[x][i-1]][i-1];
		g[x][i]=g[x][i-1]+g[f[x][i-1]][i-1];
	}
}
int find(int x,ll v){
	return !x||V[x]>=v?x:find(fa[x],v);
}
int main(){
	int q,cnt=1; ll la=0;
	scanf("%d",&q); dep[1]=1;
	while (q--){
		int fl; ll x,y;
		scanf("%d%lld%lld",&fl,&x,&y);
		x^=la; y^=la;
		if (fl==1)
			add(++cnt,find(x,y),y);
		else{
			ll ans=0;
			for (int i=19;i>=0;i--)
				if (x&&g[x][i]<=y){
					y-=g[x][i];
					ans+=min(1<<i,dep[x]);
					x=f[x][i];
				}
			printf("%lld\n",la=ans);
		}
	}
}