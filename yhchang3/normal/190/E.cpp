#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int parent[MAXN],Rank[MAXN],ans=0;
bool sw[MAXN];
vector<int> edge[MAXN];
void init(){
   for(int i=0;i<MAXN;i++){
      parent[i]=i;
      Rank[i]=1;
   }
}
int Find(int x){
   return x==parent[x]? x:parent[x]=Find(parent[x]);
}
void Union(int x,int y){
   int rootx=Find(x),rooty=Find(y);
   if(rootx!=rooty){
      if(Rank[rootx]<Rank[rooty])   swap(rootx,rooty);
      parent[rooty]=rootx;
      if(Rank[rootx]==Rank[rooty])  Rank[rootx]++;
   }
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   init();
   int n,m;
   cin>>n>>m;
   for(int i=1,a,b;i<=m;i++){
      cin>>a>>b;
      edge[a].push_back(b);
      edge[b].push_back(a);
   }
   int idx=1;
   for(int i=1;i<=n;i++)
      if(edge[idx].size()>edge[i].size())
         idx=i;
   for(int i=0;i<edge[idx].size();i++)
      sw[edge[idx][i]]=true;
   for(int i=1;i<=n;i++)
      if(!sw[i])
         Union(i,idx);
   for(int i=0;i<edge[idx].size();i++){
      for(int i=1;i<=n;i++)
         sw[i]=false;
      for(int j=0;j<edge[edge[idx][i]].size();j++)
         sw[edge[edge[idx][i]][j]]=true;
      for(int j=1;j<=n;j++)
         if(!sw[j])
            Union(j,edge[idx][i]);
   }
   for(int i=1;i<=n;i++)
      edge[i].clear();
   for(int i=1;i<=n;i++)
      edge[Find(i)].push_back(i);
   for(int i=1;i<=n;i++)
      if(edge[i].size())
         ans++;
   cout<<ans<<endl;
   for(int i=1;i<=n;i++)
      if(edge[i].size()){
         cout<<edge[i].size();
         for(int j=0;j<edge[i].size();j++){
            cout<<' '<<edge[i][j];
         }
         cout<<endl;
      }


}