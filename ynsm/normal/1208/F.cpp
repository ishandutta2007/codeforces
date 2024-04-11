#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e6 + 100, M = 5e6 + 100, K = 21;

int n, a[N], ans, nxt[M][2], sz = 1;
vector< int > q[N];
pii ff[1 << K];
bool was[1 << K];
void cc(pii &a, int x){
	if(a.f < x)
		a.s = a.f, a.f = x;
	else if(a.s < x)
		a.s = x;
}
void cc(pii &a, int x, int y){
	cc(a, x);
	cc(a, y);
}
void add(int x){
	int v = 0;
	for(int i = K - 1; i >= 0; i--){
		if((x >> i) & 1){
			if(nxt[v][1] == 0)
				nxt[v][1] = sz++;
			v = nxt[v][1];		
		}else{
			if(nxt[v][0] == 0)
				nxt[v][0] = sz++;
			v = nxt[v][0];		
		}
	}
}
int get(int x){
	int v = 0, res = x;
	for(int i = K - 1; i >= 0; i--){
		if((x >> i) & 1){
			v = nxt[v][0];		
		}else{
			if(nxt[v][1] != 0)
				v = nxt[v][1], res |= (1 << i);
			else
				v = nxt[v][0];		
		}
		if(v == 0)
			return 0;
	}
	return res;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		cc(ff[a[i]], i);
	}
	for(int i = 0; i < K; i++){
		for(int j = 0; j < (1 << K); j++)
			if((j >> i) & 1)
				cc(ff[j  ^ (1 << i)], ff[j].f, ff[j].s);				
	}
	for(int i = 0; i < (1 << K); i++)
		q[ff[i].s].pb(i);
	for(int i = 1; i <= n; i++){
		for(auto it : q[i])
			ans = max(ans, get(it));
		add(a[i]);
	}	
	printf("%d", ans);
	return 0;
}