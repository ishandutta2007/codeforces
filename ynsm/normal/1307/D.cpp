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
int n, m, k, a[N], A[N], B[N];
int t[N << 2];
bool cmp(int i, int j){
	return A[i] - B[i] > A[j] - B[j];
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < m; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	{
		queue<int> q;
		q.push(1);
		A[1] = 1;
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(auto to : g[v])
				if(!A[to]){
				    A[to] = A[v] + 1;
					q.push(to);
				}
		}
	}
    {
		queue<int> q;
		q.push(n);
		B[n] = 1;
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(auto to : g[v])
				if(!B[to]){
				    B[to] = B[v] + 1;
					q.push(to);
				}
		}
	}
	sort(a, a + k, cmp);
	int ans = -inf, mx = -inf;
	for(int i = 0; i < k; i++){
		ans = max(ans, A[a[i]] + mx);
		mx = max(mx, B[a[i]]);
	}
	printf("%d", min(ans, A[n]) - 1);
}