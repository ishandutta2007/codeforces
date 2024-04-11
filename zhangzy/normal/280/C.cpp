#include<bits/stdc++.h>
using namespace std;

int n,x,y;
vector<int>G[101000];
double ans;

void dfs(int x,int fff,int dep){
  ans+=1.0/dep;
  for (auto y:G[x]) if (y-fff) dfs(y,x,dep+1);
}

int main(){
  cin>>n;
  for (int i=n;--i;) cin>>x>>y, G[x].push_back(y), G[y].push_back(x);
  dfs(1,0,1);
  printf("%.233lf",ans);
}