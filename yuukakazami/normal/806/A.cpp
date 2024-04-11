#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int main(){
	int T;cin>>T;
	rep(i,0,T){
		ll x,y,p,q;
		cin>>x>>y>>p>>q;

		if(p == 1 && q == 1){
			if(x < y){
				puts("-1");
			} else {
				puts("0");
			}
			continue;
		}
		if(p == 0){
			if(x==0){
				puts("0");
			} else {
				puts("-1");
			}
			continue;
		}
		// y -> kq, kp >= x, kq >= y k (q-p) >= y-x
		ll k = max(max(x/p,y/q),(y-x)/(q-p));
		while(k*p < x || k*q < y || k * (q-p) < y - x)
			++k;
		ll ret = k*q - y;
		cout<<ret<<endl;
	}
	return 0;
}