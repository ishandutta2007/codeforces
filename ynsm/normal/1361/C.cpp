#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (1 << 22) + 100;

 
vector< pii > g[N];
bool was[N], ok;
int n, a[N], b[N], ans[N];

void solve(int k){
	
	int m = 0;
	for(int i = 0; i < N; i++){
		was[i] = 0;
		g[i].clear();
	}

	for(int i = 0; i < n; i++){
		b[i] = a[i] & ((1 << k) - 1);
		g[i].pb({n + b[i], m});
		g[n + b[i]].pb({i, m});
		m++;
	}
	for(int i = 0; i < n; i += 2){
		g[i].pb({i ^ 1, m});
		g[i ^ 1].pb({i, m});
		m++;
	}
	
	for(int i = 0; i < N; i++)
		if(g[i].size() & 1)
			return;
	int an = 0;

	stack< int > st;
	st.push(0);
	while(!st.empty()){
		int v = st.top();
		while(!g[v].empty() && was[g[v].back().s])
			g[v].pop_back();
			
		if(g[v].empty()){
			if(v < n)
				ans[an++] = v;
			st.pop();
		}else{
			was[g[v].back().s] = 1;
			st.push(g[v].back().f);				
		}	
	}
	if(an == n + 1)
		ok = 1;	
	return;	
}
int main()
{
	scanf("%d", &n);
	n <<= 1;
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 20; i >= 0; i--){
		solve(i);
		if(!ok)
			continue;
		printf("%d\n", i);
		for(int j = 0; j < n; j++)
			printf("%d ", ans[j + (ans[1] != 1)] + 1);
		return 0;
	}
}