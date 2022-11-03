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
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e6 + 10;

pair<int, int> maks[mx * 4];
int a[mx], n, k;

void build(int idx, int l, int r){
	if(l == r){
		maks[idx] = {a[l], l};
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * idx, l, mid);
	build(2 * idx + 1, mid + 1, r);
	maks[idx] = max(maks[idx * 2], maks[idx * 2 + 1]);
}

pair<int, int> cari(int idx, int l, int r, int fl, int fr){
	if(fl > r || fr < l) return {-1, -1};
	if(fl <= l && r <= fr) return maks[idx];
	int mid = (l + r) >> 1;
	auto aa = cari(2 * idx, l, mid, fl, fr);
	auto bb = cari(2 * idx + 1, mid + 1, r, fl, fr);
	return max(aa, bb);
}

long long jaw = 0;

void solve(int l, int r){
	if(l > r) return;
	auto maks = cari(1, 0, n - 1, l, r);
	int mid = maks.s;
	if(r - mid <= mid - l){
		for(int i = mid; i <= r; i++){
			int dari = i - k + 1;
			if(dari < l) continue;
			if(dari <= mid){
				int sisa = (dari - l) / (k - 1);
				int L = dari - sisa * (k - 1);
				int R = dari;
				jaw = jaw + 1LL * ((R - L) / (k - 1) + 1) * a[mid] % MOD;
				jaw %= MOD;
			}
			else{
				int R = dari - (k - 1) * ((dari - mid - 1) / (k - 1) + 1);
				if(R < l) continue;
				int L = R - (k - 1) * ((R - l) / (k - 1));
				jaw = jaw + 1LL * ((R - L) / (k - 1) + 1) * a[mid] % MOD;
				jaw %= MOD;
			}
		}
	}
	else{
		for(int i = l; i <= mid; i++){
			int dari = i + k - 1;
			if(dari > r) continue;
			if(dari < mid){
				int L = dari + (k - 1) * ((mid - dari - 1) / (k - 1) + 1);
				if(L > r) continue;
				int R = L + (k - 1) * ((r - L) / (k - 1));
				jaw = jaw + 1LL * ((R - L) / (k - 1) + 1) * a[mid] % MOD;
				jaw %= MOD;
			}
			else{
				int L = dari;
				int R = L + (k - 1) * ((r - L) / (k - 1));
				jaw = jaw + 1LL * ((R - L) / (k - 1) + 1) * a[mid] % MOD;
				jaw %= MOD;
			}
		}
	}
	// debug(l, r, mid, jaw);
	solve(l, mid - 1);
	solve(mid + 1, r);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	build(1, 0, n - 1);
	solve(0, n - 1);
	cout << jaw << endl;
}