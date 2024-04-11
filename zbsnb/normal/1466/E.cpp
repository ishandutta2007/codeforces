#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll a[1000010];
ll sum[110];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=0;i<110;i++) sum[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<60;j++){
				sum[j]=(sum[j]+(a[i]&(1ll<<j)))%mod;
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll sum1=0,sum2=0;
			for(int j=0;j<60;j++){
				if(a[i]&(1ll<<j)){
					sum1=(sum1+sum[j])%mod;
					sum2=(sum2+n*((1ll<<j)%mod))%mod;
				}
				else sum2=(sum2+sum[j])%mod;
			}
			ans=(ans+sum1*sum2)%mod;
		}
		cout<<ans<<"\n";
	}
}