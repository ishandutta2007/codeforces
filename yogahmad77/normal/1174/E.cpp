// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fbo find_by_order
#define ook order_of_key
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define MOD 1000000007 
#define MID (l+r)/2
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define mx 1000003
#define pc(x) putchar_unlocked(x);
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

long long n, dep[mx], banyak[mx], fakt[mx], inv[mx];
vector<int> fak[mx];
bool sudah[mx];
vector<vector<int>> ve;
vector<int> tmp;

void bt(int now){
	tmp.pb(now);
	if(now == 1){
		ve.pb(tmp);
		tmp.pop_back();
		return;
	}
	for(int i : fak[now])
		if(dep[now] == dep[i] + 1)
			bt(i);
	tmp.pop_back();
}

int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	cin >> n;
	fakt[0] = 1;
	inv[0] = 1;
	fakt[1] = inv[1] = 1;
	for(int i = 2; i <= n; i++)
		inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD,
		fakt[i] = fakt[i - 1] * i % MOD;
	for(int i = 2; i <= n; i++)
		inv[i] = inv[i] * inv[i - 1] % MOD;
	// n = 1e6;
	for(int i = 1; i <= n; i++){
		for(int j = i + i; j <= n; j += i)
			fak[j].pb(i);
	}
	long long maks = 0;
	for(int i = 1; i <= n; i++){
		if(i == 1)
			dep[i] = 1;
		else{
			for(int j : fak[i]){
				dep[i] = max(dep[i], dep[j] + 1);
			}
		}
		maks = max(maks, dep[i]);
	}
	// long long sum = 0;
	// for(int i = 1; i <= n; i++){
	// 	if(i == 1)
	// 		banyak[i] = 1;
	// 	else{
	// 		for(int j : fak[i]){
	// 			if(dep[j] + 1 == dep[i])
	// 				banyak[i] += banyak[j];
	// 		}
	// 	}
	// 	if(maks == dep[i])
	// 		sum += banyak[i];
	// }
	for(int i = 1; i <= n; i++){
		if(maks == dep[i])
			bt(i);
	}
	long long sum = 0;
	for(auto i : ve){
		for(int i = 1; i <= n; i++)
			sudah[i] = false;
		long long jaw = 1;
		stack<int> st;
		for(int j : i){
			int cnt = 0;
			for(int x = j; x <= n; x += j){
				if(!sudah[x]){
					sudah[x] = true;
					cnt ++;
				}
			}
			st.push(cnt);
		}
		int total = 0;
		while(!st.empty()){
			auto cnt = st.top();
			st.pop();
			jaw = jaw * fakt[total + cnt - 1] % MOD * inv[total] % MOD;
			jaw = jaw * cnt % MOD;
			total += cnt;
		}
		sum = (sum + jaw) % MOD;
		// debug(jaw);
	}
	cout << sum << endl;
}