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

string ss[2003];
bool sudah[2003][2003];
int t, n, m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		vector<pair<int, int>> ve[26];
		for(int i = 0; i < n; i++)
			cin >> ss[i];
		pair<int, int> di;
		int maks = -1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				sudah[i][j] = false;
				if(ss[i][j] == '.')
					continue;
				ve[ss[i][j] - 'a'].pb({i, j});
				if(maks < (int)(ss[i][j])){
					maks = (int)(ss[i][j]);
					di = {i, j};
				}
			}
		}
		bool udah = false;
		vector<pair<pair<int, int>, pair<int, int>>> ans;
		// for(int i = 0; i < n; i ++)
		bool ya = true;
		for(int i = 25; i >= 0; i--){
			// debug(i);
			if(sz(ve[i]) == 0){
				if(!udah)
					continue;
				ans.pb({di, di});
			}
			else{
				udah = true;
				sort(ALL(ve[i]));
				set<int> ver, hor;
				for(auto j : ve[i])
					ver.insert(j.f), hor.insert(j.s);
				if(sz(ver) > 1 && sz(hor) > 1){
					ya = false;
					break;
				}
				if(sz(ver) == 1 && sz(hor) == 1){
					ans.pb({ve[i][0], ve[i][0]});
					sudah[ve[i][0].f][ve[i][0].s] = true;
					continue;
				}
				// debug(sz(ver));
				// debug(sz(hor));
				if(sz(ver) == 1){
					for(int j = ve[i][0].s; j <= ve[i].back().s; j++){
						if(!sudah[ve[i][0].f][j] && ss[ve[i][0].f][j] != (char)(i + 'a')){
							ya = false;
							break;
						}
					}
					if(!ya)
						break;
					ans.pb({ve[i][0], ve[i].back()});
					for(int j = ve[i][0].s; j <= ve[i].back().s; j++){
						sudah[ve[i][0].f][j] = true;
					}
				}
				if(sz(hor) == 1){
					for(int j = ve[i][0].f; j <= ve[i].back().f; j++){
						if(!sudah[j][ve[i][0].s] && ss[j][ve[i][0].s] != (char)(i + 'a')){
							ya = false;
							break;
						}
					}
					if(!ya)
						break;
					ans.pb({ve[i][0], ve[i].back()});
					for(int j = ve[i][0].f; j <= ve[i].back().f; j++){
						sudah[j][ve[i][0].s] = true;
					}
				}
			}
		}
		if(!ya){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		cout << sz(ans) << '\n';
		reverse(ALL(ans));
		for(auto i : ans)
			cout << i.f.f + 1<< ' ' << i.f.s + 1<< ' ' << i.s.f + 1 << ' ' << i.s.s + 1 << '\n';
	}
}