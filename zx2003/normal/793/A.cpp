#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],i,mn=1<<30;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;++i)cin>>a[i],mn=min(mn,a[i]);
	for(i=2;i<=n;++i)if(a[i]%k!=a[1]%k)break;
	if(i<=n){
		cout<<"-1\n";
		return 0;
	}
	long long ans=0;
	for(i=1;i<=n;++i)ans+=(a[i]-mn)/k;
	cout<<ans<<endl;
	return 0;
}