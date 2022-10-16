#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll base=1000000007;
int n;
ll p2[1000000];
class reimu{
public:
	ll sum, sum2;
	int	sz;
	ll ans=0;
	void operator +=(reimu x){
		(sum2+=x.sum2)%=base;
		(sum+=x.sum)%=base;
		sz+=x.sz;
	}
	void operator -=(reimu x){
		(sum2-=x.sum2)%=base;
		(sum-=x.sum)%=base;
		sz-=x.sz;
	}
	void cal(){
		(ans=sum2*p2[sz-1]+((sz==1)?0:((sum*sum-sum2)%base)*p2[sz-2]))%=base;
	}
} f[1000000];
ll pre[64];
int main(){
	p2[0]=1;
	for(int i=1; i<1000000; i++) (p2[i]=p2[i-1]*2)%=base;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0; i<64; i++){
		for(int d=0, p10=1; d<6; d++, p10*=10) if(i&(1<<d)){
			pre[i]+=p10;
		}
	}
	for(int i=0; i<n; i++){
		ll a;
		cin>>a;
		reimu temp;
		temp.sum=a;
		(temp.sum2=a*a)%=base;
		temp.sz=1;
		f[a]+=temp;
	}
	for(int x=999999; x>=0; x--){
		int mask=0;
		for(int d=0, p10=1; d<6; d++, p10*=10){
			if((x/p10)%10!=9) mask|=1<<d;
		}
		for(int sub=mask; sub; (sub-=1)&=mask){
			if(__builtin_popcount(sub)%2==1) f[x]+=f[x+pre[sub]];
			else f[x]-=f[x+pre[sub]];
		}
	}
	for(int i=0; i<=999999; i++) f[i].cal();
	ll ans=0;
	for(int x=0; x<=999999; x++){
		int mask=0;
		for(int d=0, p10=1; d<6; d++, p10*=10){
			if((x/p10)%10!=9) mask|=1<<d;
		}
		ll res=f[x].ans;
		for(int sub=mask; sub; (sub-=1)&=mask){
			if(__builtin_popcount(sub)%2==0) res+=f[x+pre[sub]].ans;
			else res-=f[x+pre[sub]].ans;
		}
		((res%=base)+=base)%=base;
		(res*=x);
		ans^=res;
	}
	cout<<ans<<'\n';
}