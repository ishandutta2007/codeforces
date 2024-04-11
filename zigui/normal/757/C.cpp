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

pii D[MX];
ll fac[MX];

int main()
{
	scanf("%d%d", &N, &M);
	const pii P = pii(100033, 100033);
	const pii MM = pii(1000000007, 1000000009);
	pii m = pii(1, 1);
	for(int i = 1; i <= N; i++){
		scanf("%d", &a);
		map<int, int> L;
		for(int j = 1; j <= a; j++){
			scanf("%d", &b);
			L[b] = L[b] + 1;
		}
		for(pii c : L){
			D[c.first] = (m * c.second + D[c.first]) % MM;
		}
		m = m * P % MM;
	}
	sort(D+1, D+M+1);
	
	fac[0] = 1;
	for(int i = 1; i <= M; i++) fac[i] = fac[i-1] * i % 1000000007;
	
	int c = 1;
	ll ans = 1;
	for(int i = 2; i <= M; i++){
		if( D[i] == D[i-1] ) c++;
		else ans = ans * fac[c] % 1000000007, c = 1;
	}
	ans = ans * fac[c] % 1000000007;
	printf("%lld\n", ans);
}