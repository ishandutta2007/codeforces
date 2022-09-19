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
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif
map <char, char> sym;
bool match(char a, char b) {
	sym[a] = b;
	sym[b] = a;
}
bool match(char a) {
	sym[a] = a;
}
int main() {
	match('O');
	match('o');
	match('x');
	match('X');
	match('H');
	match('I');
	match('M');
	match('U');
	match('V');
	match('v');
	match('Y');
	match('W');
	match('w');
	match('b', 'd');
	match('p', 'q');
	match('T');
	match('A');
	string a;
	cin >> a;
	int n = a.size();
	bool good = true;
	REP(i, n)
		if (sym[a[i]] != a[n - i - 1])
			good = false;
	if (good)
		printf("TAK\n");
	else
		printf("NIE\n");
}