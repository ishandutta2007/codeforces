#include<stdio.h>
#include<memory.h>
int n,m,t;
int Last[100002],Next[100002],End[100002];
long long w[100002];
int dp[3002][3002],s[100002];
long long v[3002][3002];
inline int Min(int p,int q){return p<q?p:q;}
void dfs0(int p,int f){
	s[p]=1;
	for(int i=Last[p];i;i=Next[i])if(End[i]!=f)dfs0(End[i],p),w[p]+=w[End[i]],s[p]+=s[End[i]];
}
void dfs(int p,int f){
	int cnt=1;
	for(int i=0;i<=m&&i<=s[p];i++)dp[p][i]=0,v[p][i]=1e18;v[p][0]=0;
	for(int i=Last[p];i;i=Next[i])if(End[i]!=f){
		dfs(End[i],p);
		for(int j=Min(m,cnt+s[End[i]]);j>=1;j--)
			for(int k=Min(j,cnt);k>=0&&k>=j-s[End[i]];k--){
				if(dp[p][j]<dp[p][k]+dp[End[i]][j-k]||(dp[p][j]==dp[p][k]+dp[End[i]][j-k]&&v[p][j]>v[p][k]+v[End[i]][j-k]))
					dp[p][j]=dp[p][k]+dp[End[i]][j-k],v[p][j]=v[p][k]+v[End[i]][j-k];
			}cnt+=s[End[i]];
	}
	for(int j=Min(m,cnt);j>=1;j--)
		if(dp[p][j]<dp[p][j-1]+(w[p]-v[p][j-1]>0)||(dp[p][j]==dp[p][j-1]+(w[p]-v[p][j-1]>0)&&v[p][j]>w[p]))
			dp[p][j]=dp[p][j-1]+(w[p]-v[p][j-1]>0),v[p][j]=w[p];
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)Last[i]=0;
		for(int i=1;i<=n;i++){int p;scanf("%d",&p);w[i]=-p;}
		for(int i=1;i<=n;i++){int p;scanf("%d",&p);w[i]+=p;}
		for(int i=1;i<n+n-2;i+=2){
			scanf("%d%d",&End[i+1],&End[i]);
			Next[i]=Last[End[i+1]];Last[End[i+1]]=i;
			Next[i+1]=Last[End[i]];Last[End[i]]=i+1;
		}dfs0(1,0);dfs(1,0);
		printf("%d\n",dp[1][m-1]+(w[1]>v[1][m-1]));
	}
}