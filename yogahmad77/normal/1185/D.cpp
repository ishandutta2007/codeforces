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

long long a[mx], n;
map<long long, int> cnt, di;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		di[a[i]] = i;
	sort(a + 1, a + n + 1);
	set<long long> beda;
	for(int i = 2; i <= n; i++)
		cnt[a[i] - a[i - 1]] ++;
	for(int i = 1; i <= n; i++){
		if(i == 1){
			cnt[a[i + 1] - a[i]] --;
			if(cnt[a[i + 1] - a[i]] == 0)
				cnt.erase(a[i + 1] - a[i]);
			if(sz(cnt) <= 1){
				cout << di[a[i]] << endl;
				return 0;
			}
			cnt[a[i + 1] - a[i]] ++;
		}
		else if(i == n){
			cnt[a[i] - a[i - 1]] --;
			if(cnt[a[i] - a[i - 1]] == 0)
				cnt.erase(a[i] - a[i - 1]);
			if(sz(cnt) <= 1){
				cout << di[a[i]] << endl;
				return 0;
			}
			cnt[a[i] - a[i - 1]] ++;
		}
		else{
			// assert(sz(cnt) > 1);
			// if(sz(cnt) == 2){
				cnt[a[i + 1] - a[i]] --;
				if(cnt[a[i + 1] - a[i]] == 0)
					cnt.erase(a[i + 1] - a[i]);
				cnt[a[i] - a[i - 1]] --;
				if(cnt[a[i] - a[i - 1]] == 0)
					cnt.erase(a[i] - a[i - 1]);
				cnt[a[i + 1] - a[i - 1]] ++;
				if(sz(cnt) <= 1){
					cout << di[a[i]] << endl;
					return 0;
				}
				cnt[a[i + 1] - a[i]] ++;
				cnt[a[i] - a[i - 1]] ++;
				cnt[a[i + 1] - a[i - 1]] --;
				if(cnt[a[i + 1] - a[i - 1]] == 0)
					cnt.erase(a[i + 1] - a[i - 1]);
			// }
		}
	}
	cout << -1 << endl;
}