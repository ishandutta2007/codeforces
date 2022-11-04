#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<iostream>
#include<cmath>
#include<vector>
#define int64 long long
#define mk make_pair
#define pb push_back
#define sqr(x) (x)*(x)
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define VI vector<int>
#define VS vector<string>
#define PII pair<int,int>
#define VPII vector< PII >
#define N 110000
using namespace std;
const double pi=acos(-1);
PII P1[N],P2[N];
VI E[N];
int Pow[N],size[N],bo[N],v[N],in0[N],in1[N],out0[N],out1[N];
int ni_K,K,X,Y,n,m,tot;
int64 ans;
void prep(){
	int x=K,y=Y-2;
	ni_K=1;
	while(y){
		if(y&1)ni_K=1ll*ni_K*x%Y;
		x=1ll*x*x%Y;
		y/=2;
	}
	
	Pow[0]=1;
	rep(i,1,n)Pow[i]=1ll*Pow[i-1]*K%Y;
}
int getsize(int x,int ff){
	size[x]=1;
	for(int i:E[x])if(i!=ff)size[x]+=getsize(i,x);
	return size[x];
}
int getroot(int x){
	int maxx=0,id;
	for(int i:E[x])if(!bo[i] && size[i]>maxx)
		maxx=size[i],id=i;
	if(maxx*2>size[x]){
		size[x]-=maxx;
		size[id]+=maxx;
		return getroot(id);
	}
	return x;
}
void dfs(int x,int rev,int down,int up,int dep){
	P1[++tot]=mk((1ll*(X-up)*rev%Y+Y)%Y,x);
	P2[tot]=mk(down,x);
	bo[x]=1;
	for(int i:E[x])if(!bo[i])
		dfs(i,1ll*rev*ni_K%Y,(down+1ll*Pow[dep+1]*v[i])%Y,(1ll*up*K+v[i])%Y,dep+1);
	bo[x]=0;
}
void calc(int l,int r,int flag){
	#define x first
	#define y second
	sort(P1+l,P1+r+1);
	sort(P2+l,P2+r+1);
	int i,j=l,i0,j0;
	for(i=l;i<=r;i=i0){
		for(i0=i;i0<=r && P1[i].x==P1[i0].x;++i0);
		while(j<=r && P2[j].x<P1[i].x)j++;
		for(j0=j;j0<=r && P1[i].x==P2[j0].x;++j0);
		if(j!=j0)rep(k,i,i0-1)out0[P1[k].y]+=flag*(j0-j);
		if(j!=j0)rep(k,j,j0-1)in0[P2[k].y]+=flag*(i0-i);
		j=j0;
	}
	#undef x
	#undef y
}
void work(int x){
	x=getroot(x);
	bo[x]=1;
	tot=0;
	for(int i:E[x])if(!bo[i]){
		int tt=tot;
		dfs(i,ni_K,(1ll*v[i]*K+v[x])%Y,v[i],1);
		calc(tt+1,tot,-1);
	}
	P1[++tot]=mk(X,x);
	P2[tot]=mk(v[x],x);
	calc(1,tot,1);
	for(int i:E[x])if(!bo[i])work(i);
}
int main(){
	int x,y;
	scanf("%d%d%d%d",&n,&Y,&K,&X);
	prep();
	rep(i,1,n)scanf("%d",&v[i]);
	rep(i,1,n-1)scanf("%d%d",&x,&y),E[x].pb(y),E[y].pb(x);
	getsize(1,0);
	work(1);
	rep(i,1,n)in1[i]=n-in0[i],out1[i]=n-out0[i];
	ans=0;
	rep(i,1,n)ans+=2ll*out0[i]*out1[i]+2ll*in0[i]*in1[i]+1ll*in0[i]*out1[i]+1ll*in1[i]*out0[i];
	printf("%I64d\n",1ll*n*n*n-ans/2);
}