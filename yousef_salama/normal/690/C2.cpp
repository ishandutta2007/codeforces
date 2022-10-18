#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

vector<int> adj[100100];

int n,m;

int dist[100100];
void dfs(int nd,int p,int d){
	dist[nd]=max(dist[nd],d);
	for(int i=0;i<adj[nd].size();i++){
		int ch=adj[nd][i];
		if(ch==p)continue;
		dfs(ch,nd,d+1);
	}
}
int main(){
	cin.sync_with_stdio(false);
   cin>>n>>m;
   for(int i=0;i<m;i++){
	   int a,b;
	   cin>>a>>b;
	   adj[a].push_back(b);
	   adj[b].push_back(a);
   }
   dfs(1,1,0);
   int nd=1;
   for(int i=2;i<=n;i++){
	   if(dist[nd]<dist[i]){
		   nd=i;
	   }
   }
   dfs(nd,nd,0);
   int mx=0;
   for(int i=1;i<=n;i++){
	   mx=max(dist[i],mx);
   }
   cout<<mx<<endl;
}