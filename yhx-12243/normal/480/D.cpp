#include <bits/stdc++.h>
#define N 510
#define STR 1034
#define T 1034
using namespace std;

struct parcel{
	int i, o, w, s, v;
	parcel (int in = 0, int out = 0, int weight = 0, int strength = 0, int value = 0):
		i(in), o(out), w(weight), s(strength), v(value) {}
	parcel * read() {scanf("%d%d%d%d%d", &i, &o, &w, &s, &v); return this;}
	bool operator < (const parcel &B) const {return o < B.o || o == B.o && i > B.i;}
}p[N];

int n, S;
int f[N][STR], g[T];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

int main(){
	int i, j, k, lj, b;
	scanf("%d%d", &n, &S);
	p[0] = parcel(0, n << 1 | 1, 0, S, 0);
	for(i = 1; i <= n; ++i) p[i].read();
	sort(p, p + (n + 1));
	for(i = 0; i <= n; ++i){
		for(j = p[i].w; j <= S; ++j){
			b = p[i].i;
			lj = min(j - p[i].w, p[i].s);
			g[b] = 0;
			for(k = 0; k < i; ++k){
				if(p[i].i <= p[k].i){ // in(i) < in(k) < out(k) < out(i)
					for(; b < p[k].o; ++b) g[b + 1] = g[b];
					up(g[b], g[p[k].i] + f[k][lj]);
				}
			}
			f[i][j] = g[b] + p[i].v;
		}
	}
	printf("%d\n", f[n][S]);
	return 0;
}