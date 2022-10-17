#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

vector< int > g[N];
int n, a[N], p[N], b[N];
bool cmp(int i, int j){
	return a[i] > a[j];
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		p[i] = i;
	}
	sort(p, p + n, cmp);
	for(int i = 0; i < n + n; i++)
		b[i] = -1;

	for(int i = 0, q = 0; i < n; i++){
		int j = p[i];
		b[i] = (j << 1);
		g[i  + a[j]].pb(j << 1 | 1);
	}
	for(int i = n; i < n + n; i++)
		if(!g[i].empty()){
			b[i] = g[i].back();
			g[i].pop_back();
		}else
			break;
	for(int i = 1; i < n + n; i++)
		if(b[i] == -1)
			break;
		else
			printf("%d %d\n", b[i - 1] + 1, b[i] + 1);
	for(int i = 1; i < n + n; i++)
		for(auto it : g[i])
			printf("%d %d\n", b[i - 1] + 1, it + 1);
	return 0;
}