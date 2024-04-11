#include<bits/stdc++.h>
using namespace std;

vector<int> edge[300001];
vector<pair<int,int> > event[300001];

long long int ans[300001];

long long int bit[300002];

void add(int pos,int val){
	for(int i=pos;i<=300001;i+=i&-i)
		bit[i]+=val;
}

long long int query(int pos){
	long long int res=0;
	for(int i=pos;i>0;i-=i&-i)
		res+=bit[i];
	return res;
}

void dfs(int x,int p,int dep){
	for(auto it:event[x]){
		add(dep,it.second);
		add(dep+it.first+1,-it.second);
	}
	ans[x]=query(dep);
	for(int i:edge[x]){
		if(i==p)	continue;
		dfs(i,x,dep+1);
	}
	for(auto it:event[x]){
		add(dep,-it.second);
		add(dep+it.first+1,it.second);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0,u,v;i<n-1;i++){
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int m;
	cin>>m;
	for(int i=1,v,d,x;i<=m;i++){
		cin>>v>>d>>x;
		event[v].push_back(make_pair(d,x));
	}
	dfs(1,0,1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
	

}