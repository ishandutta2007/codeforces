#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
#define mx 2000003
#define pc(x) putchar_unlocked(x);
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n, k, a[mx], kirikecil[mx], kanankecil[mx], kiribesar[mx], kananbesar[mx], x, bit[mx];
int pref[mx], suff[mx];

void upd(int idx, int val){
	for(; idx <= x + 100; idx += idx & -idx)
		bit[idx] += val;
}

int cari(int idx){
	int ret = 0;
	for(; idx > 0; idx -= idx & -idx)
		ret += bit[idx];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> x;
	set<int> nomor;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= x; i++){
		kanankecil[i] = kirikecil[i] = x + 1;
		kiribesar[i] = kananbesar[i] = 0;
	}
	//kanan
	for(int i = 1; i <= n; i++){
		nomor.insert(a[i]);
		auto it = nomor.upper_bound(a[i]);
		if(it != nomor.end())
			kanankecil[a[i]] = min(kanankecil[a[i]], *it);
		it = nomor.end();
		it --;
		if(*it > a[i])
			kananbesar[a[i]] = max(kananbesar[a[i]], *it);
	}
	nomor.clear();
	//kiri
	for(int i = n; i > 0; i--){
		nomor.insert(a[i]);
		auto it = nomor.begin();
		if(*it < a[i])
			kirikecil[a[i]] = min(kirikecil[a[i]], *it);
		it = nomor.lower_bound(a[i]);
		if(it != nomor.begin()){
			it --;
			kiribesar[a[i]] = max(kiribesar[a[i]], *it);
		}
	}
	//prefix doang
	long long jaw = 1;
	int kanan = x + 1, kiri = 0;
	for(int i = 1; i < x; i++){
		kanan = min(kanan, kanankecil[i]);
		kiri = max(kiri, kiribesar[i]);
		if(kiri < 1 && i < kanan)
			jaw++;
	}
	//suffix doang
	kiri = 0, kanan = x + 1;
	for(int i = x; i > 1; i--){
		kiri = max(kiri, kiribesar[i]);
		kanan = min(kanan, kanankecil[i]);
		if(kiri < i && x < kanan)
			jaw++;
	}
	// debug(jaw);
	kiri = 0, kanan = x + 1;
	int kik = x + 1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i = x; i > 0; i--){
		kiri = max(kiri, kiribesar[i]);
		kanan = min(kanan, kanankecil[i]);
		kik = min(kik, kirikecil[i]);
		// debug(kiri);
		// debug(kanan);
		if(kiri < i && x < kanan){
			pq.push({i, kik});
			// debug(i);
			// debug(kik);
			upd(1, 1);
			upd(kik, -1);
		}
	}
	int kab = 0;
	kiri = 0, kanan = x + 1;
	for(int i = 1; i <= x; i++){
		kab = max(kab, kananbesar[i]);
		kiri = max(kiri, kiribesar[i]);
		kanan = min(kanan, kanankecil[i]);
		while(!pq.empty() && (pq.top().f <= i + 1 || pq.top().f <= kab)){
			auto now = pq.top();
			pq.pop();
			// cout << "hapus " << now.f<<endl;
			upd(1, -1);
			upd(now.s, 1);
		}
		if(kiri < 1 && i < kanan){
			// debug(i);
			jaw += cari(i);
		}
	}
	cout << jaw << '\n';
}