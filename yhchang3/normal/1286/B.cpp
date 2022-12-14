#include<bits/stdc++.h>
using namespace std;

int c[2001];
vector<int> e[2001];

bool ok=true;
int sz[2001];

void check(int x){
	sz[x]=1;
	for(int it:e[x]){
		check(it);
		sz[x]+=sz[it];
	}
	if(sz[x]-1<c[x])	ok=false;
}
int ans[2001];
void dfs(int x,vector<int> v){
	int p=0;
	ans[x]=v[c[x]];
	v[c[x]]=-1;
	for(int it:e[x]){
		vector<int> nxt;
		int cnt=sz[it];
		while(cnt){
			if(v[p]==-1){
				p++;
				continue;
			}
			cnt--;
			nxt.emplace_back(v[p++]);
		}
		dfs(it,nxt);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int root;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p>>c[i];
		if(p==0)	root=i;
		else	e[p].emplace_back(i);
	}
	check(root);
	if(!ok){
		cout<<"NO"<<endl;
		return 0;
	}
	vector<int> v(n);
	for(int i=0;i<n;i++)
		v[i]=i+1;
	dfs(root,v);
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
}