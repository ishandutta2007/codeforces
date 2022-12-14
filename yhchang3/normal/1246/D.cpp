#include<bits/stdc++.h>
using namespace std;

vector<int> e[100000];

int l[100000];

void dfs(int x){
	for(int it:e[x]){
		dfs(it);
		l[x]=max(l[x],l[it]);
	}
	l[x]++;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1,p;i<n;i++){
		cin>>p;
		e[p].emplace_back(i);
	}
	dfs(0);
	for(int j=0;j<n;j++)
		for(int i=0;i<e[j].size();i++)
			if(l[e[j][i]]>l[e[j].back()])
				swap(e[j][i],e[j].back());
	int x=0;
	vector<int> ans;
	while(!e[x].empty()){
		cout<<x<<' ';
		for(int i=e[x].size()-1;i-1>=0;i--){
			ans.emplace_back(e[x][i]);
			e[e[x][i-1]].emplace_back(e[x][i]);
		}
		x=e[x][0];
	}
	cout<<x<<'\n';
	cout<<ans.size()<<'\n';
	for(int i=(int) ans.size()-1;i>=0;i--)
		cout<<ans[i]<<' ';
	cout<<'\n';
}