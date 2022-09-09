#include<bits/stdc++.h>
using namespace std;
int n,I,i,j,a,xb,ans,su;
map<int,int>mp;
pair<int,int>b[400005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>I;I=min(30,I*8/n);I=1<<I;
	for(i=0;i<n;++i)cin>>a,++mp[a];
	for(auto u:mp)b[++xb]=u;
	ans=n;
	for(i=j=1,su=b[i].second;i<=xb;){
		for(;j<xb && j-i+2<=I;su+=b[++j].second);
		ans=min(ans,n-su);su-=b[i++].second;
	}
	cout<<ans<<endl;
	return 0;
}