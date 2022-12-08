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

vector<int> L;
int D[MX], vst[MX];
int T[2][MX];

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d", D+i);
	for(int i = 1; i <= N; i++){
		if( vst[i] ) continue;
		int c = i, d = 0;
		while(!vst[c]){
			d++;
			vst[c] = true;
			c = D[c];
		}
		L.push_back(d);
	}
	int odd = 0;
	for(int c : L) if( c%2 == 1 ) odd++;
	int mx = min(N-odd, K*2) + max(0, K - (N-odd)/2), mn;
	mx=  min(mx, N);

	map<int, int> X, Y;
	for(int c : L) X[c] += 1;
	for(auto c : X) Y[c.first*c.second] = c.first;

	int *S = T[0], *E = T[1];

	S[0] = 1;
	int t = 0, L = min(N-K, K);
	for(auto cc : Y){
		int a = cc.second, b = cc.first / cc.second;
		t += cc.first;
		for(int i = 0; i <= t && i <= L; i++) E[i] = S[i];
		
		for(int i = 0; i < a; i++){
			int p = 0;
			for(int j = i, q = i-(b+1)*a; j <= L && j <= t; j += a, q += a){
				p += S[j];
				if( q >= 0 ) p -= S[q];
				if( p ) E[j] = 1;
			}
		}
		swap(S, E);
	}
	if( S[L] ) mn = K;
	else mn = K+1;
	printf("%d %d\n", mn, mx);
}