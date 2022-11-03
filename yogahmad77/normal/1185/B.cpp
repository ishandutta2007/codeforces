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
#define mx 100003
#define pc(x) putchar_unlocked(x);
#define sz(x) (int)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		vector<pair<char, int>> ve1, ve2;
		char tadi = '-';
		int cnt = 0;
		for(auto i : s1){
			if(tadi == '-'){
				tadi = i;
				cnt = 1;
			}
			else{
				if(tadi == i)
					cnt ++;
				else{
					ve1.pb({tadi, cnt});
					tadi = i;
					cnt = 1;
				}
			}
		}
		ve1.pb({tadi, cnt});
		tadi = i;
		cnt = 1;

		tadi = '-';
		cnt = 0;
		for(auto i : s2){
			if(tadi == '-'){
				tadi = i;
				cnt = 1;
			}
			else{
				if(tadi == i)
					cnt ++;
				else{
					ve2.pb({tadi, cnt});
					tadi = i;
					cnt = 1;
				}
			}
		}
		ve2.pb({tadi, cnt});
		tadi = i;
		cnt = 1;
		if(sz(ve1) != sz(ve2)){
			cout << "NO\n";
			continue;
		}
		bool ya = true;
		for(int i = 0; i < sz(ve1); i++){
			if(ve1[i].f != ve2[i].f || ve1[i].s > ve2[i].s)
				ya = false;
		}
		if(!ya)
			cout << "NO\n";
		else cout << "YES\n";
	}
}