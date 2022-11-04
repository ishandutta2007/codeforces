#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
using namespace std;
const int N=1005;
int n,x[N],y[N];
int tp1,tp2,q[N*2];
pii ln1[N],ln2[N];
map<int,set<pii>> mp1,mp2;
vector<pii> ans1,ans2;
set<pii> Ln1,Ln2;
int E[N][N],mat[N],Mat[N];
struct edge{
	int to,next,f;
}e[N*N];
int head[N*2],tot=1;
int dis[N*2],S,T;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	For(i,1,T) dis[i]=-1;
	int h=0,t=1; dis[q[1]=S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[q[++t]=e[i].to]=dis[x]+1;
				if (e[i].to==T) return 1;
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if (x==T) return flow;
	int k,rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f));
			rest-=k; e[i].f-=k; e[i^1].f+=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
void output(vector<pii > ans){
	printf("%d\n",ans.size());
	for (auto i:ans)
		printf("%d %d %d %d\n",x[i.fi],y[i.fi],x[i.se],y[i.se]);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d",&x[i],&y[i]);
		mp1[x[i]].insert(pii(y[i],i));
		mp2[y[i]].insert(pii(x[i],i));
	}
	for (auto i:mp1){
		int las=-1;
		for (auto j:i.se){
			if (las!=-1) ln1[++tp1]=pii(las,j.se);
			las=j.se;
		}
	}
	for (auto i:mp2){
		int las=-1;
		for (auto j:i.se){
			if (las!=-1) ln2[++tp2]=pii(las,j.se);
			las=j.se;
		}
	}
	S=tp1+tp2+1; T=S+1;
	For(i,1,tp1) add(S,i,1);
	For(i,1,tp2) add(i+tp1,T,1);
	For(i,1,tp1) For(j,1,tp2)
		if (x[ln2[j].fi]<x[ln1[i].fi]&&x[ln1[i].fi]<x[ln2[j].se])
			if (y[ln1[i].fi]<y[ln2[j].fi]&&y[ln2[j].fi]<y[ln1[i].se])
				add(i,j+tp1,1),E[i][j]=1;
	while (bfs()) dfs(S,1e9);
	For(i,1,tp1) for (int j=head[i];j;j=e[j].next)
		if (tp1<e[j].to&&e[j].to<=tp1+tp2&&!e[j].f)
			mat[e[j].to-tp1]=i,Mat[i]=e[j].to-tp1;
	for (;;){
		bool fl=1;
		For(i,1,tp1) if (!Mat[i]){
			Ln1.insert(ln1[i]);
			fl=0; Mat[i]=-1;
			For(j,1,tp2) if (E[i][j])
				Mat[mat[j]]=0,mat[j]=-1; 
		}
		For(i,1,tp2) if (!mat[i]){
			Ln2.insert(ln2[i]);
			fl=0; mat[i]=-1;
			For(j,1,tp1) if (E[j][i])
				mat[Mat[j]]=0,Mat[j]=-1; 
		}
		if (fl) break;
	}
	For(i,1,tp1)
		if (Mat[i]>0)
			Ln1.insert(ln1[i]);
	for (auto i:mp1){
		int top=0;
		for (auto j:i.se)
			q[++top]=j.se;
		int las=1;
		For(j,1,top-1)
			if (!Ln1.count(pii(q[j],q[j+1])))
				ans1.PB(pii(q[las],q[j])),las=j+1; 
		ans1.PB(pii(q[las],q[top]));
	}
	for (auto i:mp2){
		int top=0;
		for (auto j:i.se)
			q[++top]=j.se;
		int las=1;
		For(j,1,top-1)
			if (!Ln2.count(pii(q[j],q[j+1])))
				ans2.PB(pii(q[las],q[j])),las=j+1; 
		ans2.PB(pii(q[las],q[top]));
	}
	output(ans2);
	output(ans1); 
}