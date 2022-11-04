#include<bits/stdc++.h>
#define fi first
#define se second
#define pa pair<int,int>
using namespace std;
const int N=300005;
struct edge{
	int to,next;
}e[N*2];
int head[N],fa[N],tot,n,T;
int sz[N],pos[N],dep[N];
char s[N*2],ss[N*2];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs1(int x){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			dep[e[i].to]=dep[x]+1;
			fa[e[i].to]=x;
			dfs1(e[i].to);
			sz[x]+=sz[e[i].to];
		}
}
int top[N];
void dfs2(int x,int tp){
	pos[x]=++T; top[x]=tp;
	s[T]=ss[x]; int k=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&sz[e[i].to]>sz[k])
			k=e[i].to;
	if (k) dfs2(k,tp);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k)
			dfs2(e[i].to,e[i].to);
}
int LCA(int x,int y){
	for (;top[x]!=top[y];x=fa[top[x]])
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
vector<pa> read(){
	int x,y,L;
	vector<pa> res,res2;
	scanf("%d%d",&x,&y);
	L=LCA(x,y);
	for (;top[x]!=top[L];x=fa[top[x]])
		res.push_back(pa(2*n+2-pos[x],pos[x]-pos[top[x]]+1));
	res.push_back(pa(2*n+2-pos[x],pos[x]-pos[L]+1));
	for (;top[y]!=top[L];y=fa[top[y]])
		res2.push_back(pa(pos[top[y]],pos[y]-pos[top[y]]+1));
	if (y!=L) res2.push_back(pa(pos[L]+1,pos[y]-pos[L]));
	for (int i=res2.size()-1;i>=0;i--)
		res.push_back(res2[i]);
	return res;
}
const int M=600010;
int bit[M],nn;
void initSA(){
	nn=n*2+1; s[n+1]='@';
	for (int i=1;i<=n;i++) s[n*2+2-i]=s[i];
	for (int i=2;i<=nn;i++) bit[i]=bit[i>>1]+1;
}
int cnt[M],x[M],y[M];
int SA[M],rk[M];
bool cmp(int i,int j,int k){
	return y[i]!=y[j]||((i+k>nn?-1:y[i+k])!=(j+k>nn?-1:y[j+k]));
}
void buildSA(){
	int m=128;
	for (int i=1;i<=nn;i++) cnt[x[i]=s[i]]++;
	for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
	for (int i=nn;i>=1;i--) SA[cnt[x[i]]--]=i;
	for (int k=1;k<nn;k<<=1){
		int p=0;
		for (int i=nn-k+1;i<=nn;i++) y[++p]=i;
		for (int i=1;i<=nn;i++)
			if (SA[i]>k) y[++p]=SA[i]-k;
		for (int i=0;i<=m;i++) cnt[i]=0;
		for (int i=1;i<=nn;i++) cnt[x[y[i]]]++;
		for (int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
		for (int i=nn;i>=1;i--) SA[cnt[x[y[i]]]--]=y[i];
		swap(x,y); m=1; x[SA[1]]=1;
		for (int i=2;i<=nn;i++) x[SA[i]]=(m+=cmp(SA[i],SA[i-1],k));
		if (m>=nn) break;
	}
	for (int i=1;i<=nn;i++)
		rk[SA[i]]=i;
}
int hei[M][20];
int buildhei(){
	int p=0;
	for (int i=1;i<=nn;i++)
		if (rk[i]!=1){
			int p1=i,p2=SA[rk[i]-1]; p-=(p!=0);
			for (;p1+p<=nn&&p2+p<=nn&&s[p1+p]==s[p2+p];p++);
			hei[rk[i]][0]=p;
		}
	for (int i=1;i<=19;i++)
		for (int j=1;j+(1<<i)-1<=nn;j++)
			hei[j][i]=min(hei[j][i-1],hei[j+(1<<(i-1))][i-1]);
}
int askLCP(int x,int y){
	if (x==y) return nn;
	x=rk[x]; y=rk[y];
	if (x>y) swap(x,y); x++;
	int lg=bit[y-x+1];
	return min(hei[x][lg],hei[y-(1<<lg)+1][lg]);
}
int main(){
	scanf("%d%s",&n,ss+1);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dep[1]=1;
	dfs1(1);
	dfs2(1,1);
	initSA(); 
	buildSA();
	buildhei();
	int Q;
	scanf("%d",&Q);
	while (Q--){
		vector<pa> x=read(),y=read();
		int id1=0,id2=0,ans=0;
		for (;id1!=x.size()&&id2!=y.size();){
			int LCP=askLCP(x[id1].fi,y[id2].fi);
			LCP=min(LCP,min(x[id1].se,y[id2].se));
			x[id1].fi+=LCP; x[id1].se-=LCP;
			y[id2].fi+=LCP; y[id2].se-=LCP; ans+=LCP;
			if (x[id1].se&&y[id2].se) break;
			if (!x[id1].se) id1++;
			if (!y[id2].se) id2++;
		}
		printf("%d\n",ans);
	}
}