#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1000000007;
ll POW[62];
void init(){
	POW[0]=1;
	for(int i=1;i<62;i++){
		POW[i]=POW[i-1]*2;
		if(POW[i]>=MOD)POW[i]-=MOD;
	}
}

ll n;
ll a[500010];

void solve(){
	ll cnt[62]={};
	for(int i=0;i<n;i++){
		for(int j=0;j<60;j++){
			if((a[i]>>j)&1LL)cnt[j]++;
		}
	}
	ll ret=0;
	for(int i=0;i<n;i++){
		ll sum[2]={};
		for(int j=0;j<60;j++){
			if((a[i]>>j)&1LL){
				sum[0]+=POW[j]*cnt[j];
				sum[0]%=MOD;
			}
		}
		for(int j=0;j<60;j++){
			if((a[i]>>j)&1LL){
				sum[1]+=POW[j]*n;
				sum[1]%=MOD;
			}
			else {
				sum[1]+=POW[j]*cnt[j];
				sum[1]%=MOD;
			}
		}
		ret+=sum[0]*sum[1];
		ret%=MOD;
	}
	printf("%lld\n",ret);
}

int main(){
	init();
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%lld",&n);
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		solve();
	}
}