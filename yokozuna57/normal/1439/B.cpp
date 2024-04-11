#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,m,k;
set<int> G[200010];

void solve(){
	if(k>=1000||k*(k-1)>2*m){
		puts("-1");
		return;
	}
	queue<int> que;
	for(int i=0;i<n;i++){
		if(G[i].size()<=k-2)que.push(i);
	}
	while(!que.empty()){
		int v=que.front(); que.pop();
		for(int u: G[v]){
			G[u].erase(v);
			if(G[u].size()==k-2)que.push(u);
		}
		G[v].clear();
	}
	for(int i=0;i<n;i++){
		if(G[i].size()<=k-1)que.push(i);
	}
	vector<pair<int,int>> ng;
	while(!que.empty()){
		int v=que.front(); que.pop();
		if(G[v].size()==k-1){
			bool ok=true;
			for(auto p: ng){
				if(G[v].find(p.fr)!=G[v].end()&&G[v].find(p.sc)!=G[v].end()){
					ok=false;
					break;
				}
			}
			if(ok){
				for(auto itr1=G[v].begin();itr1!=G[v].end();itr1++){
					for(auto itr2=itr1;itr2!=G[v].end();itr2++){
						if(itr2==itr1)continue;
						if(G[*itr1].find(*itr2)==G[*itr1].end()){
							ok=false;
							if(ng.size()<=100)ng.push_back(mp(*itr1,*itr2));
							break;
						}
					}
					if(!ok)break;
				}
			}
			if(ok){
				puts("2");
				for(int x: G[v]){
					printf("%d ",x+1);
				}
				printf("%d\n",v+1);
				return;
			}
		}
		for(int u: G[v]){
			G[u].erase(v);
			if(G[u].size()==k-1)que.push(u);
		}
		G[v].clear();
	}
	vector<int> ret;
	for(int i=0;i<n;i++){
		if(G[i].size()>0)ret.push_back(i);
	}
	if(ret.size()>0){
		printf("1 %d\n",(int)ret.size());
		for(int i=0;i<ret.size();i++){
			printf("%d%c",ret[i]+1,(i+1==ret.size())?'\n':' ');
		}
	}
	else puts("-1");
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<n;i++)G[i].clear();
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a--; b--;
			G[a].insert(b);
			G[b].insert(a);
		}
		solve();
	}
}