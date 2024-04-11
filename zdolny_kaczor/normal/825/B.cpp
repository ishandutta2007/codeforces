#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#define cerr if(0) cerr
#endif
#define cc(x) x.f, x.s
char in[11][11];
bool check() {
	for (int i = 0; i < 10; ++i)
		for (int k = 0; k < 6; ++k) {
			bool good = true;
			for (int l = 0; l < 5; ++l)
				if (in[i][k + l] != 'X')
					good = false;
			if (good)
				return true;
		}
	for (int i = 0; i < 6; ++i)
		for (int k = 0; k < 10; ++k) {
			bool good = true;
			for (int l = 0; l < 5; ++l)
				if (in[i + l][k] != 'X')
					good = false;
			if (good)
				return true;
		}
	for (int i = 0; i < 6; ++i)
		for (int k = 0; k < 6; ++k) {
			bool good = true;
			for (int l = 0; l < 5; ++l)
				if (in[i + l][k + l] != 'X')
					good = false;
			if (good)
				return true;
		}
	for (int i = 0; i < 6; ++i)
		for (int k = 0; k < 6; ++k) {
			bool good = true;
			for (int l = 0; l < 5; ++l)
				if (in[i + l][k + 4 - l] != 'X')
					good = false;
			if (good)
				return true;
		}
	return false;
}
int main() {
	for (int i = 0; i < 10; ++i)
		scanf("%s", in[i]);
	for (int i = 0; i < 10; ++i)
		for (int k = 0; k < 10; ++k)
			if (in[i][k] == '.') {
				in[i][k] = 'X';
				if (check()) {
					printf("YES\n");
					return 0;
				}
				in[i][k] = '.';
			}
	printf("NO\n");
}