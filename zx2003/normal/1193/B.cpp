#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
map<int,ll>mpp[N],*mp[N];
int n,m,k,p[N],d[N],w[N],i,v;
ll ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(i=2;i<=n;++i)cin>>p[i];for(i=1;i<=n;++i)mp[i]=mpp+i;
	for(;m--;)cin>>v,cin>>d[v]>>w[v];
	for(i=n;i>1;--i){
		if(d[i]){
			auto it=mp[i]->insert(make_pair(d[i],0)).first;
			it->second+=v=w[i];
			for(++it;it!=mp[i]->end() && v>=it->second;v-=it->second,mp[i]->erase(it++));
			if(it!=mp[i]->end())it->second-=v;
		}
		if(mp[i]->size()>mp[p[i]]->size())
			swap(mp[i],mp[p[i]]);
		for(auto u:*mp[i]){
			auto it=mp[p[i]]->insert(make_pair(u.first,0)).first;
			it->second+=u.second;
		}
	}
	for(auto u:*mp[1])ans+=u.second;cout<<ans<<endl;
	return 0;
}