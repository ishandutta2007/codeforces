#include <bits/stdc++.h>
using namespace std;
const int base=1000000007;
long long f[200001];
long long iv[200001];
int n, l, r;
long long power(long long a, long long x){
	if(x==0) return 1;
	long long t=power(a, x/2);
	(t*=t)%=base;
	if(x%2) (t*=a)%=base;
	return t;
}
long long C(int n, int k){
	if(k==0) return 1;
	if(k>n) return 0;
	return ((f[n]*iv[k])%base*iv[n-k])%base;
}
int calculate(int plus, int minus){
	long long ans=0;
	for(int first_minus=1; first_minus<=n; first_minus++){
		if(first_minus-1>plus) break;
		int bound=first_minus-l;
		if(bound<1) continue;
		int last_last_plus=min(r-bound, n);
		if(last_last_plus<first_minus-1) continue;
		int first_last_plus=plus;
		if(first_last_plus==first_minus) first_last_plus++;
		if(first_last_plus>last_last_plus) continue;
		//place first_last_plus-first_minus plus inside the range
		(ans+=C(last_last_plus-first_minus, plus-(first_minus-1))*bound)%=base;
	}
	for(int last_plus=n; last_plus>=1; last_plus--){
		if(n-last_plus>minus) break;
		int bound=r-last_plus;
		if(bound<1) continue;
		int first_first_minus=max(1, bound+l+1);
		if(first_first_minus>last_plus+1) continue;
		int last_first_minus=n-minus+1;
		if(last_first_minus==last_plus) last_first_minus--;
		if(first_first_minus>last_first_minus) continue;
		(ans+=C(last_plus-first_first_minus, minus-(n-last_plus))*bound)%=base;
	}
	return ans;
}
void solve(){
	cin>>n>>l>>r;
	int ans=0;
	if(n%2){
		ans=(calculate(n/2, n/2+1)+calculate(n/2+1, n/2))%base;
	}
	else ans=calculate(n/2, n/2);
	cout<<ans<<'\n';
}
int main(){
	f[0]=1;
	for(int i=1; i<=200000; i++) f[i]=(f[i-1]*i)%base;
	iv[200000]=power(f[200000], base-2);
	for(int i=200000; i>=1; i--) iv[i-1]=(iv[i]*i)%base;
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}