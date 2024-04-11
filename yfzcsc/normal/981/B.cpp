#include<bits/stdc++.h>
using namespace std;
map<int,int>st;
long long ans;
int n,m;
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i)
		scanf("%d%d",&x,&y),st[x]=max(st[x],y);
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i)
		scanf("%d%d",&x,&y),st[x]=max(st[x],y);
	for(auto p:st)ans+=p.second;
	printf("%lld\n",ans);
}