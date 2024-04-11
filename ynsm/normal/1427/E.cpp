#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
ll k, a[N], b[N], c[N];
pair<pll, bool> ans[N];   
ll op1(ll a, ll b){
	ans[k++] = {{a, b}, 0};
	return a + b;
}
ll op2(ll a, ll b){
	ans[k++] = {{a, b}, 1};
	return a ^ b;
}
int main(){
	ll x;
	scanf("%lld", &x);
	ll lg = 0, xx = x;
	while(xx)
		lg++, xx >>= 1;
	a[0] = b[0] = c[0] = x;
	for(int i = 1; i <= lg; i++){
		a[i] = op1(a[i - 1], a[i - 1]);
		b[i] = op1(a[i], b[i - 1]);
	}
	ll A = op1(op2(a[lg], b[lg - 1]), x);	
	for(int i = 1; i <= lg; i++){
		c[i] = op1(c[i - 1], c[i - 1]);
		if((c[i] ^ A) < c[i])
			c[i] = op2(c[i], A);
	}
	ll X = x;
	for(int i = 0; i <= lg; i++){
		if((X >> i) & 1)
			continue;			
		X = op2(X, c[i]);
	}

	ll x1 = X;
	ll x2 = op1(x1, x1);
	ll x3 = op2(x1, x2);
	ll x4 = op1(x1, x3);
	ll x5 = op1(x2, x1);
	ll x6 = op2(x3, x5);
	ll x7 = op2(x6, x4);
	ll x8 = op2(x7, x2);
	
	A = x8;
	for(int i = 1; A <= X; i++){
		X = op2(X, A);
		A = op1(A, A);
	}
	printf("%lld\n", k);	
	for(int i = 0; i < k; i++){                     
		if(!ans[i].s)
			printf("%lld + %lld\n", ans[i].f.f, ans[i].f.s);
		else
			printf("%lld ^ %lld\n", ans[i].f.f, ans[i].f.s); 
	}
}