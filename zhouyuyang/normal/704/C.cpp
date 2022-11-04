#include<bits/stdc++.h>
#define N 100005
#define mo 1000000007
using namespace std;
struct edge{int to,next,v;}e[N*2];
int fl[N],head[N],vis[N],dp[N][2][2];
int n,tot=1,m,u,v,del,pdu,pdv,an0,an1,cnt;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void add(int x,int y,int v1,int v2){
	x=abs(x); y=abs(y);
	add(x,y,v1); add(y,x,v2);
}
void dfs(int x,int pre){
	cnt-=2; vis[x]=1;
	for (int i=head[x];i;i=e[i].next){
		cnt++;
		if (e[i].to==x) cnt++;
		if (!vis[e[i].to]) dfs(e[i].to,i);
		else if (i!=(pre^1)){
			u=x; v=e[i].to; del=i;
		}
	}
}
int check(int k1,int k2,int k3){
	if ((k3&2)==0) k1^=1;
	if ((k3&1)==0) k2^=1;
	return k1|k2;
}
void treedp(int x,int fa){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&(i^del)&&(i^del^1))
			treedp(e[i].to,x);
	memset(dp[x],0,sizeof(dp[x]));
	for (int w=0;w<2;w++){
		if (x==u&&w!=pdu) continue;
		if (x==v&&w!=pdv) continue;
		int ans0=1,ans1=0;
		for (int i=head[x];i;i=e[i].next){
			int to=e[i].to;
			if (to==fa||!(i^del)||!(i^del^1)) continue;
			int an0=ans0,an1=ans1; ans0=0; ans1=0;
			for (int w1=0;w1<2;w1++){
				int A=dp[to][w1][0],B=dp[to][w1][1];
				if (check(w,w1,e[i].v)) swap(A,B);
				ans0=(ans0+1ll*A*an0+1ll*B*an1)%mo;
				ans1=(ans1+1ll*A*an1+1ll*B*an0)%mo;
			}
		}
		if (fl[x]&(1<<w)) swap(ans0,ans1);
		dp[x][w][0]=(dp[x][w][0]+ans0)%mo;
		dp[x][w][1]=(dp[x][w][1]+ans1)%mo;
	}
}
void solve(int x){
	cnt=0; del=-100; dfs(x,-1);
	int ans0=0,ans1=0;
	if (del==-100){
		v=0; u=x; pdu=0; pdv=1; treedp(x,0); 
		ans0=(ans0+1ll*dp[x][0][0]+dp[x][1][0])%mo;
		ans1=(ans1+1ll*dp[x][0][1]+dp[x][1][1])%mo;
		pdu=1; treedp(x,0);
		ans0=(ans0+1ll*dp[x][0][0]+dp[x][1][0])%mo;
		ans1=(ans1+1ll*dp[x][0][1]+dp[x][1][1])%mo;
	}
	else{
		for (pdu=0;pdu<2;pdu++)
			for (pdv=0;pdv<2;pdv++){
				treedp(u,0);
				if (check(pdu,pdv,e[del].v))
					swap(dp[u][0][0],dp[u][0][1]),
					swap(dp[u][1][0],dp[u][1][1]);
				ans0=(ans0+1ll*dp[u][0][0]+dp[u][1][0])%mo;
				ans1=(ans1+1ll*dp[u][0][1]+dp[u][1][1])%mo;
			}
	}
	int k0=an0,k1=an1;
	an0=(1ll*k0*ans0+1ll*k1*ans1)%mo;
	an1=(1ll*k0*ans1+1ll*k1*ans0)%mo;
}
int main(){
	scanf("%d%d",&m,&n);
	for (;m;m--){
		int x,y;
		scanf("%d",&x);
		if (x==1){
			scanf("%d",&y);
			if (y>0) fl[y]|=2;
			else fl[-y]|=1;
		}
		else{
			scanf("%d%d",&x,&y);
			if (x<0&&y<0) add(x,y,0,0);
			if (x<0&&y>0) add(x,y,1,2);
			if (x>0&&y<0) add(x,y,2,1);
			if (x>0&&y>0) add(x,y,3,3);
		}
	}
	an0=1; an1=0;
	for (int i=1;i<=n;i++)
		if (!vis[i]) solve(i);
	printf("%d",an1);
}