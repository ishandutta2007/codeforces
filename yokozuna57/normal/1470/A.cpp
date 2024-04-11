#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
ll k[300010],c[300010];

void solve(){
	sort(k,k+n);
	reverse(k,k+n);
	ll ret=0;
	for(int i=0;i<n;i++){
		if(i<m)ret+=min(c[k[i]],c[i]);
		else ret+=c[k[i]];
	}
	printf("%lld\n",ret);
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%lld",&k[i]);
			k[i]--;
		}
		for(int i=0;i<m;i++)scanf("%lld",&c[i]);
		solve();
	}
}