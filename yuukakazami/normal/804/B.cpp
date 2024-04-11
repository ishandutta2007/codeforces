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
    string S;cin>>S; int n = S.size();
    ll cntb = 0;

    ll ans = 0;

    per(i,0,n){
        if(S[i] == 'b'){
            (++cntb) %= mod;
        } else {
            ans += cntb; ans %= mod;
            cntb *= 2; cntb %= mod;
        }
    }

    cout<<ans<<endl;
	return 0;
}