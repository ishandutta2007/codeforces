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
#define mx 300003
#define pc(x) putchar_unlocked(x);
#define sz(x) (int)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

long long n, m, tot[(1 << 9) + 100], benar[(1 << 9) + 100], mini[(1 << 9) + 100], apa[(1 << 9) + 100];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int k, x, bit = 0;
		cin >> k;
		while(k --){
			cin >> x;
			x--;
			bit |= 1 << x;
		}
		tot[bit] ++;
	}
	for(int i = 0; i < 1 << 9; i++){
		for(int j = 0; j < 1 << 9; j++){
			int dan = j & i;
			if(dan == i)
				benar[j] += tot[i];
		}
	}
	vector<pair<long long, int>> ve;
	for(int i = 1; i <= m; i++){
		long long harga;
		int k, x, bit = 0;
		cin >> harga >> k;
		ve.pb({harga, i});
		// int bi
		while(k --){
			cin >> x;
			x--;
			bit |= 1 << x;
		}
		if(mini[bit] == 0)
			mini[bit] = harga, apa[bit] = i;
		else if(mini[bit] > harga)
			mini[bit] = harga, apa[bit] = i;
	}
	int I, J;
	long long harga = 1e18, maks = 0;
	for(int i = 0; i < 1 << 9; i++){
		for(int j = 0; j < 1 << 9; j++){
			if(mini[i] == 0 || mini[j] == 0)
				continue;
			if(benar[i | j] > maks){
				maks = benar[i | j];
				harga = mini[i] + mini[j];
				I = apa[i];
				J = apa[j];
			}
			else if(benar[i | j] == maks){
				if(harga > mini[i] + mini[j]){
					I = apa[i];
					J = apa[j];
					harga = mini[i] + mini[j];
				}
			}
		}
	}
	if(I == J){
		long long mi = 1e18;
		sort(ALL(ve));
		for(int i = 0; i < sz(ve); i++){
			if(ve[i].s != I){
				cout << I << ' ' << ve[i].s << endl;
				return 0;
			}
		}
	}
	cout << I << ' ' << J << endl;
}