#include<bits/stdc++.h>
#define maxn 4010000
#define xx first
#define yy second
using namespace std;
const int inf=2e9;
typedef pair<int,int> pii;
int n,m1,m2,t,tp,ptr,c[maxn],z[maxn],d[maxn],np;
pii lsh[maxn],dp[maxn][2],e[maxn];
int main(){
	scanf("%d%d%d%d",&n,&m1,&m2,&t);
	for(int i=1,xi;i<=m1;++i){
		scanf("%d",&xi);
		lsh[++tp]=pii(xi-1,0);
		lsh[++tp]=pii(xi,1);
		lsh[++tp]=pii(xi+1,0);
	}
	for(int i=1,xi;i<=m2;++i){
		scanf("%d",&xi);
		lsh[++tp]=pii(xi-1,0);
		lsh[++tp]=pii(xi,2);
		lsh[++tp]=pii(xi+1,0);
	}
	lsh[++tp]=pii(0,0);
	lsh[++tp]=pii(n+1,0);
	sort(lsh+1,lsh+tp+1);
	for(int i=1;i<=tp;++i)
		if(!ptr||lsh[i].first!=lsh[ptr].first)lsh[++ptr]=lsh[i];
		else lsh[ptr].second|=lsh[i].second;
	dp[1][0]=dp[1][1]=pii(t,0);
	for(int i=2;i<=ptr;++i)
		for(int j=0;j<2;++j){
			dp[i][j]=pii(inf,0);
			int dt=lsh[i].xx-lsh[i-1].xx;
			if(lsh[i].yy>>j&1){
				if(dp[i-1][j].xx-dt+1<=0)dp[i][j]=min(dp[i][j],pii(dp[i-1][j].xx+t-dt,j));
			} else {
				int flg=lsh[i].yy>>(j^1)&1;
				if(flg&&dp[i-1][j^1].xx-dt+1<=0)
					dp[i][j]=min(dp[i][j],pii(max(0,dp[i-1][j^1].xx+t-dt),j^1));
				else if(!flg)dp[i][j]=min(dp[i][j],pii(max(0,dp[i-1][j^1].xx-dt),j^1));
				dp[i][j]=min(dp[i][j],pii(dp[i-1][j].xx-dt,j));	
			}
		}
	int ans=-1;
	if(dp[ptr][0].xx<=t)ans=0;
	if(dp[ptr][1].xx<=t)ans=1;
	if(ans==-1)return puts("No"),0;
	puts("Yes");
	int nw=ans,tp=0,tp2=0;
	for(int i=ptr;i>=2;--i){
		int nxt=dp[i][nw].yy;
		if(nxt!=nw)c[++tp]=i;
		z[++tp2]=i,d[tp2]=nw;
//		printf("[%d,%d]",lsh[i].xx,nw);
		nw=nxt;
	}
//	printf("[begin:%d]",nw);
	if(nw==1)c[++tp]=1;
	reverse(c+1,c+tp+1);
	reverse(d+1,d+tp2+1);
	reverse(z+1,z+tp2+1);
	printf("%d\n",tp);
	for(int i=1;i<=tp;++i)
		printf("%d ",lsh[c[i]].xx);
	int lsttim=t;
	for(int i=1;i<=tp2;++i){
		int nxtp=z[i],nd=d[i];
		if(lsh[nxtp].yy>>nw&1)e[++np]=pii(lsttim,nw+1),lsttim+=t;
		if(nw!=nd)lsttim=max(lsttim,lsh[nxtp].xx);
		nw=nd;
//		printf("{%d}",nw);
	}
	printf("\n%d\n",np);
	for(int i=1;i<=np;++i)
		printf("%d %d\n",e[i].xx,e[i].yy);
}