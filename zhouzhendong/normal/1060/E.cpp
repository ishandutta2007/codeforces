#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
struct Gragh{
	static const int M=N*2;
	int cnt,y[M],nxt[M],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n;
LL ans=0;
int size[N],s0[N],s1[N],depth[N];
LL d0[N],d1[N];
void dfs(int x,int pre,int d){
	size[x]=1;
	depth[x]=d;
	s0[x]=1,s1[x]=0;
	d0[x]=d1[x]=0;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre){
			int y=g.y[i];
			dfs(y,x,d+1);
			size[x]+=size[y];
			s0[x]+=s1[y];
			s1[x]+=s0[y];
			d0[x]+=d1[y];
			d1[x]+=d0[y]+s0[y];
		}
}
void solve(int x,int pre,LL v0,LL v1){
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre){
			int y=g.y[i];
			LL t0=d0[x]-d1[y];
			LL t1=d1[x]-d0[y]-s0[y];
			solve(y,x
				,v1+t1
				,v0+t0+((depth[x]&1)?s1[1]:s0[1])-s1[y]);
		}
	ans+=v0+v1+d0[x]+d1[x];
}
int main(){
	n=read();
	g.clear();
	for (int i=1;i<n;i++){
		int a=read(),b=read();
		g.add(a,b);
		g.add(b,a);
	}
	dfs(1,0,0);
	solve(1,0,0,0);
	cout << ans/2;
	return 0;
}