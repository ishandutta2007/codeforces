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

const int MX = 200005;
const double PI = acos(-1);

auto cmp = [](const pii &l, const pii &r){return l.second !=r.second? l.second < r.second : l.first < r.first; };

char buf[MX];
int TT, N, M, K, W, a, b, c, d, e, f, g, h;

vector<pii> G[MX];
vector<int> T[MX], L[MX];
int ans[MX];
int ad = 0;

void find_region(int x, int y)
{
	L[ad].push_back(x);
	int c = lower_bound(G[y].begin(), G[y].end(), pii(x, -2)) - G[y].begin();
	if( c == 0 ) c = G[y].size() - 1;
	else c--;

	if( G[y][c].second ) return;
	G[y][c].second = ad;
	find_region(y, G[y][c].first);
}

int vst[MX], cnt[MX];

int get_cnt(int x, int p)
{
	if( vst[x] ) return cnt[x] = 0;
	cnt[x] = 1;
	for(int c : T[x]){
		if( c == p ) continue;
		cnt[x] += get_cnt(c, x);
	}
	return cnt[x];
}

void centroid(int x, int lev)
{
	if( vst[x] ) return;
	get_cnt(x, -1);

	while(T[x].size()){
		int mx = 0;
		for(int i = 0; i < T[x].size(); i++){
			if( cnt[T[x][i]] > cnt[T[x][mx]] ) mx = i;
		}
		if( cnt[T[x][mx]]*2 <= cnt[x] ) break;
		cnt[x] = cnt[x] - cnt[T[x][mx]];
		cnt[T[x][mx]] = cnt[x] + cnt[T[x][mx]];
		x = T[x][mx];
	}
	
	vst[x] = 1; ans[x] = lev;
	for(int c : T[x]) centroid(c, lev+1);
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i = 1; i < N; i++){
		G[i].push_back(pii(i+1, 0));
		G[i+1].push_back(pii(i, -1));
	}
	G[N].push_back(pii(1, 0));
	G[1].push_back(pii(N, -1));

	for(int i = 1; i <= M; i++){
		scanf("%d%d", &a, &b);
		G[a].push_back(pii(b, 0));
		G[b].push_back(pii(a, 0));
	}
	for(int i = 1; i <= N; i++) sort(G[i].begin(), G[i].end());
	for(int i = 1; i <= N; i++){
		for(pii &c : G[i]){
			if( c.second ) continue;
			ad++; c.second = ad;
			find_region(i, c.first);
		}
	}
	static int O[MX];
	for(int i = 1; i <= ad; i++) O[i] = i;
	for(int i = 1; i <= ad; i++) sort(L[i].begin(), L[i].end(), greater<int>());
	sort(O+1, O+ad+1, [&](const int &l, const int &r){
		return L[l] < L[r];
	});

	for(int i = 1; i <= N; i++){
		for(pii c : G[i]){
			if( i > c.first ) continue;
			int a = c.second;
			int b = lower_bound(G[c.first].begin(), G[c.first].end(), pii(i, -2)) -> second;
			if( a == -1 || b == -1 ) continue;
			T[a].push_back(b);
			T[b].push_back(a);
		}
	}
	
	centroid(1, 1);
	
	for(int i = 1; i <= ad; i++){
		printf("%d ", ans[O[i]]);
	}
}