#include<stdio.h>
#include<bitset>
#include<vector>
#include<string.h>
#include<algorithm>
#include<memory.h>
#include<math.h>
#include<string>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<functional>
#include<unordered_map>
#include<list>
#define E2(x,y) return !printf(x, y)
#define E1(x) return !printf(x)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int,int,int> t3;

const int MM = 1000;

ll sq(ll x){ return x*x; }
ll rv(ll x){ ll su = 0; while(x){ su = su*10 + x%10; x /= 10; } return su; }

ll pw(ll a, ll b){
	if( !b ) return 1;
	return pw(a*a % MM, b/2) * (b%2 == 1? a : 1) % MM;
}

ll pw(ll a, ll b, ll c){
	if( !b ) return 1;
	return pw(a*a % c, b/2) * (b%2 == 1? a : 1) % c;
}

//ll rv(ll a){ return pw(a, MM-2); }

int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int Ox[8] = {-1, -2, 1, 2, -1, -2, 1, 2};
int Oy[8] = {2, 1, -2, -1, -2, -1, 2, 1}; 
int Bx[6] = {-1, -1, 0, 1, 1, 0};
int By[6] = {-1, 0, 1, 1, 0, -1};

ll gcd(ll A, ll B){ return A? gcd(B%A, A) : B;}

pii operator*(const pii &l, const ll &r){
	return pii(l.first * r, l.second * r);
}

pii operator*(const pii &l, const pii &r){
	return pii(l.first * r.first, l.second * r.second);
}

pii operator+(const pii &l, const pii &r){
	return pii(l.first + r.first, l.second + r.second);
}

pii operator-(const pii &l, const pii &r){
	return pii(l.first - r.first, l.second - r.second);
}

pii operator%(const pii &l, const pii &r){
	return pii(l.first % r.first, l.second % r.second);
}

ll operator^(const pii &l, const pii &r){
	return (ll)l.first * r.second - (ll)l.second * r.first;
}

ll size(pii c){ return sq(c.first) + sq(c.second); }

void file(char* name){
	char buf[105];
	sprintf(buf, "%s.in", name);
	freopen(buf,"r", stdin);
	sprintf(buf, "%s.out", name);
	freopen(buf,"w", stdout);
}

int coor(vector<int> &L, int x){
	return lower_bound(L.begin(), L.end(), x) - L.begin();
}

const int MX = 300005;
const double PI = acos(-1);

auto cmp = [](const pii &l, const pii &r){return l.second !=r.second? l.second < r.second : l.first < r.first; };

char buf[MX];
int TT, N, M, K, W, a, b, c, d, e, f, g, h;

typedef pair<int, char> edge;

vector<edge> D[MX];
int T[MX*2][26], cnt[MX];
int lev[MX], ans[MX], sz;
vector<pii> L;

int add_tree(int x, int y)
{
	int c = 0;
	for(int i = 0; i < 26; i++){
		if( !T[y][i] ) continue;
		if( T[x][i] && T[y][i] ){
			c += add_tree(T[x][i], T[y][i]) + 1;
		}
		else{
			T[x][i] = ++sz; L.emplace_back(x, i);
			add_tree(T[x][i], T[y][i]);
		}
	}
	return c;
}

void solve(int x)
{
	for(int i = 0; i < 26; i++){
		if( T[x][i] ) solve(T[x][i]);
	}
	int mx = 0;
	for(int i = 0; i < 26; i++){
		if( cnt[T[x][i]] > cnt[T[x][mx]] ) mx = i;
	}
	if( cnt[T[x][mx]] == 0 ) return;

	sz = N;
	ans[lev[x]]++;
	for(int i = 0; i < 26; i++){
		if( !T[x][i] || mx == i ) continue;
		ans[lev[x]]++;
		ans[lev[x]] += add_tree(T[x][mx], T[x][i]);
	}
	for(pii c : L){
		T[c.first][c.second] = 0;
	}
	L.clear();
}

int dfs(int x, int p)
{
	lev[x] = lev[p] + 1;
	cnt[x] = 1;
	for(edge c : D[x]){
		if( c.first == p ) continue;
		cnt[x] += dfs(c.first, x);
		T[x][c.second-'a'] = c.first;
	}
	return cnt[x];
}

int main()
{
	scanf("%d", &N);
	for(int i = 2; i <= N; i++){
		scanf("%d%d%s", &a, &b, buf);
		D[a].emplace_back(b, buf[0]);
		D[b].emplace_back(a, buf[0]);
	}
	dfs(1, 0);
	solve(1);
	int mx = 0;
	for(int i = 1; i <= N; i++){
		if( ans[mx] < ans[i] ) mx = i;
	}
	printf("%d\n%d\n", N-ans[mx], mx);
}