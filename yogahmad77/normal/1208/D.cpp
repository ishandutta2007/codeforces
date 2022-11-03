#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
#define MOD 1000000007 
#define mx 300003

int n;
long long bit[mx];


void upd(int idx, int val){
	for(; idx <= n; idx += idx & -idx)
		bit[idx] += val;
}

long long cari(int idx){
	long long ret = 0;
	for(; idx > 0; idx -= idx & -idx)
		ret += bit[idx];
	return ret;
}

int main(){
	cin >> n;
	vector<long long> s(n), a(n);
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 1; i <= n; i++)
		upd(i, i);
	set<int> ini;
	for(int i = 1; i <= n; i++)
		ini.insert(i);
	for(int i = n - 1; i >= 0; i--){
		long long lo = 1, hi = n, mid, ans;
		while(lo <= hi){
			mid = (lo + hi) >> 1;
			long long sum = cari(mid - 1);
			if(sum >= s[i]){
				hi = mid - 1;
				ans = mid;
			}
			else lo = mid + 1;
		}
		auto it = ini.lower_bound(ans);
		a[i] = *it;
		assert(cari(a[i] - 1) == s[i]);
		upd(a[i], -a[i]);
		ini.erase(it);
	}
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
}