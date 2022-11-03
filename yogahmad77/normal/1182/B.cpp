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
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;
string ss[mx];
int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> ss[i];
		for(int j = 0; j < m; j++){
			if(ss[i][j] == '*'){
				cnt ++;
			}
		}
	}
	if(cnt > n + m - 1){
		puts("NO");
		return 0;
	}
	for(int i = 1; i < n - 1; i++){
		for(int j = 1; j < m - 1; j++){
			if(ss[i][j] == '.')
				continue;
			int l1, l2, r1, r2;
			l1 = r1 = i;
			l2 = r2 = j;
			for(int x = i + 1; x < n; x++){
				if(ss[x][j] == '.')
					break;
				r1 = x;
			}
			for(int x = i - 1; x >= 0; x--){
				if(ss[x][j] == '.')
					break;
				l1 = x;
			}
			for(int y = j + 1; y < m; y++){
				if(ss[i][y] == '.')
					break;
				r2 = y;
			}
			for(int y = j - 1; y >= 0; y--){
				if(ss[i][y] == '.')
					break;
				l2 = y;
			}
			if(i == 2 && j == 2){
				// debug(l1), debug(r1), debug(l2), debug(r2);
			}
			if((r2 - l2) + (r1 - l1) + 1 == cnt && l1 != i && r1 != i && l2 != j && r2 != j){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
}