#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		ll n;
		scanf("%lld",&n);
		
		ll cnt[32];
		cnt[1]=1;
		for(int i=2;i<=30;i++){
			cnt[i]=cnt[i-1]*4;
		}
		ll sum=0;
		ll k=1;
		while(1){
			sum+=cnt[k];
			if((n+2)/3<=sum)break;
			k++;
		}
		ll a[32];
		a[k]=n%3; if(a[k]==0)a[k]=3;
		if(k>=2){
			ll x=(n+2)/3-(sum-cnt[k]);
			x --;
			for(int i=1;i<=k-1;i++){
				a[i]=x%4;
				x/=4;
			}
		}
		if(a[k]==2){
			for(int i=1;i<=k-1;i++){
				if(a[i]==1)a[i]=2;
				else if(a[i]==2)a[i]=3;
				else if(a[i]==3)a[i]=1;
			}
		}
		if(a[k]==3){
			for(int i=1;i<=k-1;i++){
				if(a[i]==1)a[i]=3;
				else if(a[i]==2)a[i]=1;
				else if(a[i]==3)a[i]=2;
			}
		}
		ll ret=0;
		for(int i=1;i<=k;i++){
			ret+=a[i]*cnt[i];
		}
		printf("%lld\n",ret);
	}
}