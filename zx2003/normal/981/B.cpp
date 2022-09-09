#include<bits/stdc++.h>
using namespace std;
int a,x,b,y,n,m,i;
map<int,int>mp;
long long ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",&a,&x);
		mp[a]=max(mp[a],x);
	}
	scanf("%d",&m);
	for(i=1;i<=m;++i){
		scanf("%d%d",&b,&y);
		mp[b]=max(mp[b],y);
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it)
		ans+=it->second;
	cout<<ans<<endl;
	return 0;
}