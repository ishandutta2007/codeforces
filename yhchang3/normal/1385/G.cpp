#include<bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int to[maxn<<1];
bool vis[maxn<<1];
vector<int> pos[maxn];

void dfs(int x,vector<int> &flip,vector<int> &noflip){
	if(x&1)	noflip.emplace_back(x>>1);
	else	flip.emplace_back(x>>1);
	vis[x]=true;
	if(!vis[to[x]^1])	dfs(to[x]^1,flip,noflip);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=0;i<2*n;i++)	vis[i]=false;
		for(int i=1;i<=n;i++)	pos[i].clear();
		for(int i=0,x;i<2;i++)
			for(int j=0;j<n;j++){
				cin>>x;
				pos[x].emplace_back(j*2+i);
			}
		bool fail = false;
		for(int i=1;i<=n;i++){
			if(pos[i].size()!=2){
				fail = true;
				break;
			}
			to[pos[i][0]]=pos[i][1];
			to[pos[i][1]]=pos[i][0];
		}
		if(fail){
			cout<<-1<<'\n';
			continue;
		}
		vector<int> ans;
		for(int i=0;i<n;i++){
			if(vis[i<<1]||vis[i<<1|1])	continue;
			vector<int> noflip,flip;
			dfs(i<<1,noflip,flip);
			if(noflip.size()<flip.size()){
				for(int x:noflip)
					ans.emplace_back(x);
			}
			else{
				for(int x:flip)
					ans.emplace_back(x);
			}
		}
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<'\n';
		for(int x:ans)
			cout<<x+1<<' ';
		cout<<'\n';
	}
}