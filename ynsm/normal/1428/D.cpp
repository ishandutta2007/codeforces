#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n, a[N];
vector< int > v[5];
vector< pii > ans;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = n; i >= 1; i--){
		if(a[i] == 1){
			v[1].pb(i);
			ans.pb({i, i});
		}
		if(a[i] == 2){
			if(v[1].size()){
				int j = v[1].back();
				v[1].pop_back();
				ans.pb({j, i}); 				
			}else{
				puts("-1");
				return 0;
			}
			v[2].pb(i);
		}
		if(a[i] == 3){
			if(v[3].size()){
				int j = v[3].back();
				v[3].pop_back();
				ans.pb({i, i});
				ans.pb({i, j});
			}else if(v[2].size()){
				int j = v[2].back();
				v[2].pop_back();
				ans.pb({i, i});
				ans.pb({i, j});
			}else if(v[1].size()){
				int j = v[1].back();
				v[1].pop_back();
				ans.pb({i, i}); 				
				ans.pb({i, j});
			}else{
				puts("-1");
				return 0;
			}
			v[3].pb(i);
		}
	}
	printf("%d\n", ans.size());
	for(auto x : ans)
		printf("%d %d\n", x.f, x.s);
}