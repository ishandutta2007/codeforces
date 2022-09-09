#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
int val[N],fa[N],n,i,a[N],q,o,p,x,xb;
map<int,int>mp;
inline void ins(int v){
	auto it=mp.insert(make_pair(v,0)).first;
	if(!it->second)val[it->second=++xb]=v;
}
inline void gfa(int x){
	if(val[x]==-1)gfa(fa[x]),val[x]=val[fa[x]];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;xb=n;
	for(i=1;i<=n;++i){
		cin>>a[i];ins(a[i]);
		fa[i]=mp[a[i]];val[i]=-1;
	}
	for(cin>>q;q--;){
		cin>>o>>p;
		if(o==2){
			ins(p);i=mp[p];
			for(auto it=mp.begin();it!=mp.end() && it->first<p;)
				val[it->second]=-1,fa[it->second]=i,mp.erase(it++);
		}else{			
			cin>>x;
			ins(x);fa[p]=mp[x];
		}
	}
	for(i=1;i<=n;++i){
		gfa(i);
		cout<<val[i]<<' ';
	}
	cout<<endl;
	return 0;
}