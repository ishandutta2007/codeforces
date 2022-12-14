#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > e[100001];
vector<int> ans;
int dfn[100001],low[100001],cnt,u[100001],v[100001];
stack<int> st;
void dfs(int x,int p,int id){
	dfn[x]=low[x]=++cnt;
	for(auto &[to,i]:e[x]){
		if(to==p)	continue;
		if(!dfn[to]){
			st.emplace(i);
			dfs(to,x,i);
			low[x]=min(low[x],low[to]);
			if(low[to]==dfn[x]){
				vector<int> tmp;
				set<int> s;
				while(true){
					int x=st.top();
					st.pop();
					tmp.emplace_back(x);
					s.insert(u[x]);
					s.insert(v[x]);
					if(x==i)	break;
				}
				if(s.size()==tmp.size())
					for(int it:tmp)
						ans.emplace_back(it);
			}
		}
		else if(dfn[to]<dfn[x]){
			st.emplace(i);
			low[x]=min(low[x],dfn[to]);
		}
	}
	if(st.size()&&st.top()==id)	st.pop();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
		e[u[i]].emplace_back(v[i],i);
		e[v[i]].emplace_back(u[i],i);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i,0,0);
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(int it:ans)
		cout<<it<<' ';
	cout<<endl;
}