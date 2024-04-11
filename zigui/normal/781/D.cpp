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
typedef pair<double, double> pdd;
typedef tuple<int,int,int> t3;

const int MM = 1000000007;

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

struct mat{
	bitset<500> t[500];
	mat operator*(mat l)const{
		mat x;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				x.t[i][j] = 0;
			}
		}
		for(int i = 0; i < N; i++){
			for(int j = i+1; j < N; j++){
				int t = l.t[i][j];
				l.t[i][j] = l.t[j][i];
				l.t[j][i] = t;
			}
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				bitset<500> p = t[i] & l.t[j];
				if( p.any() ) x.t[i][j] = 1;
			}
		}
		for(int i = 0; i < N; i++){
			for(int j = i+1; j < N; j++){
				int t = l.t[i][j];
				l.t[i][j] = l.t[j][i];
				l.t[j][i] = t;
			}
		}
		return x;
	}
};

mat X[64], Y[64];

int main()
{
	scanf("%d%d", &N, &M);
	mat P, B;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			P.t[i][j] = 0;
			B.t[i][j] = 0;
		}
	}
	for(int i = 1; i <= M; i++){
		scanf("%d%d%d", &a, &b, &c);
		if( c == 0 ) P.t[a-1][b-1] = 1;
		else B.t[a-1][b-1] = 1;
	}
	X[0] = P, Y[0] = B;
	for(int i = 1; i <= 60; i++){
		X[i] = X[i-1] * Y[i-1];
		Y[i] = Y[i-1] * X[i-1];
	}
	mat c;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			c.t[i][j] = i==j;
		}
	}
	int f = 0;
	ll ans = 0;
	for(int t = 60; t >= 0; t--){
		mat p;
		if( f == 0 ) p = c * X[t];
		else p = c * Y[t];
		int ch = 0;
		for(int i = 0; i < N; i++){
			if( p.t[i].any() ){
				ch = 1;
				break;
			}
		}
		if( ch ) c = p, ans += 1ll<<t, f = !f;
	}
	if( ans <= 1e18 ) printf("%lld\n", ans);
	else printf("-1");
}