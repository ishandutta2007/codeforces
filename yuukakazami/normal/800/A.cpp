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

const int MAX_N = 100000 + 10;

typedef long double db;

int n,p;

int a[MAX_N],b[MAX_N];

bool check(db T){
	db rate = 0;
	rep(i,0,n){
		db want = max((db)0,(db)a[i]*T - b[i]) / T;
		rate += want;
		if(rate > p) return 0;
	}
	return 1;
}

int main(){
	cin>>n>>p;
	rep(i,0,n) scanf("%d%d",a+i,b+i);

	long long x = 0; rep(i,0,n) x += a[i];

	if(p >= x){
		cout<<-1<<endl;
		return 0;
	}

	db l=0,r=1e20;
	rep(it,0,100){
		db m = (l+r)/2;
		if(check(m)) l = m;
		else r = m;
	}

	printf("%0.10lf\n",(double)(l));
	return 0;
}