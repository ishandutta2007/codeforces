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
typedef pair<int,int> pii;

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

const int MX = 3005;

char buf[MX];
int TT, N, M, K, W, a, b, c, d, e, f;

char D[5][5];

int main()
{
	for(int i = 0; i < 4; i++) scanf("%s", D[i]);
	int ch = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if( D[i][j] != '.' ) continue;
			D[i][j] = 'x';

			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 4; j++){
					if( D[i][j] != 'x' ) continue;
					for(int k = 0; k < 8; k++){
						int p = 1;
						for(int l = 1; l < 3; l++){
							int px = i + dx[k] * l, py = j + dy[k] * l;
							if( px < 0 || px >= 4 || py < 0 || py >= 4 ) p = 0;
							else if( D[px][py] != 'x' ) p = 0;
						}
						if( p ) ch = 1;
					}
				}
			}

			D[i][j] = '.';
		}
	}
	if( ch ) printf("YES\n");
	else printf("NO\n");
}