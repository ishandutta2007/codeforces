#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,a[200005];
map<ll,ll> mp;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	mp.insert(pair<ll,ll>(a[1],0));
	map<ll,ll>::iterator j;
	for (int i=1;i<n;i++)
		for (j=mp.upper_bound(a[i+1]);j!=mp.end();){
			long long &f0=mp[a[i+1]];
			f0=max(f0,j->second+(j->first/a[i+1]-1)*a[i+1]*i);
			if (j->first%a[i+1]){
				long long &f1=mp[j->first%a[i+1]];
				f1=max(f1,j->second+j->first/a[i+1]*a[i+1]*i);
			}
			mp.erase(j);
			j=mp.upper_bound(a[i+1]);
		}
	for (j=mp.begin();j!=mp.end();j++)
		ans=max(ans,(j->first-1)*n+j->second);
	printf("%I64d",ans);
}