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

const int MAX_N = 120 + 10;
const int MAX_M = MAX_N * 32 + 10;
const int INF = ~0U>>3;

const int P = 5;

int n;
int a[MAX_N][P];

int acc[P];

int get(int acc,int total){
	if(acc*2 > total) return 500;
	if(acc*4 > total) return 1000;
	if(acc*8 > total) return 1500;
	if(acc*16 > total) return 2000;
	if(acc*32 > total) return 2500;
	return 3000;
}

int score(int minute,int acc,int total){
	if(minute == -1) return 0;
	int tmp = get(acc,total);
	return tmp - tmp * minute / 250;
}

int main(){
	cin>>n;
	rep(i,0,n) rep(j,0,P){
		cin>>a[i][j];
		if(a[i][j] != -1) acc[j]++;
	}

	rep(new_r,0,MAX_M){
		int dp[P+1]={};
		rep(i,0,P+1) dp[i] = -INF;

		dp[0] = 0;

		rep(i,0,P+1){
			rep(a,0,new_r+1){
				if(a > 0 && ::a[0][i] == -1) continue;
				dp[i+1] = max(dp[i+1],
					dp[i] + score(::a[0][i],acc[i]+a,n+new_r)
					- score(::a[1][i],acc[i]+a,n+new_r) );
			}
		}

		if(dp[P] > 0){
			cout<<new_r<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}