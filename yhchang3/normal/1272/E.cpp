#include<bits/stdc++.h>
using namespace std;

int a[200010];

int dodd[200010],deven[200010];
vector<int> e[200010];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]+i<=n)
			e[a[i]+i].emplace_back(i);
		if(i-a[i]>=1)
			e[i-a[i]].emplace_back(i);
		dodd[i]=deven[i]=-1;
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(a[i]&1)
			dodd[i]=0,q.emplace(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int it:e[x])
			if(dodd[it]==-1){
				dodd[it]=dodd[x]+1;
				q.emplace(it);
			}
	}
	for(int i=1;i<=n;i++)
		if(!(a[i]&1))
			deven[i]=0,q.emplace(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int it:e[x])
			if(deven[it]==-1){
				deven[it]=deven[x]+1;
				q.emplace(it);
			}
	}
	for(int i=1;i<=n;i++)
		if(a[i]&1)
			cout<<deven[i]<<' ';
		else
			cout<<dodd[i]<<' ';
	cout<<endl;

}