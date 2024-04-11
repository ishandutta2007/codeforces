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

const int MX = 405;
const double PI = acos(-1);

auto cmp = [](const pii &l, const pii &r){return l.second !=r.second? l.second < r.second : l.first < r.first; };

char buf[MX];
int TT, N, M, K, W, a, b, c, d, e, f, g, h;

char A[MX][MX], B[MX][MX];
vector<pii> ans;

#define assert(x) { printf("%d >>\n", x); }

void Do(int x, int y)
{
	ans.push_back(pii(x, y));
	if( A[x][y] == 'L' && A[x+1][y] == 'L'){
		A[x][y] = 'U';    A[x][y+1] = 'U';
		A[x+1][y] = 'D';  A[x+1][y+1] = 'D';
	}
	else if( A[x][y] == 'U' && A[x][y+1] == 'U'){
		A[x][y] = 'L';    A[x][y+1] = 'R';
		A[x+1][y] = 'L';  A[x+1][y+1] = 'R';
	}
	else assert(1);
}

void solve(int x, int y)
{
	for(int t = 0; t < 2; t++){
		if( A[x][y] == 'L' && A[x+1][y] == 'L'){
			Do(x, y); break;
		}
		else if( A[x][y] == 'U' && A[x][y+1] == 'U'){
			Do(x, y); break;
		}
		else if( t == 0 && A[x][y] == 'U'){
			if( A[x][y+1] == 'D' ) solve(x-1, y+1);
			if( A[x+1][y+1] == 'U' ) solve(x+1, y+1);
			Do(x, y+1);
		}
		else if( t == 0 && A[x][y] == 'L'){
			solve(x+1, y);
		}
		else assert(2);
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
	for(int i = 1; i <= N; i++) scanf("%s", B[i] + 1);
	for(int i = 2; i <= N+M; i++){
		for(int j = i; j >= 1; j--){
			int x = j, y = i-j;
			if( x <= 0 || x > N || y <= 0 || y > M ) continue;
			if( A[x][y] == B[x][y] ) continue;
			if( A[x][y] == 'U' && B[x][y] == 'L' ){
				solve(x, y);
			}
			else if( A[x][y] == 'L' && B[x][y] == 'U'){
				solve(x, y);
			}
		}
	}
	printf("%d\n", ans.size());
	for(pii c : ans) printf("%d %d\n", c.first, c.second);
}