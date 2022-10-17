#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=998244353;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int dig(ll n){
	int ret=0;
	while(n>0){
		ret+=n&1LL;
		n>>=1;
	}
	return ret;
}

ll modpow(ll x,ll k){
	if(k==0)return 1;
	ll ret=modpow(x,k/2);
	ret*=ret; ret%=MOD;
	if(k%2==1){
		ret*=x; ret%=MOD;
	}
	return ret;
}

ll SWAP(ll n,ll i,ll j){
	if(((n>>i)&1LL)!=((n>>j)&1LL)){
		n^=(1LL<<i)+(1LL<<j);
	}
	return n;
}

int main(){
	static ll n,m;
	static ll a[200010];
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	
	vector<int> ind;
	int cnt=0;
	for(int i=0;i<m;i++){
		for(int j=cnt;j<n;j++){
			if((a[j]>>i)&1LL){
				if(j>cnt)swap(a[j],a[cnt]);
				break;
			}
		}
		if(((a[cnt]>>i)&1LL)==0)continue;
		for(int j=0;j<n;j++){
			if(j==cnt)continue;
			if((a[j]>>i)&1LL)a[j]^=a[cnt];
		}
		ind.push_back(i);
		cnt++;
	}
	
	ll ret[60]={};
	if(cnt<=20){
		for(int i=0;i<(1LL<<cnt);i++){
			ll sum=0;
			for(int j=0;j<cnt;j++){
				if((i>>j)&1LL)sum^=a[j];
			}
			ret[dig(sum)]++;
		}
	}
	else {
		int n_=m;
		for(int i=(int)(ind.size())-1;i>=0;i--){
			n_--;
			for(int j=0;j<cnt;j++){
				if(ind[i]!=n_)a[j]=SWAP(a[j],ind[i],n_);
			}
		}
		for(int j=0;j<cnt;j++){
			a[j]&=(1LL<<n_)-1;
		}
		static ll dp[40][1<<15]={};
		dp[0][0]=1;
		for(int i=0;i<cnt;i++){
			for(int j=i;j>=0;j--){
				for(int k=0;k<(1LL<<n_);k++){
					dp[j+1][k^a[i]]+=dp[j][k];
					if(dp[j+1][k^a[i]]>=MOD)dp[j+1][k^a[i]]-=MOD;
				}
			}
		}
		for(int j=0;j<(1LL<<n_);j++){
			int d=dig(j);
			for(int i=0;i<=cnt;i++){
				ret[i+d]+=dp[i][j];
				if(ret[i+d]>=MOD)ret[i+d]-=MOD;
			}
		}
	}
	for(int i=0;i<=m;i++){
		ret[i]*=modpow(2,n-cnt);
		ret[i]%=MOD;
		printf("%lld%c",ret[i],(i==m)?'\n':' ');
	}
}