#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)a[i]-=a[i-1];
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=0)ans+=a[i];
	}
	if(a[1]<0)ans+=a[1];
	cout<<((ans+1)>>1)<<endl;
	// for(int i=1;i<=n;i++)cout<<i<<" "<<a[i]<<endl;
	int q;cin>>q;
	while(q--){
		int l,r,x;cin>>l>>r>>x;
		if(a[1]<0)ans-=a[1];
		if(a[l]>=0)ans-=a[l];
		if(r+1<=n&&a[r+1]>=0)ans-=a[r+1];
		a[l]+=x,a[r+1]-=x;
		// cout<<ans<<endl;
		if(a[l]>=0)ans+=a[l];
		if(r+1<=n&&a[r+1]>=0)ans+=a[r+1];
		if(a[1]<0)ans+=a[1];
		cout<<((ans+1)>>1)<<"\n";

		// for(int i=1;i<=n;i++)cout<<i<<" "<<a[i]<<endl;
	}
}