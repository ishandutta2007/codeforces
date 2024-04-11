#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, LOG = 19;

int n, q, a[N], last[LOG], ans[LOG][N];
int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		for(int j = 0; j < LOG; j++)
			if((a[i] >> j) & 1)
				for(int q = 0; q < LOG; q++)
					ans[q][i] = max(ans[q][i], ans[q][last[j]]);
		for(int j = 0; j < LOG; j++)
			if((a[i] >> j) & 1)
				ans[j][i] = i, last[j] = i;
	}
	
	while(q--){
		int v, u;
		scanf("%d%d", &v, &u);
		bool ok = 0;
		for(int i = 0; i < LOG; i++)
			if((a[v] >> i) & 1)
				ok |= (v <= ans[i][u]);  
		if(ok)
			puts("Shi");
		else
			puts("Fou");
	}
	return 0;
}