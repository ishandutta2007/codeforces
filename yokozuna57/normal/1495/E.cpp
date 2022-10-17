#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

const ll MOD=1000000007;

ll seed=0;
ll base=0;

ll rnd(){
	ll ret=seed;
	seed=(seed*base+233)%MOD;
	return ret;
}

int n;
ll a[5000010],t[5000010];
ll ans[5000010];

int main(){
	scanf("%d",&n);
	int m,pre=0;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int p,k,b,w;
		scanf("%d%d%d%d",&p,&k,&b,&w);
		seed=b;
		base=w;
		for(int j=pre;j<p;j++){
			t[j]=rnd()%2;
			a[j]=rnd()%k+1;
		}
		pre=p;
	}
	
	/*for(int i=0;i<n;i++){
		printf("%lld ",a[i]);
	}printf("\n");
	for(int i=0;i<n;i++){
		printf("%lld ",t[i]);
	}printf("\n");*/
	
	ll sum[2]={};
	for(int i=0;i<n;i++){
		sum[t[i]]+=a[i];
	}
	
	for(int i=0;i<n;i++){
		ans[i]=a[i];
	}
	
	int l=0;
	if(sum[t[0]]>sum[1-t[0]]){
		l=1-t[0]; a[0]--;
	}
	else l=t[0];
	
	ll cnt=0;
	for(int i=0;i<n;i++){
		if(t[i]==l){
			cnt+=a[i];
			a[i]=0;
		}
		else {
			ll x=min(cnt,a[i]);
			cnt-=x;
			a[i]-=x;
		}
	}
	for(int i=0;i<n;i++){
		if(t[i]==l){
			cnt+=a[i];
			a[i]=0;
		}
		else {
			ll x=min(cnt,a[i]);
			cnt-=x;
			a[i]-=x;
		}
	}
	for(int i=0;i<n;i++){
		if(t[i]==l){
			cnt+=a[i];
			a[i]=0;
		}
		else {
			ll x=min(cnt,a[i]);
			cnt-=x;
			a[i]-=x;
		}
	}
	ll ret=1;
	for(ll i=0;i<n;i++){
		ll ret_=((ans[i]-a[i])^((i+1)*(i+1)))+1;
		ret_%=MOD;
		ret*=ret_;
		ret%=MOD;
	}
	cout<<ret<<endl;
}