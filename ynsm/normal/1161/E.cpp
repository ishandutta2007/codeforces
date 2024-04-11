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


int n, p[N];
vector< pii > v;
string s;

void ask(){
	if(v.empty()){
		s = "";
		return;
	}
	printf("Q %d", (int)v.size());
	for(auto it : v)
		printf(" %d %d", it.f, it.s);
	printf("\n");
	fflush(stdout);
	char ch = getchar();
	s = "";              
	while(ch != '0' && ch != '1')
		ch = getchar();
	while(ch == '0' || ch == '1')
		s += ch, ch = getchar();
}
int getp(int v){
	if(p[v] == v)
		return v;
	return p[v] = getp(p[v]);
}
void Merge(int v, int u){
	p[getp(v)] = getp(u);
}
void ans(){
	map<int ,vector< int > > m;
	for(int i = 1; i <= n; i++)
		m[getp(i)].pb(i);
	int cnt = 0;
	printf("A");
	for(auto it : m){
		cnt++;
		printf(" %d", it.s.size());
	}
	for(int i = cnt; i < 3; i++)
		printf(" 0");
	printf("\n");
	for(auto it : m){
		for(auto i : it.s)
			printf("%d ", i);
		printf("\n");			
	}
	for(int i = cnt; i < 3; i++)
		printf("\n");
	fflush(stdout);
}

void solve(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		p[i] = i;                    
	
	v.clear();
	for(int i = 1; i + 1 <= n; i += 2)
		v.pb({i, i + 1});
	ask();
	for(int i = 0; i < s.size(); i++)
		if(s[i] == '1')
			Merge(v[i].f, v[i].s);	

	v.clear();
	for(int i = 2; i + 1 <= n; i += 2)
		v.pb({i, i + 1});
	ask();                              
	for(int i = 0; i < s.size(); i++)
		if(s[i] == '1')
			Merge(v[i].f, v[i].s);	
	
	vector< int > p;
	p.pb(1);
	for(int i = 2; i <= n; i++)
		if(getp(i) != getp(i - 1))
			p.pb(i);	
	
	v.clear();
	for(int i = 0; i + 2 < p.size(); i += 3)
		v.pb({p[i], p[i + 2]});
	ask();
	for(int i = 0; i < s.size(); i++)
		if(s[i] == '1')
			Merge(v[i].f, v[i].s);	
	v.clear();
	for(int i = 1; i + 2 < p.size(); i += 3)
		v.pb({p[i], p[i + 2]});
	ask();
	for(int i = 0; i < s.size(); i++)
		if(s[i] == '1')
			Merge(v[i].f, v[i].s);	
	v.clear();
	for(int i = 2; i + 2 < p.size(); i += 3)
		v.pb({p[i], p[i + 2]});
	ask();
	for(int i = 0; i < s.size(); i++)
		if(s[i] == '1')
			Merge(v[i].f, v[i].s);	
	if(p.size() <= 2){
		ans();
		return;
	}
	vector< int > g;
	g.pb(p[0]);
	g.pb(p[1]);
	for(int i = 2; i < p.size(); i++){
		if(getp(p[i]) == getp(p[i - 2]))
			Merge(p[i], p[i - 2]);
		else{
			if(g.size() == 2){
				g.pb(p[i]);
				continue;
			}
			for(int j = 0; j < 3; j++){
				bool ok = 0;                              
				ok |= (getp(p[i - 1]) == getp(g[j]));
				ok |= (getp(p[i - 2]) == getp(g[j]));
				if(ok == 0){
					Merge(p[i], g[j]);
					break;
				}
			}
		}	
	}		
	ans();
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}