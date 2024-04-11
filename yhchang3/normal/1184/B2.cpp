#include<bits/stdc++.h>
using namespace std;
int Nx,Ny;
const int MAXN = 1000;
vector<int> edgex[MAXN+1],edgey[MAXN+1];
int matchx[MAXN+1],matchy[MAXN+1];//x pairs with matchx[x]; y pairs with matchy[y]
bool visitx[MAXN+1],visity[MAXN+1];
bool dfs(int x){
   visitx[x]=true;
   for(int i=0;i<edgex[x].size();i++){
      int y=edgex[x][i];
      visity[y]=true;
      if(matchy[y]==-1||(!visitx[matchy[y]]&&dfs(matchy[y]))){
         matchy[matchx[x]=y]=x;
         return true;
      }
   }
   return false;
}
int matching(){
   memset(matchx,-1,sizeof matchx);
   memset(matchy,-1,sizeof matchy);
   int ans=0;
   for(int i=1;i<=Nx;i++){
      memset(visitx,0,sizeof visitx);
      memset(visity,0,sizeof visity);
      if(dfs(i))  ans++;
   }
   return ans;
}

int dp[101][101];
int ss[1001],a[1001],f[1001];
int bb[1001],d[1001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			dp[i][j]=1e9+1;
	for(int i=1;i<=100;i++)
		dp[i][i]=0;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		dp[u][v]=dp[v][u]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	int s,b,k,h;
	cin>>s>>b>>k>>h;
	Nx=s;Ny=b;
	for(int i=1;i<=s;i++)
		cin>>ss[i]>>a[i]>>f[i];
	for(int i=1;i<=b;i++)
		cin>>bb[i]>>d[i];
	for(int i=1;i<=s;i++)
		for(int j=1;j<=b;j++)
			if(f[i]>=dp[ss[i]][bb[j]]&&a[i]>=d[j]){
				edgex[i].emplace_back(j);
				edgey[j].emplace_back(i);
			}
	long long int ans=(long long int) s*h;
	int ma=matching();
	cout<<min(ans,1LL*ma*k)<<endl;

}