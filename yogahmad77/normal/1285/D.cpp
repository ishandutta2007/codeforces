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


const int MOD = 1e9 + 7;

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


const int mx = 1e5 + 10;
int idx;
vector<int> val, l, r;

void masuk(int now, int level, int bil){
	if(level == 0){
		val[now] = 0;
		return;
	}
	if((1 << (level - 1)) & bil){
		if(r[now] == -1) r[now] = idx++;
		masuk(r[now], level - 1, bil);
	}
	else{
		if(l[now] == -1) l[now] = idx++;
		masuk(l[now], level - 1, bil);
	}
	if(l[now] != -1 && r[now] != -1){
		val[now] = (1 << (level - 1)) | min(val[l[now]], val[r[now]]);
	}
	else if(l[now] != -1) val[now] = val[l[now]];
	else val[now] = val[r[now]];
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	val.resize(n * 30 + 10, 0), l.resize(n * 30 + 10, -1), r.resize(n * 30 + 10, -1);
	int root = idx++;
	for(int i = 0; i < n; i++){
		masuk(root, 30, a[i]);
	}
	cout << val[0] << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}