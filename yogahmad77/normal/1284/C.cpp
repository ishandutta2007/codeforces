#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())


int MOD;

int add(int x, int y){
	int ret = x + y;
	if(ret >= MOD) ret -= MOD;
	return ret;
}
int sub(int x, int y){
	int ret = x - y;
	if(ret < 0) ret += MOD;
	return ret;
}
int mul(int x, int y){
	return (long long)x * y % MOD;
}


const int mx = 3e5 + 10;

int fak[mx];

void solve(){
	int n;
    cin >> n >> MOD;
    fak[0] = 1;
    for(int i = 1; i <= n; i++) fak[i] = mul(fak[i - 1], i);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int banyak = n - i + 1;
        int geser = banyak;
        int sisa = n - i;
        int tot = mul(mul(banyak, geser), mul(fak[i], fak[sisa]));
        // debug(i, tot);
        ans = add(ans, tot);
    }
    cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t--){
		solve();
	}
}