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
int a,b,h,w,n;
vector<int> mult;

int get(int x,int a){
	int t = x/a;
	while(t*a < x) ++t;
	return t;
}

int main(){
	cin>>a>>b>>h>>w>>n;
	mult.resize(n); rep(i,0,n) scanf("%d",&mult[i]);

	sort(mult.rbegin(),mult.rend());

	int ans = 1<<30;

	rep(_,0,2){
		set<PII> dp,pd;

		dp.insert({get(a,h),get(b,w)});

		rep(it,0,min(n+1,40)){
			for(auto i : dp){
				if(i.fi == 1 && i.se == 1){
					ans = min(ans,it);
					goto end;
				}
				if(it < n){
					pd.insert({get(i.fi,mult[it]),i.se});
					pd.insert({i.fi,get(i.se,mult[it])});
				}
			}
			dp = pd;
		}

		end:{}

		swap(a,b);
	}

	if(ans == (1<<30)) ans = -1;
	printf("%d\n",ans);
	return 0;
}