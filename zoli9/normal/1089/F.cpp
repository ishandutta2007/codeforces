#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define trav(a,x) for(auto& a : x)
#define all(x) x.begin, x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define TESTING

#ifdef TESTING
#define TO
#else
#define TO if(0)
#endif

ll euclid(ll a, ll b, ll &x, ll &y){
	if(b){
		ll d = euclid(b,a%b, y, x);
		return y -= a/b * x, d;
	}
	return x=1, y=0, a;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	
	int n;
	cin >> n;
	int pp = 2;
	while(pp*pp <= n && n%pp != 0){
		pp++;
	}
	int k = 0;
	int p = 1;
	int q = n;
	while(q%pp==0){
		k++;
		q/=pp;
		p*=pp;
	}
	if(k==0 || q==1){
		cout << "NO" << endl;
		return 0;
	}
	ll a,b;
	euclid(p,q,a,b);
	a = (a*(n-1))%q;
	if(a<0) a+=q;
	b = (b*(n-1))%p;
	if(b<0) b+=p;
	cout << "YES" << endl;
	cout << 2 << endl;
	cout << a << " " << q << endl;
	cout << b << " " << p << endl;
	return 0;
}