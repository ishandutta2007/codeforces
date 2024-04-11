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
	int n,t,k,d;
	cin>>n>>t>>k>>d;
	auto f = [&](int x,int y){ return (x-1)/y + 1; };
	int T1 = f(n,k) * t;

	int T2 = 1<<30;
	rep(i,0,n+1) T2 = min(T2, max(f(i,k)*t,d+f(n-i,k)*t));

	puts(T2 < T1 ? "YES":"NO");
	return 0;
}