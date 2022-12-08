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
#define next _next

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

//int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
//int dy[8] = {0, 0, -1, 1, 1, -1, -1, 1};
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

const int MX = 1<<18;

char buf[MX];
int TT, N, M, K, W, a, b, c, d, e, f;

int D[MX];

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct node{
	int t[4][4];
};

struct tree{
	node t[MX*2];
	node merge(node &l, node &r){
		node res = {};
		for(int i = 0; i < 4; i++){
			for(int j = i; j < 4; j++){
				res.t[i][j] = 1e9;
				for(int k = i; k <= j; k++){
					res.t[i][j] = min(res.t[i][j], l.t[i][k] + r.t[k][j]);
				}
			}
		}
		return res;
	}
	void set(){
		for(int i = MX-1; i >= 1; i--){
			t[i] = merge(t[i*2], t[i*2+1]);
		}
	}
	node read(int s, int e){
		s += MX, e += MX;
		node l = {}, r = {};
		while(s <= e){
			if( s&1 ) l = merge(l, t[s++]);
			if( ~e&1 ) r = merge(t[e--], r);
			s /= 2, e /= 2;
		}
		return merge(l, r);
	}
}tree;

int next[MX][4], wi[4];

int main()
{
	scanf("%d%d", &N, &M);
	scanf("%s", buf+1);
	for(int i = 1; i <= N; i++){
		int c = -1;
		if( buf[i] == '2' ) c = 0;
		if( buf[i] == '0' ) c = 1;
		if( buf[i] == '1' ) c = 2;
		if( buf[i] == '6' ) c = 3;
		/*
		for(int x = 0; x <= c; x++){
			for(int y = c; y < 4; y++){
				tree.t[i+MX].t[x][y] = 1;
			}
		}*/
		if( c != -1 ) tree.t[i+MX].t[c][c] = 1;
	}
	tree.set();
	for(int i = 1; i <= N; i++){
		if( buf[i] == '2' ) wi[0] = i;
		if( buf[i] == '0' ) wi[1] = i;
		if( buf[i] == '1' ) wi[2] = i;
		if( buf[i] == '7' ) wi[3] = i;
		for(int j = 0; j < 4; j++) next[i][j] = wi[j];
	}

	for(int i = 1; i <= M; i++){
		scanf("%d%d", &a, &b);
		int c[6] = {};
		c[5] = b;
		for(int i = 4; i >= 1; i--) c[i] = next[c[i+1]][i-1];
/*
		c[4] = b;
		c[3] = next[b][3];
		c[2] = next[c[3]][2];
		c[1] = next[c[2]][1];
		c[0] = next[c[1]][0];
*/
		if( c[1] < a ){
			printf("-1\n");
			continue;
		}

		c[0] = a-1; c[4] = b+1;
		node a[4];
		for(int i = 0; i < 4; i++){
			a[i] = tree.read(c[i]+1, c[i+1]-1);
		}
		int ans = 1e9;
		for(int i = 1; i < 4; i++){
			for(int j = max(i, 2); j < 4; j++){
				for(int k = max(j, 3); k < 4; k++){
					int t = a[0].t[0][i] + a[1].t[i][j] + a[2].t[j][k] + a[3].t[k][3];
					ans = min(ans, t);
				}
			}
		}
		printf("%d\n", ans);
	}
}