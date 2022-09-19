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
#define free snath
const int MN = 1e6 + 44;
const int A = 26;
const char a = 'a', wild = '?';
int free;
char in[MN], aim[MN];
int couin[A], couaim[A];
vector <char> needed;
bool poss(int x) {
	int needed = 0;
	for (int i = 0; i < A; ++i)
		needed += max(0, couaim[i] * x - couin[i]);
	debug("needed for %d = %d\n", x, needed);
	return needed <= free;
}
int main() {
	scanf("%s%s", in, aim);
	for (int i = 0; in[i]; ++i)
		if (in[i] != wild)
			couin[in[i] - a]++;
		else
			free++;
	for (int i = 0; aim[i]; ++i)
		couaim[aim[i] - a]++;
	int cou = 0;
	for (int i = 0; ; ++i)
		if (!poss(i + 1)) {
			cou = i;
			break;
		}
	debug("cou = %d\n", cou);
	for (int i = 0; i < A; ++i)
		for (int k = 0; k < couaim[i] * cou - couin[i]; ++k)
			needed.push_back(a + i);
	srand(time(NULL));
	while (needed.size() < free)
		needed.push_back(a + rand() % 26);
	random_shuffle(needed.begin(), needed.end());
	for (int i = 0; in[i]; ++i)
		if (in[i] == wild) {
			in[i] = needed.back();
			needed.pop_back();
		}
	printf("%s\n", in);
}