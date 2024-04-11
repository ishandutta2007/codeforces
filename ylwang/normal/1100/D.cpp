#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define x first
#define y second

#define MAXN 1005
#define K 666
bool v[MAXN][MAXN];
pair < int , int > a, b[MAXN];
int c[MAXN];
inline void upd(int dx, int dy) {
    a.x += dx;
    a.y += dy;
    if (v[a.x][a.y]) a.x -= dx;
    printf("%d %d\n", a.x, a.y);
    fflush(stdout);
    int o, p, q;
    scanf("%d %d %d", &o, &p, &q);
    if (o == -1 && p == -1 && q == -1) exit(0);
    v[b[o].x][b[o].y] = 0;
    v[b[o].x=p][b[o].y=q] = 1;
}
signed main()
{
	a.x = read(), a.y = read();
	For(i, 1, K) {
		b[i].x = read(), b[i].y = read();
		v[b[i].x][b[i].y] = 1;
	}
	while (a.x > 500) upd(-1, 0);
    while (a.x < 500) upd(1, 0);
    while (a.y > 500) upd(0, -1);
    while (a.y < 500) upd(0, 1);
    for (int i = 1; i <= K; i++) {
        int k = 0;
        if (b[i].x < 500) k |= 2;
        if (b[i].y < 500) k |= 1;
        c[k]++;
    }
    int t = 0, w = c[0];
    for (int i = 1; i < 4; i++)
        if (c[i] < w) w = c[t=i];
    int dx = (t >> 1) ? 1 : -1, dy = (t & 1) ? 1 : -1;
    while (1) upd(dx, dy);
    return 0;
}