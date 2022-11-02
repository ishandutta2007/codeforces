#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N=100005*2,M=200005*2;
struct Gragh{
	int cnt,x[M],y[M],nxt[M],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,x[cnt]=a,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,m,s,f[N][2],sol[N];
int head,tail,q[N],ty[N],qmod,pr[N][2];
void solved(int t){
	int cnt=0;
	for (int x=t,ty=0;x!=s||ty!=1;x=pr[x][ty],ty^=1)
		sol[++cnt]=x;
	sol[++cnt]=s;
	puts("Win");
	for (int i=cnt;i>=1;i--)
		printf("%d ",sol[i]);
}
int inst[N],vis[N],st[N],top,dfn[N],low[N],bh[N],ans,time;
void tarjan(int x){
	dfn[x]=low[x]=++time;
	st[++top]=x;
	vis[x]=inst[x]=1;
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (!vis[g.y[i]]){
			tarjan(g.y[i]);
			low[x]=min(low[x],low[g.y[i]]);
		}
		else if (inst[g.y[i]])
			low[x]=min(low[x],low[g.y[i]]);
	if (dfn[x]==low[x]){
		ans++;
		inst[st[top]]=0;
		bh[st[top]]=ans;
		while (st[top--]!=x){
			inst[st[top]]=0;
			bh[st[top]]=ans;
		}
	}
}
int cnt[N];
bool rounded(){	
	ans=top=time=0;
	tarjan(s);
	for (int i=1;i<=n;i++)
		cnt[bh[i]]++;
	for (int i=1;i<=ans;i++)
		if (cnt[i]>1)
			return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	g.clear();
	for (int i=1;i<=n;i++){
		int c,y;
		scanf("%d",&c);
		while (c--){
			scanf("%d",&y);
			g.add(i,y);
		}
	}
	scanf("%d",&s);
	f[s][1]=1,head=0,tail=1;
	q[tail]=s,ty[tail]=1;
	while (head<tail){
		int x=q[++head],y,type=ty[head]^1;
		for (int i=g.fst[x];i;i=g.nxt[i])
			if (!f[y=g.y[i]][type])
				f[y][type]=1,pr[y][type]=x,q[++tail]=y,ty[tail]=type;
	}
	for (int i=1;i<=n;i++)
		if (!g.fst[i]&&f[i][0]){
			solved(i);
			return 0;
		}
	puts(rounded()?"Draw":"Lose");
	return 0;
}