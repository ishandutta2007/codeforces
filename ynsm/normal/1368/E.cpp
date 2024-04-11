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
 
vector< int > g[N], gr[N];
bool del[N], ans[N];
int n, m, deg[N];
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		
		for(int i = 1; i <= n; i++){
			g[i].clear();
			ans[i] = 0;
		}

		for(int i = 0; i < m; i++){
			int v, u;
			scanf("%d%d", &v, &u);
			g[u].pb(v);
		}
		for(int i = 1; i <= n; i++)
			for(auto j : g[i])
				for(auto q : g[j])
					if(!ans[j] && !ans[q]){
						ans[i] = 1;
					}
		int k = 0;
		for(int i = 1; i <= n; i++)
			if(ans[i])
        		k++;
        printf("%d\n", k);
		for(int i = 1; i <= n; i++)
			if(ans[i])
            	printf("%d ", i);
		printf("\n");
	}
}