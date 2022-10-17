#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#pragma GCC optimize(2)
#pragma GCC target("avx")
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int s[M],tp,n,q,p[M];
int a[M],b[M];
LL c[M];
bool vis[M];
vector<int> v[M];
int lg[M],dep[M],f[M][20];
void dfs(int x,int fa){
	f[x][0]=fa;
	if (fa==-1) dep[x]=1;
	else dep[x]=dep[fa]+1;
	F(i,1,lg[dep[x]]) f[x][i]=f[f[x][i-1]][i-1];
	LL ss=0;
	for (auto y:v[x]){
		dfs(y,x);
		ss+=b[y];
		if (c[y]<0) c[x]+=c[y],c[y]=0;
	}
	c[x]+=a[x]-b[x]+ss;
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int del=dep[x]-dep[y];
	F(i,0,lg[del]) if (del>>i&1) x=f[x][i];
	if (x==y) return x;
	DF(i,lg[dep[x]],0){
		if (f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
LL dis(int x,int y){
//	cout<<x<<" "<<y<<" lca : "<<lca(x,y)<<" "<<c[x]+c[y]-c[lca(x,y)]*2<<"   nmd\n";
	return c[x]+c[y]-c[lca(x,y)]*2;
}
void init(){
	F(i,2,n) lg[i]=lg[i>>1]+1;
	dfs(0,-1);
	F(i,1,n) c[i]+=c[f[i][0]];
}
LL ans;
set<int> sl;
set<int>::iterator it;
void ins(int x){
	int pre,suf;
	it=sl.lower_bound(x);
	if (it==sl.end()){
		pre=*(--it);
		suf=*sl.begin();
	}
	else{
		suf=*it; it--; pre=*it;
	}
	sl.insert(x);
	ans+=dis(x,pre)+dis(x,suf)-dis(pre,suf);
}
void del(int x){
	int pre,suf;
	sl.erase(x);
	it=sl.lower_bound(x);
	if (it==sl.end()){
		pre=*(--it);
		suf=*sl.begin();
	}
	else{
		suf=*it; it--; pre=*it;
	}
	ans-=dis(x,pre)+dis(x,suf)-dis(pre,suf);
}
int num[M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); q=read();
	F(i,1,n){
		p[i]=read();
		while (tp && p[s[tp]]<p[i]) tp--;
		v[s[tp]].pb(i);	
//		cout<<s[tp]<<" -> "<<i<<"  edge \n";
		s[++tp]=i;
	}
	F(i,1,n) a[i]=read();
	F(i,1,n) b[i]=read();
	init();
	sl.insert(0);
	F(i,1,q){
		int x=read();
		if (vis[x]){
			if (f[x][0]){
				vis[x]^=1;
				if (!(--num[f[x][0]])){
					del(f[x][0]);
				}
			}
			
		}
		else{
			if (f[x][0]){
				vis[x]^=1;
				if (!(num[f[x][0]]++)){
					ins(f[x][0]);
				}
			}
		}
		cout<<ans/2+c[0]<<"\n";
	}
	return 0;
}