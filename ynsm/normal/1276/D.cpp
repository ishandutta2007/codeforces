#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;

vector< int > g[N];
int n, s[N], t[N];
ll A[N], B[N], C[N];
ll pre1[N], suf1[N];
ll pre2[N], suf2[N];
void dfs(int v, int p = -1){
	vector< pii > v1, v2;
	for(auto i : g[v]){
		if(i == p)
			continue;
		int to = s[i] ^ t[i] ^ v;
		dfs(to, i);
		if(i < p)
			v1.pb({i, to});
		else
			v2.pb({i, to});
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	ll a = 0, b = 0, c = 0, d = 0;
	for(int i = 0; i < v1.size(); i++)
		if(i != 0)
			pre1[i] = pre1[i - 1] * B[v1[i].s] % mod;
	 	else
	 		pre1[i] = B[v1[i].s];
	for(int i = v1.size() - 1; i >= 0; i--)
		if(i != v1.size() - 1)
			suf1[i] = suf1[i + 1] * C[v1[i].s] % mod;
	 	else
	 		suf1[i] = C[v1[i].s];

	for(int i = 0; i < v2.size(); i++)
		if(i != 0)
			pre2[i] = pre2[i - 1] * B[v2[i].s] % mod;
	 	else
	 		pre2[i] = B[v2[i].s];
	for(int i = v2.size() - 1; i >= 0; i--)
		if(i != v2.size() - 1)
			suf2[i] = suf2[i + 1] * C[v2[i].s] % mod;
	 	else
	 		suf2[i] = C[v2[i].s];

	for(int i = 0; i < v1.size(); i++){
		ll cur = A[v1[i].s];      
		if(i != 0)
        	cur = cur * pre1[i - 1] % mod;
		if(i != v1.size() - 1)
			cur = cur * suf1[i + 1] % mod;
		if(v2.size() != 0)
        	cur = cur * suf2[0] % mod;
		/*
		for(int j = 0; j < i; j++)
			cur = cur *  B[v1[j].s] % mod;
		for(int j = i + 1; j < v1.size(); j++)
			cur = cur *  C[v1[j].s] % mod;
		for(int j = 0; j < v2.size(); j++)
			cur = cur *  C[v2[j].s] % mod;
	    */
	    a = (a + cur) % mod;
	}
	{
		ll cur = 1;
    	for(int j = 0; j < v1.size(); j++)
			cur = cur *  B[v1[j].s] % mod;
		for(int j = 0; j < v2.size(); j++)
			cur = cur *  C[v2[j].s] % mod;
		c = cur; 
	}
	for(int i = 0; i < v2.size(); i++){
		ll cur = A[v2[i].s];
		if(i != 0)
        	cur = cur * pre2[i - 1] % mod;
		if(i != v2.size() - 1)
			cur = cur * suf2[i + 1] % mod;
		if(v1.size() != 0)
        	cur = cur * pre1[v1.size() - 1] % mod;
		/*
		for(int j = 0; j < i; j++)
			cur = cur *  B[v2[j].s] % mod;
		for(int j = i + 1; j < v2.size(); j++)
			cur = cur *  C[v2[j].s] % mod;
		for(int j = 0; j < v1.size(); j++)
			cur = cur *  B[v1[j].s] % mod;
	    */
	    b = (b + cur) % mod;
	}
	{
		ll cur = 1;
    	for(int j = 0; j < v1.size(); j++)
			cur = cur *  B[v1[j].s] % mod;
		for(int j = 0; j < v2.size(); j++)
			cur = cur *  B[v2[j].s] % mod;
		d = cur; 
	}      
	A[v] = (b + d) % mod;
	B[v] = (a + c) % mod;
	C[v] = (a + b + d) % mod;
} 

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d%d", &s[i], &t[i]);
		g[s[i]].pb(i);
		g[t[i]].pb(i);
	}
	dfs(1);
	printf("%lld", C[1]);
	return 0;
}