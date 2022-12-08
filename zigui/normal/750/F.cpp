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
typedef pair<ll,ll> pii;

const int MM = 1000000007;

ll sq(ll x){ return x*x; }

ll pw(ll a, ll b){
	if( !b ) return 1;
	return pw(a*a % MM, b/2) * (b%2 == 1? a : 1) % MM;
}

ll pw(ll a, ll b, ll c){
	if( !b ) return 1;
	return pw(a*a % c, b/2) * (b%2 == 1? a : 1) % c;
}

//ll rv(ll a){ return pw(a, MM-2); }

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, 1, -1, -1, 1};
int Ox[8] = {-1, -2, 1, 2, -1, -2, 1, 2};
int Oy[8] = {2, 1, -2, -1, -2, -1, 2, 1}; 

ll gcd(ll A, ll B){ return A? gcd(B%A, A) : B;}

pii operator+(const pii &l, const pii &r){
	return pii(l.first + r.first, l.second + r.second);
}

pii operator-(const pii &l, const pii &r){
	return pii(l.first - r.first, l.second - r.second);
}

ll operator^(const pii &l, const pii &r){
	return (ll)l.first * r.second - (ll)l.second * r.first;
}

ll size(pii c){ return sq(c.first) + sq(c.second); }

void file(){
	freopen("lasers.in","r", stdin);
	freopen("lasers.out", "w", stdout);
}

int coor(vector<int> &L, int x){
	return lower_bound(L.begin(), L.end(), x) - L.begin();
}

const int MX = 100005;

char buf[MX];
int TT, N, M, K, W, a, b, c, d, e, f;

map<int, vector<int>> G;

void check(int x){
	if( G.find(x) != G.end() ) return;
	if( G.size() == 16 ){
		G[x].push_back(-1);
		G[x].push_back(-1);
		return;
	}
	printf("? %d\n", x); fflush(stdout);
	scanf("%d", &a);
	for(int i = 0; i < a; i++){
		scanf("%d", &b);
		G[x].push_back(b);
	}
}

void dfs(int x, int p, vector<int> &L){
	L.push_back(x);
	check(x);
	for(int c : G[x]){
		if( c == p ) continue;
		dfs(c, x, L);
		break;
	}
}

int dfs2(int h, int x, int p){
	check(x);
	if( G[x].size() == 2 ) return x;
	if( h == 0 ) return -1;
	for(int c : G[x]){
		if( c == p ) continue;
		int t = dfs2(h-1, c, x);
		if( t != -1 ) return t;
	}
	return -1;
}

int main()
{
	scanf("%d", &TT);
	while(TT--){
		G.clear();
		int H;
		vector<int> A, B;
		scanf("%d", &H);
		int c = 1, h = 1, d = -1, e = -1;
		check(1);
		vector<int> &P = G[1];
		if( P.size() != 1 ){
			A.push_back(1), B.push_back(1);
			dfs(P[0], 1, A);
			dfs(P[1], 1, B);
			if( A.size() == B.size() ){
				h = A.size(), d = P[0], e = P[1];
			}
			else{
				if( A.size() > B.size() ) swap(A, B);
				h = (A.size() + B.size()) / 2;
				int wi = (B.size() - A.size()) / 2;
				c = B[wi], d = B[wi-1], e = B[wi+1];
			}
		}
		while(h < 4 && h < H){
			check(c);
			vector<int> C;
			C.push_back(c);
			for(int x : G[c]){
				if(x == d || x == e ) continue;
				dfs(x, c, C);
			}
			int wi = (C.size() - h) / 2;
			h = (C.size() + h) / 2;
			c = C[wi]; d = C[wi-1]; e = C[wi+1];
		}
		for(int x : G[c]){
			if( x == d || x == e ) continue;
			c = dfs2(H-h-1, x, c);
		}
		printf("! %d\n", c); fflush(stdout);
	}
}