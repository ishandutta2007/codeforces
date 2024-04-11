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
#define MAXN 1005
inline int ceil(int a, int b) {
	return (a + b - 1) /  b;
}
signed main()
{
	int a = read(), b = read();
	int n = a + b, ans = 0;
	for(int l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		int g = (n / l);
		int la = ceil(a, g+1), lb = ceil(b, g+1);
		int ha = a / g, hb = b / g;
		if(la <= ha && lb <= hb)
			ans += max(0, min(r, ha + hb) - max(l, la + lb) + 1);
	}
	cout << ans << endl;
    return 0;
}