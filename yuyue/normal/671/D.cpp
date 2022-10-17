#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;
//------------ 
#define lc a[x].l 
#define rc a[x].r 
int rt[M]; 
struct node{
	int dis,l,r,rt,o;
	LL val,tg;
}a[M];
int tot;
int Fd(int x){
	return (a[x].rt==x ? x : a[x].rt=Fd(a[x].rt)); 
}
void Ps(int x,LL d){
	if (x) a[x].val+=d,a[x].tg+=d; 
}
void pd(int x){
	if (a[x].tg){
		Ps(lc,a[x].tg);
		Ps(rc,a[x].tg);
		a[x].tg=0; 
	}
}
int merge(int x,int y){
	if (!x || !y) return x|y;
//	cout<<x<<" "<<y<<"\n"; 	
	if (a[x].val>a[y].val) swap(x,y); 	
	pd(x);
	rc=merge(rc,y);
	if (a[lc].dis<a[rc].dis) swap(lc,rc); 
	a[lc].rt=a[rc].rt=a[x].rt=x; 
	a[x].dis=a[rc].dis+1; 
	return x;
}
//----------------
int to[M<<1],nxt[M<<1],head[M],cnt;
void add(int x,int y){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; 
}
#define pii pair<int,int>
#define mp make_pair
vector<pii> v[M];
LL f[M];
int dep[M];
void dfs(int x,int fa){
//	cout<<x<<" "<<fa<<"\n"; 
	F(i,0,SZ(v[x])){
		pii tmp=v[x][i]; 
		a[++tot].val=tmp.second; a[tot].dis=1; a[tot].o=tmp.first; 
		rt[x]=merge(rt[x],tot);
	}
//	cout<<x<<" "<<rt[x]<<"    gg\n"; 
	LL tmp=0; 	dep[x]=dep[fa]+1; 
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==fa) continue;
		dfs(y,x); tmp+=f[y]; 
		Ps(rt[y],-f[y]);
		rt[x]=merge(rt[x],rt[y]);
	}
	Ps(rt[x],tmp);
//	cout<<tmp<<"\n";
	while (rt[x] && dep[a[rt[x]].o]>=dep[x]){
//		cout<<a[rt[x]].o<<"   hfdh\n"; 
		pd(rt[x]); rt[x]=merge(a[rt[x]].l,a[rt[x]].r);
	}
//	cout<<a[rt[x]].val<<" ff "<<x<<"  fmfmf\n"; 
	if (rt[x]) f[x]=a[rt[x]].val;
	else {
		puts("-1");
		exit(0);
	}
}
int n,m; 
int main(){
	n=read(); m=read(); 
	F(i,1,n-1){
		int x=read(),y=read(); 
		add(x,y); add(y,x); 
	}
	F(i,1,m){
		int x=read(),y=read(),z=read();
		v[x].pb(mp(y,z)); 
	}
	LL ans=0; 
	for (int i=head[1];i;i=nxt[i]) 
	dfs(to[i],1),ans+=f[to[i]];
	cout<<ans<<"\n"; 
	return 0;
}