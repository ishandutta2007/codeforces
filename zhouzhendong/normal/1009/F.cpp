//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
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
int depth[N],Maxd[N];
int Next[N],val[N],ans[N],ansv[N];
void solve(int x,int pre,int d){
	depth[x]=Maxd[x]=d;
	int id=x;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre){
			solve(g.y[i],x,d+1);
			if (Maxd[id]<Maxd[g.y[i]]+1)
				id=g.y[i];
		}
	if (id==x){
		val[x]=ansv[x]=1;
		Next[x]=ans[x]=0;
		return;
	}
	Next[x]=id;
	Maxd[x]=Maxd[id]+1;
	if (ansv[id]==1)
		ans[x]=0,ansv[x]=1;
	else
		ans[x]=ans[id]+1,ansv[x]=ansv[id];
	val[x]=1;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre&&g.y[i]!=id)
			for (int p1=id,p2=g.y[i],dep=1;p2;p1=Next[p1],p2=Next[p2],dep++){
				val[p1]+=val[p2];
				if (val[p1]>ansv[x]||(val[p1]==ansv[x]&&dep<ans[x]))
					ans[x]=dep,ansv[x]=val[p1];
			}
}
int main(){
	n=read();
	g.clear();
	for (int i=1;i<n;i++){
		int a=read(),b=read();
		g.add(a,b);
		g.add(b,a);
	}
	solve(1,0,0);
	for (int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}