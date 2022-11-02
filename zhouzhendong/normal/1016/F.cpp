#include <bits/stdc++.h>
#define y0 _zzd0001
#define y1 _zzd0002
#define rank _zzd0003
#define next _zzd0004
using namespace std;
typedef long long LL;
typedef long double LD;
const int N=300005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
struct Gragh{
	static const int M=N*2;
	int cnt,y[M],z[M],nxt[M],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b,int c){
		y[++cnt]=b,z[cnt]=c,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,m;
int vis[N];
LL dep[N],len[N],size[N];
int p[N],pcnt;
bool dfs1(int x,int pre){
	if (x==n){
		vis[x]=1;
		p[++pcnt]=x;
		return 1;
	}
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre)
			if (dfs1(g.y[i],x)){
				vis[x]=1;
				p[++pcnt]=x;
				len[pcnt]=g.z[i];
				return 1;
			}
	return 0;
}
void GetRoad(){
	pcnt=0;
	bool f=dfs1(1,0);
}
LL dfs2(int rt,int x,int pre,LL d){
	size[rt]++;
	LL maxd=d;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre&&!vis[g.y[i]])
			maxd=max(maxd,dfs2(rt,g.y[i],x,d+g.z[i]));
	return maxd;
}
int main(){
	n=read(),m=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read(),w=read();
		g.add(x,y,w);
		g.add(y,x,w);
	}
	GetRoad();
	for (int i=1;i<=pcnt;i++)
		vis[p[i]]=1;
	memset(size,0,sizeof size);
	for (int i=1;i<=pcnt;i++)
		dep[i]=dfs2(p[i],p[i],0,0);
//	dep[pcnt]=dep[1]=0;
	LL Max=-1e18,ans=-1e18,tot=0;
	for (int i=pcnt-1;i>=1;i--){
		if (dep[i+1]==0&&dep[i]==0){
			Max-=len[i+1];
			tot+=len[i+1];
			ans=max(ans,Max);
			Max=max(Max,-len[i+1]);
			continue;
		}
		Max=max(Max,dep[i+1]);
		Max-=len[i+1];
		tot+=len[i+1];
		ans=max(ans,Max+dep[i]);
	}
	for (int i=1;i<=pcnt;i++)
		if (size[p[i]]>2)
			ans=0;
	while (m--){
		LL x=min(ans+read(),0LL);
		printf("%I64d\n",tot+x);
	}
	return 0;
}