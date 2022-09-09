#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,s,a[N],aa[N],g[N],p[N],i,j;
int gfa(int x){return g[x]==x?x:g[x]=gfa(g[x]);}
bool bb[N],vi[N];
set<int>S;
unordered_map<int,int>be,en;
unordered_map<int,vector<int>>mp;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;for(i=1;i<=n;++i)cin>>a[i];
	memcpy(aa+1,a+1,n<<2);sort(aa+1,aa+n+1);
	for(i=1;i<=n;++i){bb[i]=a[i]==aa[i],g[i]=i;if(!bb[i])S.insert(i);}
	int ss=S.size();
	if(ss>s){cout<<-1<<endl;return 0;}
	for(i=1;i<=n;++i)en[aa[i]]=i;for(i=n;i;--i)be[aa[i]]=i;
	for(i=1;i<=n;++i)if(!bb[i])p[i]=*S.lower_bound(be[a[i]]),S.erase(p[i]),g[gfa(p[i])]=gfa(i);
	for(i=1;i<=n;++i)if(!bb[i])mp[a[i]].push_back(i);else p[i]=i;
	for(auto u:mp){
		auto v=u.second;
		for(i=1;i<v.size();++i)if(gfa(v[i])!=gfa(v[0]))
			g[gfa(v[i])]=gfa(v[0]),swap(p[v[i]],p[v[0]]);
	}
	vector<vector<int>>ans;
	for(i=1;i<=n;++i)if(p[i]!=i && !vi[i]){
		vector<int>ve;
		for(j=i;vi[j]=1,ve.push_back(j),p[j]!=i;j=p[j]);
		ans.push_back(ve);
	}
	if(ss+3<=s && ans.size()>1){
		vector<int>v1,v2,v3;
		for(i=1;ss+i<=s && !ans.empty();++i){
			v3=ans.back();ans.pop_back();
			v1.insert(v1.end(),v3.begin(),v3.end());
			v2.push_back(v3[0]);
		}
		reverse(v2.begin(),v2.end());
		ans.push_back(v1);ans.push_back(v2);
	}
	cout<<ans.size()<<'\n';
	for(auto u:ans){cout<<u.size()<<'\n';for(int x:u)cout<<x<<' ';cout<<'\n';}
	return 0;
}