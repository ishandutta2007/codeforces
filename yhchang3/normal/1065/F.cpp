#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int jump[MAXN],n,k,x;
int dp[2][MAXN];
bool visit[MAXN];
vector<int> edge[MAXN];
void dfs(int now){
   visit[now]=true;
   int tmp=0;
   for(int i=0;i<edge[now].size();i++){
      int next=edge[now][i];
      if(visit[next])   continue;
      dfs(next);
      jump[now]=max(jump[now],jump[next]);
      if(jump[next]){
         dp[0][now]+=dp[0][next];
         dp[1][now]+=dp[0][next];
         tmp=max(dp[1][next]-dp[0][next],tmp);
      }
      else
         tmp=max(tmp,dp[1][next]);
   }
   dp[1][now]+=tmp;
   if(edge[now].size()==0){
      jump[now]=k;
      dp[0][now]=dp[1][now]=1;
   }
   else if(jump[now]>0)   jump[now]--;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>k;
   for(int i=2;i<=n;i++){
      cin>>x;
      edge[x].push_back(i);
   }
   dfs(1);
   cout<<dp[1][1]<<endl;
}