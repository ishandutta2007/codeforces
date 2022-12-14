#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,MAXN=3e5+10;
vector<int> edge[MAXN];
int vertex[MAXN];
bool visit[MAXN];
long long int ans=0,cnt[3];
void dfs(int x){
   cnt[vertex[x]]++;
   visit[x]=true;
   for(int i=0;i<edge[x].size();i++){
      int next=edge[x][i];
      if(!visit[next]){
         vertex[next]=3-vertex[x];
         dfs(next);
      }
      else if(vertex[x]+vertex[next]!=3)
         ans=0;
   }
}
long long int exp(long long int x){
   if(x==0) return 1;
   else if(x==1)  return 2;
   long long int tmp=1;
   if(x%2)  tmp*=2;
   return (tmp*exp(x/2)%MOD)*exp(x/2)%MOD;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t,n,m;
   cin>>t;
   while(t--){
      cin>>n>>m;
      for(int i=1;i<=n;i++)
         edge[i].clear();
      for(int i=1;i<=n;i++)
         vertex[i]=visit[i]=0;
      for(int i=1,a,b;i<=m;i++){
         cin>>a>>b;
         edge[a].push_back(b);edge[b].push_back(a);
      }
      ans=1;
      for(int i=1;i<=n;i++)
         if(!visit[i]){
            vertex[i]=1;
            cnt[1]=cnt[2]=0;
            dfs(i);
            ans=(ans*(exp(cnt[1])+exp(cnt[2])))%MOD;
         }
      cout<<ans<<endl;

   }

}