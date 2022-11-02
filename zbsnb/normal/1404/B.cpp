#include<bits/stdc++.h>
using namespace std;
vector<int> e[1000010];
int de[1000010],digm;
int dfs(int u,int fa){
	de[u]=de[fa]+1;
	int ret=0;
	for(auto &v:e[u]){
		if(fa==v) continue;
		int now=dfs(v,u)+1;
		digm=max(digm,ret+now);
		ret=max(ret,now);
	}
	return ret;
}

int main(){
	int t;cin>>t;
	while(t--){
		digm=0;
		int n,a,b,c,d;cin>>n>>a>>b>>c>>d;
		for(int i=1;i<=n;i++) e[i].clear(),de[i]=0;
		for(int i=1;i<n;i++){
			int a,b;cin>>a>>b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		if(d<=2*c) cout<<"Alice"<<endl;
		else{
			vector<int> dep;
			dfs(a,0);
			// cout<<"now:"<<dd<<endl;
			if(digm<=2*c||de[b]-1<=c)cout<<"Alice"<<endl;
			else cout<<"Bob"<<endl;
		}	
	}
}