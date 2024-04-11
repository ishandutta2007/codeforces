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

vector< int > g[N];
int n, m;
int main()
{
	scanf("%d%d", &n, &m);
	while(m--){
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;                
		g[a].pb((a - b + n) % n);
		g[b].pb((b - a + n) % n);
	}                           
	for(int i = 0; i < n; i++)
		sort(g[i].begin(), g[i].end());		

	for(int i = 1; i < n; i++)
		if(n % i == 0){
			bool ok = 1;
			for(int j = 0; j < n; j++)
				if(g[j] != g[(j + i) % n])
					ok = 0;
			if(!ok)
				continue;
			printf("Yes");
			return 0;					
		}
	printf("No");
	return 0;
}