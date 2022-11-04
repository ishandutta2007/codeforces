#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;

const int N=100005;
const int BLK=305;
int tp[N],v[N],in[N];
bool vis[N],clr[N],fl[N],ofl[N];
vector<pair<pii,int> > vec2[N];
vector<int> e[N]; 
void dfs1(int x,int fa=-1,int whi=0,int dis=0){
	if (vis[x]){
		if (fa!=-1)
			vec2[fa].PB(MK(MK(x,whi),dis));
		for (int i=0;i<e[x].size();i++)
			dfs1(e[x][i],x,0,0);
	}
	else{
		if (!fl[x]) whi++;
		for (int i=0;i<e[x].size();i++)
			dfs1(e[x][i],fa,whi,dis+1);
	}
}
void make1(int x){
	if (!fl[x]) return fl[x]=1,void(0);
	in[x]++;
	for (int i=0;i<vec2[x].size();i++)
		if (vec2[x][i].fi.se+1<=in[x])
			make1(vec2[x][i].fi.fi);
}
void make2(int x){
	fl[x]=0; in[x]=0; clr[x]=1;
	for (int i=0;i<vec2[x].size();i++){
		vec2[x][i].fi.se=vec2[x][i].se;
		make2(vec2[x][i].fi.fi);
	}
}
void dfs2(int x,int fa=0,bool cl=0){
	if (vis[x])
		fa=in[x],cl|=clr[x];
	else{
		fl[x]=ofl[x];
		if (cl) fl[x]=0;
		if (!fl[x]&&fa)
			fl[x]=1,fa--;
	}
	for (int i=0;i<e[x].size();i++)
		dfs2(e[x][i],fa,cl);
} 
int n,Q;
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=2;i<=n;i++){
		int x; scanf("%d",&x);
		e[x].push_back(i);
	}
	for (int i=1;i<=Q;i++)
		scanf("%d%d",&tp[i],&v[i]);
	for (int l=1,r=BLK;l<=Q;l+=BLK,r+=BLK){
		r=min(r,Q);
		for (int j=1;j<=n;j++){
			if (vis[j]) vec2[j].clear();
			vis[j]=clr[j]=0;
			ofl[j]=fl[j]; in[j]=0;
		}
		for (int j=l;j<=r;j++)
			vis[v[j]]=1;
		dfs1(1);
		for (int j=l;j<=r;j++)
			if (tp[j]==1) make1(v[j]);
			else if (tp[j]==2) make2(v[j]);
			else puts(fl[v[j]]?"black":"white");
		dfs2(1);
	}
}