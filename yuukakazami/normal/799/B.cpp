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

int p[MAX_N],a[MAX_N],b[MAX_N],n,m;

vector<int> has_color[3];

bool used[MAX_N];

int main(){
	cin>>n;
	rep(i,0,n) scanf("%d",p+i);
	rep(i,0,n){
		scanf("%d",a+i),--a[i];
		has_color[a[i]].pb(i);
	}
	rep(i,0,n){
		scanf("%d",b+i),--b[i];
		has_color[b[i]].pb(i);
	}

	rep(i,0,3)
		sort(has_color[i].begin(), has_color[i].end(),[&](int x,int y){ return p[x] > p[y]; });

	cin>>m;
	rep(i,0,m){
		int c;scanf("%d",&c);--c;
		bool ok = 0;
		while(!has_color[c].empty()){
			int id = has_color[c].back();
			has_color[c].pop_back();
			if(used[id]) continue;
			used[id] = 1;
			printf("%d ",p[id]);
			ok = 1;
			break;
		}
		if(!ok) printf("-1 ");
	}	
	puts("");
	return 0;
}