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
#define left santheo
const int A = 26, MN = 1e5 + 44;
int left[A];
char in[MN];
vector <char> stos;
int main() {
	scanf("%s", in);
	int n;
	for (n = 0; in[n]; ++n) {
		left[in[n] - 'a']++;
	}
	int pos = 0;
	while (pos < n) {
		bool insert;
		if (stos.empty()) {
			insert = true;
		}
		else {
			int lowest = A;
			for (int i = 0; i < A; ++i) {
				if (left[i]) {
					lowest = i;
					break;
				}
			}
			insert = (lowest + 'a' < stos.back());
		}
		if (insert) {
			stos.push_back(in[pos]);
			left[in[pos] - 'a']--;
			pos++;
		}
		else {
			putchar(stos.back());
			stos.pop_back();
		}
	}
	while (!stos.empty()) {
		putchar(stos.back());
		stos.pop_back();
	}
}