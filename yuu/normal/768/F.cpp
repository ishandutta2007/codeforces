#include <bits/stdc++.h>
using namespace std;
int a, b, h;
using ll=long long;
const ll base=1000000007;
ll f[200001];
ll r[200001];
ll power(ll x, ll y){
	if(y==0) return 1;
	ll t=power(x, y/2);
	t=(t*t)%base;
	if(y%2) t=(t*x)%base;
	return t;
}
ll C(int n, int k){
	if(n<k) return 0;
	return ((f[n]*r[k])%base*r[n-k])%base;
}
ll candy(int n, int k){
	if(n<0) return 0;
	if(k==0) return n==0;
	return C(n+k-1, k-1);
}
int main(){
	f[0]=1;
	for(int i=1; i<=200000; i++) f[i]=(f[i-1]*i)%base;
	r[200000]=power(f[200000], base-2);
	for(int i=200000; i>=1; i--) r[i-1]=(r[i]*i)%base;
	cin>>a>>b>>h;
	if(b==0){
		cout<<1<<'\n';
		return 0;
	}
	h++;
	ll arrspace=0;
	ll solspace=0;
	///number of base for a=b
	for(int i=1; (i<=a)&&(i<=b); i++){
		arrspace=(arrspace+candy(a-i, i)*candy(b-i, i)*2)%base;
		if(((ll)i)*h<=b) solspace=(solspace+candy(a-i, i)*candy(b-i*h, i)*2)%base;
	}
	///number of base for a=b+1
	for(int i=2; (i<=a)&&(i-1<=b); i++){
		arrspace=(arrspace+candy(a-i, i)*candy(b-i+1, i-1))%base;
		if(((ll)i-1)*h<=b) solspace=(solspace+candy(a-i, i)*candy(b-(i-1)*h, i-1))%base;
	}
	///number of base for a+1=b
	for(int i=0; (i<=a)&&(i+1<=b); i++){
		// cerr<<candy(a-i, i)<<' '<<candy(b-i-1, i+1)<<'\n';
		arrspace=(arrspace+candy(a-i, i)*candy(b-i-1, i+1))%base;
		if(((ll)i+1)*h<=b) solspace=(solspace+candy(a-i, i)*candy(b-(i+1)*h, i+1))%base;
	}
	cerr<<arrspace<<' '<<solspace<<'\n';
	cout<<(solspace*power(arrspace, base-2))%base<<'\n';
}