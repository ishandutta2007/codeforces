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
string ss[mx];
int n;
vector<int> vv[mx];
bool vowel(char a){
	return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> ss[i];
	int maks = n / 4;
	for(int i = 0 ; i < n; i++){
		int hit = 0;
		for(auto j : ss[i])
			if(vowel(j))
				hit ++;
		vv[hit].pb(i);
	}
	int dua = 0, satu = 0;
	vector<pair<int, int>> sa, du;
	for(int ii = 1; ii <= 1e6; ii++){
		int a, e, i, o, u;
		a = e = i = o = u = 0;
		vector<int> va, ve, vi, vo, vu;
		for(auto x : vv[ii]){
			char last;
			for(auto y : ss[x])
				if(vowel(y))
					last = y;
			if(last == 'a')
				va.pb(x),
				a ++;
			if(last == 'u')
				vu.pb(x),
				u ++;
			if(last == 'e')
				ve.pb(x),
				e ++;
			if(last == 'i')
				vi.pb(x),
				i ++;
			if(last == 'o')
				vo.pb(x),
				o ++;
		}
		int tot = (a / 2) + (e / 2) + (i / 2) + (o / 2) + (u / 2);
		dua += tot;
		satu += (sz(vv[ii]) - tot * 2) / 2;
		vector<int> sisa;
		int tadi = -1;
		for(int i : va){
			if(tadi == -1)
				tadi = i;
			else{
				du.pb({tadi, i});
				tadi = -1;
			}
		}
		if(tadi != -1)
			sisa.pb(tadi);
		tadi = -1;
		for(int i : ve){
			if(tadi == -1)
				tadi = i;
			else{
				du.pb({tadi, i});
				tadi = -1;
			}
		}
		if(tadi != -1)
			sisa.pb(tadi);
		tadi = -1;
		for(int i : vi){
			if(tadi == -1)
				tadi = i;
			else{
				du.pb({tadi, i});
				tadi = -1;
			}
		}
		if(tadi != -1)
			sisa.pb(tadi);
		tadi = -1;
		for(int i : vo){
			if(tadi == -1)
				tadi = i;
			else{
				du.pb({tadi, i});
				tadi = -1;
			}
		}
		if(tadi != -1)
			sisa.pb(tadi);
		tadi = -1;
		for(int i : vu){
			if(tadi == -1)
				tadi = i;
			else{
				du.pb({tadi, i});
				tadi = -1;
			}
		}
		if(tadi != -1)
			sisa.pb(tadi);
		tadi = -1;
		for(int i : sisa){
			if(tadi == -1)
				tadi = i;
			else{
				sa.pb({tadi, i});
				tadi = -1;
			}
		}
	}
	if(satu >= dua){
		cout << dua << endl;
		assert(dua == sz(du));
		for(int i = 0; i < sz(du); i++){
			cout << ss[sa[i].f] << ' ' << ss[du[i].f] << '\n';
			cout << ss[sa[i].s] << ' ' << ss[du[i].s] << '\n';
		}
	}
	else{
		cout << (satu + dua) / 2 << endl;
		assert((satu + dua) / 2 == (sz(sa) + sz(du)) / 2);
		for(int i = 0; i < sz(sa); i++){
			cout << ss[sa[i].f] << ' ' << ss[du[i].f] << '\n';
			cout << ss[sa[i].s] << ' ' << ss[du[i].s] << '\n';
		}
		for(int i = sz(sa) + 1; i < sz(du); i += 2){
			cout << ss[du[i - 1].f] << ' ' << ss[du[i].f] << '\n';
			cout << ss[du[i - 1].s] << ' ' << ss[du[i].s] << '\n';
		}
	}
}