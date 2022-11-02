#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> > e[300010];
int vis[300010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=1;i<=3*n;i++) e[i].clear(),vis[i]=0;
		for(int i=1;i<=m;i++){
			int a,b;cin>>a>>b;
			if(a>b)swap(a,b);
			e[a].insert({b,i});
		}
		vector<int> ansp,anse;

		int u=1;
		while(anse.size()<n){
			while(u<=3*n){
				int flg=0;
				if(!vis[u]){
					for(auto &it:e[u]){
						if(!vis[it.first]){
							flg=1;
							break;
						}
					}
					if(flg)break;
					ansp.push_back(u);
				}
				u++;
			}
			// cout<<i<<" "<<u<<endl;

			if(ansp.size()>=n||u==3*n+1) break;

			for(auto &it:e[u]){
				// cout<<"??"<<u<<" "<<it.first<<" "<<it.second<<endl;
				if(vis[it.first]) continue;
				vis[it.first]=1;
				anse.push_back(it.second);
				break;
			}
			u++;
		}
		if(ansp.size()>=n){
			cout<<"IndSet"<<endl;
			for(int i=0;i<n;i++) cout<<ansp[i]<<" ";cout<<endl;
		}
		else if(anse.size()>=n){
			cout<<"Matching"<<endl;
			for(int i=0;i<n;i++) cout<<anse[i]<<" ";cout<<endl;
		}
		else cout<<"Impossible"<<endl;
	}

}