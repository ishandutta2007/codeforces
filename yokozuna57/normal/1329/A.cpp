#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int main(){
	static ll m,n;
	static ll l[100010];
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld",&l[i]);
	}
	
	ll sum=0;
	for(int i=1;i<=m;i++){
		sum+=l[i];
	}
	if(sum<n){
		puts("-1");
		return 0;
	}
	static ll p[100010];
	p[m+1]=n+1;
	for(int i=m;i>=1;i--){
		p[i]=p[i+1]-l[i];
	}
	for(int i=1;i<=m;i++){
		if(i+l[i]-1>n){
			puts("-1");
			return 0;
		}
		chmax(p[i],(ll)i);
	}
	for(int i=1;i<=m;i++){
		printf("%lld%c",p[i],(i==m)?'\n':' ');
	}
}