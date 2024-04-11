#include <bits/stdc++.h>
#define N 600005
using namespace std;

typedef long double ld;

int n, T;
int ord[N];
ld x[N], t[N];
ld sx, sxt, need;

inline bool cmp(const int x, const int y) {return t[x] > t[y];}

int main(){
	int i, w;
	scanf("%d%d", &n, &T);
	for(i = 1; i <= n; ++i) {scanf("%d", &w); x[i] = w;}
	for(i = 1; i <= n; ++i) {scanf("%d", &w); t[i] = w - T;}
	for(i = 1; i <= n; ++i) if(t[1] * t[i] <= 0) break;
	if(i > n) return puts("0"), 0;
	for(i = 1; i <= n; ++i) {sx += x[i]; sxt += x[i] * t[i]; ord[i] = i;}
	if(sxt < 0.0) {sxt = -sxt; for(i = 1; i <= n; ++i) t[i] = -t[i];}
	sort(ord + 1, ord + (n + 1), cmp);
	for(w = 1; w <= n; ++w){
		if(t[i = ord[w]] <= 0) break;
		need = sxt / t[i];
		if(need <= x[i]) return printf("%.15lg\n", (double)(sx - need)), 0;
		sxt -= x[i] * t[i]; sx -= x[i];
	}
	printf("%.15lg\n", (double)sx);
	return 0;
}