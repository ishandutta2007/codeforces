#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> e[500010];
map<pair<int,int>,int> mp;
pair<int,int> ein[500010];
vector<pair<pair<int,int>,int> > e_o[500010];
int c[500010];
int col[500010];
int g[500010];
int dfs(int u,int fa,int co,int gg){
	col[u]=co,g[u]=gg;
	int ret=0;
	for(auto &v:e[u]){
		if(c[v]!=c[u]) continue;
		if(col[v]){
			if(col[v]!=3-co) ret=1;
			continue;
		}
		if(dfs(v,u,3-co,gg)) ret=1;
	}
	return ret;
}
int col2[500010];
vector<pair<int,int> > e2[500010];
int dfs2(int u,int fa,int co){
	col2[u]=co;
	int ret=0;
	for(auto it:e2[u]){
		int v=it.first,w=it.second;
		int co2=1+((co-1)^w);
		if(col2[v]){
			if(col2[v]!=co2) ret=1;
			continue;
		}
		if(dfs2(v,u,co2)) ret=1;
	}
	return ret;
}
set<int> s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=m;i++){
		int a,b;cin>>a>>b;
		ein[i]={a,b};
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		if(!col[i]){
			if(dfs(i,0,1,++tot)){
				if(!s.count(c[i])) k--;
				s.insert(c[i]);
			}
		}
	}
	ll ans=1ll*k*(k-1)/2;
	// cout<<ans<<endl;
	tot=0;
	for(int i=1;i<=m;i++){
		int a=ein[i].first,b=ein[i].second;
		int ca=c[a],cb=c[b];
		if(ca==cb) continue;
		if(s.count(ca)||s.count(cb)) continue;
		// cout<<a<<" "<<b<<" "<<ca<<" "<<cb<<endl;
		if(ca>cb)swap(ca,cb);
		int tmp=mp[{ca,cb}];
		if(tmp){
			e_o[tmp].push_back({{g[a],g[b]},col[a]==col[b]});
		}
		else{
			mp[{ca,cb}]=++tot;
			e_o[tot].push_back({{g[a],g[b]},col[a]==col[b]});
		}
		// cout<<ca<<" "<<cb<<" "<<g[a]<<" "<<g[b]<<endl;
	}
	for(int i=1;i<=tot;i++){
		auto vec=e_o[i];
		vector<int> node;
		for(auto it2:vec){
			e2[it2.first.first].push_back({it2.first.second,it2.second});
			e2[it2.first.second].push_back({it2.first.first,it2.second});
			node.push_back(it2.first.first);
			node.push_back(it2.first.second);
		}
		
		// for(auto &it2:node){
		// 	cout<<it2<<" ";
		// }
		// cout<<endl;

		for(auto &it2:node){
			col2[it2]=0;
		}
		int flg=0;
		for(auto &it2:node){
			if(!col2[it2]){
				if(dfs2(it2,0,1)){
					flg=1;
					break;
				}
			}
		}
		ans-=flg;
		for(auto &it2:node){
			e2[it2].clear();
		}
	}
	cout<<ans<<endl;
}