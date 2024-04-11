#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
int ask(ll l,ll r){
	char ret[10];
	printf("%lld %lld\n",l,r);
	fflush(stdout);
	scanf("%s",ret);
	if(ret[0]=='Y'&&l==r)exit(0);
	return ret[0]=='Y';
}
int main(){
	srand(time(0));
	scanf("%lld%lld",&n,&k);
	ll l=1,r=n;
	while(1){
		if(r-l+1>6*k){
			ll mid=l+r>>1;
			if(ask(l,mid))l=max(1ll,l-k),r=min(n,mid+k);
			else l=max(1ll,mid+1-k),r=min(n,r+k);	
		} else {
			ll p=l+rand()%(r-l+1);
			ask(p,p);
			l=max(1ll,l-k),r=min(n,r+k);
		}
		
	}
	
}