#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e6 + 100;

int t, n, m;
bool was[N];
int main()
{
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= 3 * n; i++)
			was[i ] = 0;
		vector< int > ans;
		for(int i = 1; i <= m; i++){
			int v, u;
			scanf("%d%d", &v, &u);
			if(was[v] || was[u])
				continue;
			was[v] = was[u] = 1;
			ans.pb(i);
		}
		if(ans.size() >= n){
			printf("Matching\n");
			for(int i = 0; i < n; i++)
				printf("%d ", ans[i]);
			printf("\n");
		}else{
			printf("IndSet\n");
			for(int i = 1, j = 0; j < n; i++)
				if(!was[i]){
                	printf("%d ", i);
                	j++;
                }
			printf("\n");
		}
	}
	return 0;
}