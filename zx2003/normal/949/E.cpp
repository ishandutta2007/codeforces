#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,i;
vector<int>ans,a,b;
void solve(vector<int>v,int d){
	if(d>262144)return;
	int i=0;sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
	for(;i<v.size();++i)if(!v[i])v.erase(v.begin()+i);
	if(v.empty()){
		if(ans.empty() || a.size()<ans.size())ans=a;
		return;
	}
	for(i=0;i<v.size();++i)if(v[i]&1)break;
	if(i==v.size()){
		for(i=0;i<v.size();++i)v[i]>>=1;solve(v,d<<1);
	}else{
		vector<int>vv=v;a.push_back(d);
		for(i=0;i<v.size();++i)
			if(vv[i]&1)vv[i]=(vv[i]-1)>>1;
				else vv[i]>>=1;
		solve(vv,d<<1);
		if(d==1){
			++d,--d;
		}
		a.back()=-d;
		vv=v;
		for(i=0;i<v.size();++i)
			if(vv[i]&1)vv[i]=(vv[i]+1)>>1;
				else vv[i]>>=1;
		solve(vv,d<<1);a.pop_back();
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(b.resize(n),i=0;i<n;++i)cin>>b[i];
	solve(b,1);cout<<ans.size()<<'\n';
	for(i=0;i<ans.size();++i)cout<<ans[i]<<' ';
	return 0;
}