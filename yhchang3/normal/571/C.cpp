#include<bits/stdc++.h>
using namespace std;

#define s second
#define f first
const int maxn=200001;
string ans;

vector<int> pos[maxn][2];
bool vis[maxn],used[maxn];
vector<pair<int,pair<int,int> > > e[maxn];//(to,to_type)
queue<int> q;

bool dfs(int x,int p){
	if(used[x])	return true;
	used[x]=true;
	for(auto &it:e[x])
		if(it.s.s==p)	continue;
		else{
			if(dfs(it.f,it.s.s)){
				ans[it.s.s]=(it.s.f==0?'0':'1');
				q.emplace(x);
				return true;
			}
		}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	ans.assign(m,' ');
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		while(k--){
			int x;
			cin>>x;
			if(x<0)
				pos[-x-1][1].emplace_back(i);
			else
				pos[x-1][0].emplace_back(i);
		}
	}
	for(int i=0;i<m;i++){
		if(pos[i][0].empty()){
			for(int it:pos[i][1])
				q.emplace(it);
			ans[i]='0';
		}
		else if(pos[i][1].empty()){
			for(int it:pos[i][0])
				q.emplace(it);
			ans[i]='1';
		}
		else{
			e[pos[i][1][0]].emplace_back(pos[i][0][0],make_pair(0,i));
			e[pos[i][0][0]].emplace_back(pos[i][1][0],make_pair(1,i));
		}
	}
	for(int i=0;i<n;i++){
		while(!q.empty()){
			int x=q.front();q.pop();
			if(vis[x])	continue;
			vis[x]=true;
			for(auto &it:e[x])
				if(ans[it.s.s]==' '){
					if(it.s.f==0)
						ans[it.s.s]='1';
					else
						ans[it.s.s]='0';
					q.emplace(it.f);
				}
		}
		if(vis[i])	continue;
		if(!dfs(i,-1)){
			cout<<"NO"<<'\n';
			return 0;
		}
	}
	for(auto& it:ans)
		if(it==' ')
			it='0';
	cout<<"YES"<<endl;
	cout<<ans<<endl;
}