#include<bits/stdc++.h>
using namespace std;

int n,m;
int g[1001][1001];

vector<int> ve[1001],vs[1001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>m;
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         cin>>g[i][j];
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++)
         ve[i].push_back(g[i][j]);
      sort(ve[i].begin(),ve[i].end());
      ve[i].resize(unique(ve[i].begin(),ve[i].end())-ve[i].begin());
   }
   for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++)
         vs[i].push_back(g[j][i]);
      sort(vs[i].begin(),vs[i].end());
      vs[i].resize(unique(vs[i].begin(),vs[i].end())-vs[i].begin());
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         int a=lower_bound(ve[i].begin(),ve[i].end(),g[i][j])-ve[i].begin();
         int b=lower_bound(vs[j].begin(),vs[j].end(),g[i][j])-vs[j].begin();
         cout<<max(a,b)+max(ve[i].size()-a,vs[j].size()-b)<<' ';
      }
      cout<<endl;
   }
}