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

ll p;
const int maxn = 409;
ll fact[maxn];
ll alpha[maxn][maxn];
ll a[maxn];
ll b[maxn];
ll mod(ll &x){
	x %= p;
	if(x<0) x+=p;
	return x;
}


int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t >> p;
	
	fact[0] = 1;
	rep(i,1,maxn){
		fact[i] = fact[i-1]*i;
		mod(fact[i]);
	}
	
	alpha[0][0] = 1;
	rep(i,1,maxn){
		rep(j,1,maxn){
			if(j>i){
				continue;
			}
			rep(k,1,i+1){
				alpha[i][j] += fact[k]*alpha[i-k][j-1];
				mod(alpha[i][j]);
			}
		}
	}
	
	a[0] = 0;
	b[0] = 0;
	a[1] = 1;
	b[1] = 1;
	rep(n,2,maxn){
		b[n] = fact[n];
		rep(k,1,n){
			b[n] -= b[k]*fact[n-k];
			mod(b[n]);
		}
		a[n] = 2*b[n] - fact[n];
		rep(k,4,n){
			a[n] -= alpha[n][k]*a[k];
			mod(a[n]);
		}
	}
	a[2] = 2;
	
	rep(i,0,t){
		int nn;
		cin >> nn;
		cout << a[nn] << endl;
	}
}