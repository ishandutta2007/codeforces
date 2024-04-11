#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll d[23333],mx=20000;
ll cal(int x){
	int l=0,r=mx,mid;
	for (;l+3<r;x>=mid*(mid+1)/2? l=mid: r=mid) mid=l+r>>1;
	for (;;++l) if (l*(l+1)/2<=x&&x<(l+1)*(l+2)/2) return x*(l+1ll)-d[l];
}

int n,m,p,x,y,z;
struct R{
	int to; ll val;
};
#define N 1001000
vector<R>G[N],dag[N];
int bel[N],tot,dfn[N],dft,low[N],st[N],tp;
ll v[N],f[N];

void dfs(int x){
	dfn[x]=low[x]=++dft;
	st[++tp]=x;
	for (auto y:G[x]){
		if (!dfn[y.to]){
			dfs(y.to);
			low[x]=min(low[x],low[y.to]);
		}else if (!bel[y.to]){
			low[x]=min(low[x],dfn[y.to]);
		}
	}
	if (dfn[x]==low[x]){
		bel[x]=++tot;
		for (;st[tp]!=x;) bel[st[tp--]]=tot;
		--tp;
	}
}

ll que(int x){
	if (~f[x]) return f[x]; ll res=0;
	for (auto y:dag[x]) res=max(res,y.val+que(y.to));
	return f[x]=res+v[x];
}

int main(){
	for (int i=1;i<=mx;i++) d[i]=d[i-1]+i*(i+1)/2;
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		G[x].push_back((R){y,z});
	}
	cin>>p; dfs(p);
	for (int i=1;i<=n;i++){
		for (auto o:G[i]){
			x=bel[i], y=bel[o.to];
			if (x==y) v[x]+=cal(o.val);
			else dag[x].push_back((R){y,o.val});
		}
	}
	memset(f,-1,sizeof f);
	cout<<que(bel[p]);
}