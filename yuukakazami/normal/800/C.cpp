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

const int MAX_N = 200000 + 10;

ll exgcd(ll a,ll b, ll&lx,ll&ly){
	ll t,q,x=0,y=1;lx=1,ly=0;
	while(b){
		q = a/b;t=a%b;a=b;b=t;
		t=x;x=lx-q*x;lx=t;
		t=y;y=ly-q*y;ly=t;
	}
	return a;
}

ll solve(ll a, ll b, ll m){
	//find x such that a*x == b (mod m)
	ll x,y;
	ll d = exgcd(a,m,x,y);

	assert(b%d == 0);

	ll ret = ((x*(b/d))%m+m)%m;

	assert(a*ret %m == b % m);
	
	return ret;
}

int n,m;

int a[MAX_N];

bool used[MAX_N];

vector<PII> arr;
int pre[MAX_N];
int ret[MAX_N];

vector<int> divs[MAX_N];

int dp[MAX_N];
int last[MAX_N];

int main(){
	cin>>n>>m;
	rep(i,0,n) scanf("%d",a+i), used[a[i]] = 1;

	rep(i,1,m) if(m%i==0){
		for(int j=1;j*j<=i;++j){
			if(i%j==0) {
				divs[i].pb(j);
				if(j*j<i) divs[i].pb(i/j);
			}
		}
		sort(divs[i].begin(), divs[i].end());
	}

	rep(i,1,m) if(!used[i]) arr.pb(mp(__gcd(i,m),i));

	sort(arr.begin(), arr.end());

	memset(last,-1,sizeof last);
	memset(dp,0,sizeof dp);

	int at = -1;

	rep(i,0,arr.size()){
		int u = arr[i].first;

		int tmp = 1;

		pre[i] = -1;

		for(auto e : divs[u]){
			if(dp[e] + 1 > tmp){
				tmp = dp[e] + 1;
				pre[i] = last[e];
			}
		}

		dp[u] = tmp;
		last[u] = i;
		ret[i] = tmp;

		if(at == -1 || ret[i] > ret[at])
			at = i;
	}

	vector<int> ans;

	if(at != -1){
		int x = at;
		while(x != -1){
			ans.pb(arr[x].second);
			x = pre[x];
		}

		reverse(ans.begin(), ans.end());
	}

	if(!used[0]) ans.pb(0);

	printf("%d\n",ans.size());

	rep(i,0,ans.size()){
		if(i==0)
			printf("%d ",ans[i]);
		else {
			if(ans[i] == 0)
				printf("%d ",ans[i]);
			else
				printf("%d ",solve(ans[i-1],ans[i],m));
		}
	}
	puts("");
	return 0;
}