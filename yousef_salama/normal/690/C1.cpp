#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

vector<int> adj[100100];
int n,m;
bool vis[100100];
void dfs(int nd){
	vis[nd]=true;
	for(int i=0;i<adj[nd].size();i++){
		int ch=adj[nd][i];
		if(!vis[ch]){
			dfs(ch);
		}
	}
}

int main(){
   cin>>n>>m;
   for(int i=0;i<m;i++){
	   int a,b;
	   cin>>a>>b;
	   adj[a].push_back(b);
	   adj[b].push_back(a);
   }
   bool ok=true;
   if(n!=m+1){
	   ok=false;
   }
   dfs(1);
   for(int i=1;i<=n;i++){
	   if(!vis[i]){
		   ok=false;
	   }
   }
   if(ok){
	   cout<<"yes"<<endl;
   } else {
	   cout<<"no"<<endl;
   }
   
}