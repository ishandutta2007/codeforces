#include<bits/stdc++.h>
#define maxn 500100
using namespace std;
typedef long long ll;
struct edge{int r,nxt;}e[maxn<<1];
struct data{
	ll a[2][3][2];
	data(){memset(a,0,sizeof(a));}
	data operator+(const data& d)const{
		data ret;
		for(int i=0;i<=1;++i)for(int j=0;j<=2;++j)
			for(int k=0;k<=1;++k)for(int ni=i;ni<=1;++ni)
				for(int nj=0;nj+j<=2;++nj)for(int nk=0;nk+k<=1;++nk){
					int x=(i==0&&ni==1?0:1),y=j+nj,z=nk+k;
					if(z==0&&j==1&&nj==1)continue;
					ret.a[x][y][z]+=a[i][j][k]*d.a[ni][nj][nk];
				}
		return ret;
	}
	void up(){
		a[1][1][1]+=a[1][1][0];
	}
	void print(int x){
		for(int i=0;i<=1;++i)
			for(int j=0;j<=2;++j)
				for(int k=0;k<=1;++k)
					if(a[i][j][k])printf("dp[%d][%d][%d][%d]=%I64d\n",x,i,j,k,a[i][j][k]);
	}
}dp[maxn];
int head[maxn],esz,n,flag,c[maxn];
ll ans;
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
}
int dfs(int u,int f){
	int sz=1;
	dp[u].a[0][0][0]=dp[u].a[1][1][0]=1;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f){
		sz+=dfs(e[t].r,u);
		dp[u]=dp[u]+dp[e[t].r];
	}
	dp[u].up();
	if(sz%2==n%2&&sz%2==0)ans+=1ll*sz*(n-sz)*flag;
	return sz;
}
int chk(int u,int f){
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f){
		if(!chk(e[t].r,u))return false;
		if(!c[e[t].r]&&c[u])return false;
		else if(!c[e[t].r]&&!c[u])c[u]=1;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=2,u,v;i<=n;++i)
		scanf("%d%d",&u,&v),addedge(u,v);
	flag=chk(1,0),dfs(1,0);
	cout<<dp[1].a[1][2][1]+ans;
}