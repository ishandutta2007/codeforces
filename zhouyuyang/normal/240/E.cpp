#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
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

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i++)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<61)
using namespace std;

const int N=100005;
int n,m,t,cnt,rt;
int d[N],v[N],in[N],be[N];
int la[N],mn[N],g[N];
struct edge{
	int x,y,v;
}e[N],q[N*10];
int MST(){
	for(int ans=0;;){
		For(i,1,n) in[i]=be[i]=la[i]=v[i]=0,mn[i]=(1<<30);
		For(i,1,m)
			if (e[i].x!=e[i].y&&e[i].y!=rt&&e[i].v<mn[e[i].y])
				in[e[i].y]=e[i].x,mn[e[i].y]=e[i].v,la[e[i].y]=d[i];
		For(i,1,n) if (i!=rt&&mn[i]==(1<<30)) return -1;
		For(i,1,n) if (i!=rt){
			q[la[i]].v++; ans+=mn[i];
			int j=i;
			for (;v[j]!=i&&j!=rt&&!be[j];j=in[j]) v[j]=i;
			if (j!=rt&&!be[j]){
				cnt++; int k=j;
				for (;in[k]!=j;k=in[k]) be[k]=cnt;
				be[k]=cnt;
			}
		}
		if (!cnt) return ans;
		For(i,1,n) if (!be[i]) be[i]=++cnt;
		For(i,1,m){
			int y=e[i].y;
			e[i].x=be[e[i].x]; e[i].y=be[e[i].y];
			if (e[i].x!=e[i].y)
				e[i].v-=mn[y],q[++t]=(edge){d[i],la[y],0},d[i]=t;
		}
		rt=be[rt]; n=cnt; cnt=0;
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m); t=m; rt=1;
	For(i,1,m){
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].v);
		d[i]=i; g[i]=e[i].v;
	}
	int ans=MST(); printf("%d\n",ans);
	if (ans!=-1){
		for (int i=t;i>m;i--)	
			q[q[i].x].v+=q[i].v,q[q[i].y].v-=q[i].v;
		For(i,1,m) if (g[i]&&q[i].v) printf("%d ",i); 
	}
}