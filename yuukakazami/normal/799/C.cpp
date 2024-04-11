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

int n,c,d;

typedef pair<int,int> PII;

int main(){
	cin>>n>>c>>d;
	vector<PII> tp[2];

	rep(i,0,n){
		int b,c;
		char ch;
		scanf("%d%d %c",&b,&c,&ch);
		tp[ch-'C'].pb({c,b});
	}

	int L[] = {c,d};

	int ans = 0;

	int got[2] = {-1,-1};

	rep(_,0,2){
		auto x = tp[_];
		int m = L[_];

		sort(x.begin(), x.end());

		int j = 0;

		vector<PII> mx_b = {mp(-1,-1),mp(-1,-1)};

		per(i,0,x.size()){
			while(j < x.size() && x[i].fi + x[j].fi <= m){
				mx_b.pb(mp(x[j].se,j));
				sort(mx_b.rbegin(),mx_b.rend());
				mx_b.pop_back();
				++j;
			}

			for(auto t : mx_b) if(t.fi != -1 && t.se != i){
				ans = max(ans,x[i].se + t.fi);
			}

			if(x[i].fi <= m)
				got[_] = max(got[_],x[i].se);
		}
	}

	if(got[0] != -1 && got[1] != -1)
		ans = max(ans,got[0] + got[1]);

	printf("%d\n",ans);
	return 0;
}