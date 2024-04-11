#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 150500;

vector< pii > g[N];
vector< int > G[N];
int n, q, val[1000];
int cnt[27][N], t[27][N], pr[N], id[N], k;
char ch[N];
bool good[N];

void dfs(int v, int pr){
	if(pr == -1)
    	id[v] = ++k;
	else
		id[v] = id[pr];
	if(g[v].size() == 2){
		for(auto it : g[v]){
			dfs(it.f, -1);
			cnt[it.s][id[it.f]]++;
			G[id[v]].pb(id[it.f]);
		}
	}
    if(g[v].size() == 1){
		for(auto it : g[v]){
			dfs(it.f, v);
			cnt[it.s][id[it.f]]++;
		}
	}
}
void build(int v){
	if(G[v].empty()){
		good[v] = 1;
		for(int i = 0; i < 27; i++)
			t[i][v] = cnt[i][v];
		return;
	}
	int a = G[v][0], b = G[v][1];
	build(a);
	build(b);
	good[v] = (good[a] & good[b]);
	for(int i = 0; i < 26; i++)
		t[i][v] = max(t[i][a], t[i][b]);
	int aa = 0, bb = 0;
	for(int i = 0; i < 26; i++)
		aa += t[i][v] - t[i][a], bb += t[i][v] - t[i][b];
	good[v] &= (t[26][a] >= aa);
	good[v] &= (t[26][b] >= bb);
	t[26][v] = min(t[26][a] - aa, t[26][b] - bb);		
	for(int i = 0; i < 27; i++)
		t[i][v] += cnt[i][v];
}
void UPD(int v){
	if(v == 0)
		return;
	if(G[v].empty()){
		good[v] = 1;
		for(int i = 0; i < 27; i++)
			t[i][v] = cnt[i][v];
		UPD(pr[v]);
		return;
	}
	int a = G[v][0], b = G[v][1];
	good[v] = (good[a] & good[b]);
	for(int i = 0; i < 26; i++)
		t[i][v] = max(t[i][a], t[i][b]);
	int aa = 0, bb = 0;
	for(int i = 0; i < 26; i++)
		aa += t[i][v] - t[i][a], bb += t[i][v] - t[i][b];
	good[v] &= (t[26][a] >= aa);
	good[v] &= (t[26][b] >= bb);
	t[26][v] = min(t[26][a] - aa, t[26][b] - bb);		
	for(int i = 0; i < 27; i++)
		t[i][v] += cnt[i][v];
	UPD(pr[v]);
}
int main()
{
	for(int i = 'a'; i <= 'z'; i++)
		val[i] = i - 'a';
	val['?'] = 26;
	scanf("%d%d", &n, &q);
	for(int i = 2; i <= n; i++){
		int p;
		scanf("%d %c", &p, &ch[i]);
		g[p].pb({i, val[ch[i]]});
	}
	dfs(1, -1);
	for(int v = 1; v <= k; v++)
		for(auto to : G[v])
			pr[to] = v;
	build(1);
	while(q--){
		int v;
		char c;
		scanf("%d %c", &v, &c); 
	    cnt[val[ch[v]]][id[v]]--;
	    ch[v] = c;
	    cnt[val[ch[v]]][id[v]]++;
	    UPD(id[v]);
		if(!good[1]){
    		puts("Fou");
    		continue;
    	}
    	/*
    	for(int v = 1; v <= k; v++){
    		cerr << v << " : " ;
    		for(int i = 0; i < 27; i++)
    			cerr << t[i][v] << " ";
			cerr << endl;
    	}
    	*/
    	ll ans = 0;
    	for(int i = 0; i < 26; i++)
    		ans += (i + 1) * (t[i][1] + t[26][1]);
    	printf("Shi %lld\n", ans);
    }
	return 0;
}