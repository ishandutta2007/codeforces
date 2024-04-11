#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
 
#define int long long//
 
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200200 //
int n, a[MAXN], m;
signed main()
{
	n = read(), m = read();
	int qaq = __gcd(n, m);
	int Qnum = read();
	while(Qnum--) {
		int sx = read(), sy = read(), ex = read(), ey = read();
		if(sx == 2 && ex == 1) {
			swap(sx, ex); swap(sy, ey);
		}
		sy--, ey--;
		if(sx == 1 && ex == 1) {
			if(sy/(n/qaq) == ey/(n/qaq)) {
				printf("YES\n");
			} else printf("NO\n");
		} else if(sx == 1 && ex == 2) {
			if(sy/(n/qaq) == ey/(m/qaq)) {
//				cout << sy/(n/qaq) << ' ' << ey/(m/qaq) << endl;
				printf("YES\n");
			} else printf("NO\n");
		} else {
			if(sy/(m/qaq) == ey/(m/qaq)) {
				printf("YES\n");
			} else printf("NO\n");
		}
	}
    return 0;
}