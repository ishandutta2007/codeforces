#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int b[200001];
using ll=long long;
const ll base=1000000007;
ll power(ll a, ll b){
	if(b==0) return 1;
	ll t=power(a, b/2);
	t=(t*t)%base;
	if(b%2) t=(t*a)%base;
	return t;
}
ll fact[200001];
ll rev[200001];
ll C(int n, int k){
	return ((fact[n]*rev[k])%base*rev[n-k])%base;
}
vector <int> f(vector <vector <int>> x){
	vector <vector <int>>temp;
	int sign=1;
	while(x.size()>1){
		// cerr<<x.size()<<'\n';
		temp.clear();
		for(int i=1; i<x.size(); i++){
			temp.push_back(x[i-1]);
			for(int j=0; j<x[i].size(); j++) temp.back()[j]+=x[i][j]*sign;
			sign=-sign;
		}
		x=temp;
	}
	return x[0];
}
void test(int n){
	cerr<<n<<'\n';
	vector <vector <int>> now;
	vector <int> dummy(n, 0);
	for(int i=0; i<n; i++){
		now.push_back(dummy);
		now.back()[i]=1;
	}
	auto res=f(now);
	for(int i=0; i<n; i++) cerr<<res[i]<<" \n"[i+1==n];
}
int main(){
	test(2);
	test(4);
	test(6);
	test(8);
	test(10);
	test(12);
	test(14);
	test(16);
	cin>>n;
	fact[0]=1;
	for(int i=1; i<=n; i++) fact[i]=(fact[i-1]*i)%base;
	rev[n]=power(fact[n], base-2);
	for(int i=n; i>=1; i--) rev[i-1]=(rev[i]*i)%base;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n==1){
		cout<<a[1];
		return 0;
	}
	if(n%2){
		for(int i=1; i<n; i+=2){
			b[i]=(a[i]+a[i+1])%base;
			b[i+1]=(a[i+1]+base-a[i+2])%base;
		}
		n--;
		for(int i=1; i<=n; i++) a[i]=b[i];
	}
	ll left=0, right=0;;
	ll weight=(n-2)/2;
	for(int i=1; i<=n; i+=2) left=(left+a[i]*C(n/2-1, i/2))%base;
	for(int i=2; i<=n; i+=2) right=(right+a[i]*C(n/2-1, i/2-1))%base;
	// cerr<<left<<' '<<right<<'\n';
	if(((1LL*n*(n-1))/2)%2==0) left-=right;
	else left+=right;
	left=(left+base)%base;
	cout<<left<<'\n';
}