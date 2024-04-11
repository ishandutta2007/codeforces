#include<bits/stdc++.h>
using namespace std;


typedef long long int ll;

const int mod = 998244353;

ll inv[1000010],p[1000010],cnt[1000010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inv[0]=inv[1]=1;
	for(int i=2;i<=1000000;i++)
		inv[i]=(mod-mod/i*inv[mod%i]%mod)%mod;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1,x;j<=k;j++){
			cin>>x;
			cnt[x]++;
			p[x]=(p[x]+inv[k])%mod;
		}
	}
	ll ans=0;
	for(int i=1;i<=1000000;i++){
		ans=(ans+p[i]*cnt[i])%mod;
	}
	cout<<ans*inv[n]%mod*inv[n]%mod<<endl;
}