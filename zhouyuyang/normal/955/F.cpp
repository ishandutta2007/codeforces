#include<bits/stdc++.h>
#define N 300005
using namespace std;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int mx[N],dp[N][25];
long long ans;
int n,q[N];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int fa){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			mx[x]=max(mx[x],mx[e[i].to]);
		}
	++mx[x]; ans+=mx[x];
	dp[x][1]=n;
	for (int p=2;p<=20;p++){
		int tp=0;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa)
				q[++tp]=dp[e[i].to][p-1];
		sort(q+1,q+tp+1,cmp);
		for (int j=tp;j>=2;j--)
			if (q[j]>=j){
				dp[x][p]=j;
				break;
			}
	}
}
void solve(int x,int fa){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			solve(e[i].to,x);
			for (int j=1;j<=20;j++)
				dp[x][j]=max(dp[x][j],dp[e[i].to][j]);
		}
	for (int i=1;i<=20;i++){
		ans+=1ll*(dp[x][i]-dp[x][i+1])*i;
		if (dp[x][i+1]==0){
			ans-=i; break;
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	solve(1,0);
	printf("%lld",ans);
}