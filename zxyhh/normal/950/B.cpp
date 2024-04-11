#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],ans,n,m;
set<long long> s;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1],s.insert(a[i]);
	for(int i=1;i<=m;i++)cin>>b[i],b[i]+=b[i-1],ans+=s.count(b[i]);
	cout<<ans;
}