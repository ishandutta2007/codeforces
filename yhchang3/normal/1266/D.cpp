#include<bits/stdc++.h>
using namespace std;

long long int b[300001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		long long int w;
		cin>>u>>v>>w;
		b[u]+=w;
		b[v]-=w;
	}
	vector<long long int> ans;
	queue<int> q0,q1;
	for(int i=1;i<=n;i++)
		if(b[i]>0)
			q0.emplace(i);
		else if(b[i]<0)
			q1.emplace(i);
	while(!q0.empty()){
		int i=q0.front();q0.pop();
		while(b[i]!=0){
			int j=q1.front();
			long long int x=min(abs(b[j]),b[i]);
			b[i]-=x;
			b[j]+=x;
			ans.emplace_back(i);
			ans.emplace_back(j);
			ans.emplace_back(x);
			if(b[j]==0)	q1.pop();
		}
	}
	cout<<ans.size()/3<<'\n';
	for(int i=0;i<ans.size();i+=3)
		cout<<ans[i]<<' '<<ans[i+1]<<' '<<ans[i+2]<<'\n';
}