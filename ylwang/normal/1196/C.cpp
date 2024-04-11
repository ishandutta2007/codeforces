#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005
int a[MAXN], n;

signed main()
{
	srand(time(0)); 
	int T = read();
	while(T--) {//
		n = read();
		int minx = -100000, maxx = 100000, miny = -100000, maxy = 100000;
		For(i, 1, n) {
			int x = read(), y = read();
			int a = read(), b = read(), c = reaD(), d = read();
			if(!a) minx = max(minx, x);
			if(!b) maxy = min(maxy, y);
			if(!c) maxx = min(maxx, x);
			if(!d) miny = max(miny, y);
		}
		if(minx > maxx || miny > maxy) printf("0\n");
		else printf("1 %d %d\n", minx, miny); 
	}
	
    return 0;
}