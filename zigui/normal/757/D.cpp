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
typedef pair<ll, ll> pii;

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

void file(){
	freopen("lasers.in","r", stdin);
	freopen("lasers.out", "w", stdout);
}

int coor(vector<int> &L, int x){
	return lower_bound(L.begin(), L.end(), x) - L.begin();
}

const int MX = 1000005;
const double PI = acos(-1);

char buf[MX];
int TT, N, M, K, W, a, b, c, d, e, f;

int T[80][1<<20];

void _add(int &x, int y){ x = (x+y) % MM; }

int main()
{
	scanf("%d%s", &N, buf+1);
	T[0][0] = 1;
	for(int i = 1; i <= N; i++){
		T[i][0] = 1;
		int su = 0;
		for(int j = i; j >= 1; j--){
			if( i-j <= 20 ) su += (1<<(i-j)) * (buf[j] - '0');
			else if( buf[j] == '1' ) break;
			if( su > 20 ) break;
			if( su == 0 ) continue;
			for(int k = 0; k < 1<<20; k++){
				if( k&1<<su-1 );
				else continue;
				_add(T[i][k], T[j-1][k^(1<<su-1)]);
				_add(T[i][k], T[j-1][k]);
			}
		}
	}
	int ans = 0;
	for(int j = N; j >= 1; j--){
		for(int i = 1; i <= 20; i++){
			_add(ans, T[j][(1<<i)-1]);
		}
	}//hohkhjk
	printf("%d\n", ans);
}