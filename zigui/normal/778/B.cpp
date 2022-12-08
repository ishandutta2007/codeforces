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

const int MX = 5005;
const double PI = acos(-1);

auto cmp = [](const pii &l, const pii &r){return l.second !=r.second? l.second < r.second : l.first < r.first; };

char buf[MX];
int TT, N, M, K, W, a, b, c, d, e, f, g, h;

map<string, int> var;
char D[MX][1005];
int G[MX][3];
char O[MX], B[MX];

int main()
{
	var["?"] = 0;
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++){
		scanf("%s%*s", buf);
		var[(string)buf] = i;
		scanf("%s", buf);
		if( '0' <= buf[0] && buf[0] <= '1' ){
			for(int j = 0; j < M; j++) D[i][j] = buf[j];
		}
		else{
			scanf("%s%s", O, B);
			G[i][0] = var[buf], G[i][2] = var[B];
			if( strcmp(O, "AND") == 0 ) G[i][1] = 0;
			else if( strcmp(O, "XOR") == 0 ) G[i][1] = 1;
			else G[i][1] = 2;
		}
	}
	string mx, mn;
	for(int t = 0; t < M; t++){
		int R[2] = {};
		for(int v = 0; v <= 1; v++){
			int V[MX] = {};
			V[0] = v;
			for(int i = 1; i <= N; i++){
				if( D[i][t] ){
					if( D[i][t] == '0') V[i] = 0;
					else V[i] = 1;
				}
				else{
					int a = G[i][0], b = G[i][2], o = G[i][1];
					if( o == 0 ) V[i] = V[a] & V[b];
					if( o == 1 ) V[i] = V[a] ^ V[b];
					if( o == 2 ) V[i] = V[a] | V[b];
				}
			}
			for(int i = 1; i <= N; i++) R[v] += V[i];
		}
		if( R[0] < R[1] ) mx += "1", mn += "0";
		if( R[0] > R[1] ) mx += "0", mn += "1";
		if( R[0] == R[1] ) mx += "0", mn += "0";
	}
	cout << mn << "\n" << mx;
}