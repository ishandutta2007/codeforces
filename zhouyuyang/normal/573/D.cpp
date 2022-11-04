#include<bits/stdc++.h>
#define ll long long
#define inf (1ll<<60)
#define N 30005
using namespace std;
int n,q,x,y;
int posh[N],posw[N],tag[N];
ll f[N],g[N][3];
struct data{int v,id;}w[N],h[N];
bool cmp(data x,data y){
	return x.v>y.v;
}
void mx(ll &x,ll y){
	x=x<y?y:x;
}
void solve(int i){
	if (i<=0) return;
	g[i][0]=g[i][1]=g[i][2]=-inf;
	if (tag[i]!=i) g[i][0]=1ll*h[i].v*w[i].v;
	if (tag[i]!=i+1&&tag[i+1]!=i)
		g[i][1]=1ll*h[i].v*w[i+1].v+1ll*h[i+1].v*w[i].v;
	if (tag[i]!=i+1&&tag[i+1]!=i+2&&tag[i+2]!=i)
		g[i][2]=1ll*h[i].v*w[i+1].v+1ll*h[i+1].v*w[i+2].v+1ll*h[i+2].v*w[i].v;
	if (tag[i]!=i+2&&tag[i+2]!=i+1&&tag[i+1]!=i)
		mx(g[i][2],1ll*h[i].v*w[i+2].v+1ll*h[i+2].v*w[i+1].v+1ll*h[i+1].v*w[i].v);
}
ll LZHAK(){
	for (int i=2;i<=n+1;i++) f[i]=-inf;
	for (int i=1;i<=n;i++){
		mx(f[i+1],f[i]+g[i][0]);
		mx(f[i+2],f[i]+g[i][1]);
		mx(f[i+3],f[i]+g[i][2]);
	}
	return f[n+1];
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
		scanf("%d",&w[i].v),w[i].id=i;
	for (int i=1;i<=n;i++)
		scanf("%d",&h[i].v),h[i].id=i;
	sort(w+1,w+n+1,cmp);
	sort(h+1,h+n+1,cmp);
	for (int i=1;i<=n;i++)
		posw[w[i].id]=i;
	for (int i=1;i<=n;i++)
		posh[h[i].id]=i;
	for (int i=1;i<=n;i++)
		tag[posh[i]]=posw[i];
	for (int i=1;i<=n;i++)
		solve(i);
	for (int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		swap(posh[x],posh[y]);
		tag[posh[x]]=posw[x];
		tag[posh[y]]=posw[y];
		solve(posh[x]);
		solve(posh[x]-1);
		solve(posh[x]-2);
		solve(posh[y]);
		solve(posh[y]-1);
		solve(posh[y]-2);
		printf("%I64d\n",LZHAK());
	}
}