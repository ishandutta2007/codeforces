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

const int MX = 100005;

char buf[MX];
int TT, N, M, K, W, a, b, c, d, e, f;

int D[MX];

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct cell{
	pii c;
	int d;
	cell(pii c, int d):c(c), d(d){}
	bool operator<(const cell &l)const{
		if( c != l.c ) return c < l.c;
		return d < l.d;
	}
};

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", D+i);

	set<cell> A, B;
	set<pii> L;
	A.insert(cell(pii(0, -1), 0));
	for(int i = 1; i <= N; i++){
		for(cell c : A){
			pii x = c.c;
			int d = c.d;
			for(int j = 0; j < D[i]; j++){
				x = x + pii(dx[d], dy[d]);
				L.insert(x);
			}
			B.insert(cell(x, (d+1)%8));
			B.insert(cell(x, (d+7)%8));
		}
		A.clear();
		swap(A, B);
	}
	printf("%d\n", L.size());
}