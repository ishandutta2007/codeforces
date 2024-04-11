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

const int MAX_N = int(1e5) + 10;
const int LOG = 60;

int n;
ll a[MAX_N];

int cnt[LOG];

int getLog(ll x){
	if((x&(x-1)) == 0){
		return __builtin_ctzll(x);
	}
	return -1;
}

vector<ll> extra;

bool check(int m){
	//destry m chains
	vector<ll> new_extra;

	vector<ll> ends;

	rep(i,0,LOG-1){
		int end = cnt[i] - cnt[i+1];
		int take = min(m,end);
		m -= take;
		int rem = end - take;

		rep(j,0,take) rep(k,0,i+1) new_extra.pb(1LL<<k);
		rep(j,0,rem) ends.pb(1LL<<i);
	}

	static ll tmp[MAX_N];
	int cnt = merge(extra.begin(), extra.end(),new_extra.begin(), new_extra.end(),tmp) - tmp;

	if(ends.size() < cnt) return 0;
	reverse(tmp,tmp+cnt); // big to small
	reverse(ends.begin(), ends.end());
	rep(i,0,cnt){
		if(ends[i]*2 < tmp[i]) return 0;
	}
	return 1;
}

int main(){
	cin>>n;
	rep(i,0,n){
		scanf("%lld",a+i);
		int lg = getLog(a[i]);
		if(lg == -1)
			extra.pb(a[i]);
		else
			cnt[lg]++;
	}

	rep(i,1,LOG){
		int have = min(cnt[i-1],cnt[i]);

		rep(j,0,cnt[i] - have)
			extra.pb(1LL<<i);

		cnt[i] = have;
	}

	sort(extra.begin(), extra.end());

	int tot = cnt[0];

	if(!check(0)){
		puts("-1");
		return 0;
	}
	int l = 0, r = tot;
	while(l + 1 < r){
		int m = l + r >> 1;
		if(check(m)) l = m; else r = m;
	}

	rep(k,tot-l,tot+1) printf("%d ",k);
	puts("");
	return 0;
}