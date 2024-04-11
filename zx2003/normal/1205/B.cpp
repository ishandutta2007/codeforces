#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,i,j,k,ans=-1,d[N];
long long a[N];
vector<int>e[N],v[65];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)for(cin>>a[i],j=0;j<60;++j)if(a[i]>>j&1)v[j].push_back(i);
	for(i=0;i<60;++i)if(v[i].size()>2)break;if(i<60){cout<<"3\n";return 0;}
	for(i=0;i<60;++i)sort(v[i].begin(),v[i].end());
	for(i=0;i<60;++i)if(v[i].size()==2)for(k=i+1;k<60;++k)if(v[k]==v[i])v[k].clear();
	for(i=0;i<60;++i)if(v[i].size()==2){
		for(k=1;k<=n;++k)e[k].clear();
		for(k=0;k<60;++k)if(k!=i && v[k].size()==2)e[v[k][0]].push_back(v[k][1]),
			e[v[k][1]].push_back(v[k][0]);
		queue<int>q;q.push(v[i][0]);
		memset(d+1,-1,n<<2);d[v[i][0]]=1;
		for(;!q.empty();){
			int u=q.front();q.pop();
			for(int v:e[u])if(d[v]==-1)d[v]=d[u]+1,q.push(v);
		}
		if(d[v[i][1]]!=-1 && (ans==-1 || ans>d[v[i][1]]))ans=d[v[i][1]];
	}
	cout<<ans<<'\n';
}