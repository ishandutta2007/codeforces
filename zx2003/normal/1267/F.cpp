#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ka,kb,a[N],b[N],i,d[N],pa,pb;
priority_queue<int,vector<int>,greater<int>>qa,qb;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>ka>>kb;
	if(ka>m-1 || kb>n-1){cout<<"No\n";return 0;}
	cout<<"Yes\n";
	for(i=1;i<=ka;++i)cin>>a[i];for(i=1;i<=kb;++i)cin>>b[i];
	for(;ka<m-1;)a[++ka]=1;for(;kb<n-1;)b[++kb]=n+1;
	for(i=1;i<=m-1;++i)++d[a[i]];for(i=1;i<=n-1;++i)++d[b[i]];
	for(i=1;i<=n+m;++i)if(!d[i])(i<=n?qa:qb).push(i);
	for(i=1;i<=n+m-2;++i)if(!qa.empty()){
		cout<<qa.top()<<' '<<b[++pb]<<'\n';qa.pop();
		if(!--d[b[pb]])qb.push(b[pb]);
	}else{
		cout<<qb.top()<<' '<<a[++pa]<<'\n';qb.pop();
		if(!--d[a[pa]])qa.push(a[pa]);
	}
	cout<<qa.top()<<' '<<qb.top()<<'\n';
	return 0;
}