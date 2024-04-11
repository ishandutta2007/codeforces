#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=50005*2*5;
int n,m,k;
vector <int> id[N],e[N],e2[N],e3[N];
struct Edge{
	int x,y,c,t,id;
}E[N];
bool cmpt(Edge a,Edge b){
	return a.t<b.t;
}
bool cmpc(int a,int b){
	return E[a].c<E[b].c;
}
int op(int x){
	return x<=m*5?x+m*5:x-m*5;
}
int dfn[N],low[N],inst[N],st[N],bh[N],Time=0,top=0,scc=0;
void Tarjan(int x){
	dfn[x]=low[x]=++Time;
	st[++top]=x;
	inst[x]=1;
	for (auto y : e[x])
		if (!dfn[y]){
			Tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if (inst[y])
			low[x]=min(low[x],low[y]);
	if (low[x]==dfn[x]){
		inst[st[top]]=0;
		bh[st[top]]=++scc;
		while (st[top--]!=x){
			inst[st[top]]=0;
			bh[st[top]]=scc;
		}
	}
}
void AddEdge(int x,int y){
	e[x].pb(y);
	e[op(y)].pb(op(x));
}
int o[N];
int vis[N];
void dfs(int x){
	if (vis[x])
		return;
//	printf("dfs(%d)\n",x);
	vis[x]=1;
	for (auto y : e3[x])
		dfs(y);
}
int check(int t){
//	printf("check(%d)\n",t);
	clr(vis);
	For(i,t+1,m)
		dfs(bh[op(i)]);
	queue <int> q;
	static int in[N];
	clr(in);
	For(i,1,scc)
		for (auto j : e2[i])
			in[j]++;
	For(i,1,scc)
		if (!in[i])
			q.push(i);
	while (!q.empty()){
		int x=q.front();
		q.pop();
		if (!vis[x]&&!vis[o[x]])
			vis[x]=1;
		if (!vis[o[x]])
			for (auto y : e2[x])
				if (!--in[y])
					q.push(y);
	}
	For(i,1,scc)
		if (1^vis[i]^vis[o[i]])
			return 0;
	return 1;
}
int main(){
	n=read(),m=read();
	For(i,1,m)
		E[i].x=read(),E[i].y=read(),E[i].c=read(),E[i].t=read(),E[i].id=i;
	sort(E+1,E+m+1,cmpt);
	For(i,1,m){
		int x=E[i].x,y=E[i].y;
		id[x].pb(i),id[y].pb(i);
	}
	k=m+1;
	For(i,1,n){
		sort(id[i].begin(),id[i].end(),cmpc);
		int cnt=0,x=0,y=0;
		For(j,1,(int)id[i].size()-1)
			if (E[id[i][j]].c==E[id[i][j-1]].c)
				cnt++,x=id[i][j],y=id[i][j-1];
		if (cnt>1)
			return puts("No"),0;
		if (cnt==1){
			AddEdge(x,op(y));
			AddEdge(op(x),y);
		}
		int t=(int)id[i].size();
		For(j,0,(int)id[i].size()-1){
			AddEdge(id[i][j],k+j);
			AddEdge(id[i][j],k+j+t);
		}
		For(j,0,(int)id[i].size()-2){
			AddEdge(k+j,k+j+1);
			AddEdge(k+t+j+1,k+t+j);
			AddEdge(k+j,op(k+j+t+1));
		}
		k+=t*2;
	}
	k--;
	assert(k==m*5);
	For(i,1,m*10)
		if (!dfn[i])
			Tarjan(i);
	For(i,1,m*10)
		if (bh[i]==bh[op(i)])
			return puts("No"),0;
	For(x,1,m*10)
		for (auto y : e[x])
			if (bh[x]!=bh[y]){
				e3[bh[x]].pb(bh[y]);
				e2[bh[y]].pb(bh[x]);
			}
	For(i,1,m*10)
		o[bh[i]]=bh[op(i)];
	int L=0,R=m,ans=m+1;
	while (L<=R){
		int mid=(L+R)>>1;
		if (check(mid))
			R=mid-1,ans=mid;
		else
			L=mid+1;
	}
	if (ans==m+1)
		return (void)puts("No"),0;
	check(ans);
	puts("Yes");
	vector <int> res;
	For(i,1,m)
		if (vis[bh[i]])
			res.pb(i);
	printf("%d %d\n",E[ans].t,(int)res.size());
	for (auto i : res)
		printf("%d ",E[i].id);
	puts("");
	return 0;
}