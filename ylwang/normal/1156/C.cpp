#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num = 0, flag = 1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define int long long
#define MAXN 400005
int p[MAXN], a[MAXN];
signed main()
{
	int n = read(), z = read();
	For(i, 1, n) a[i] = read();
	sort(a + 1, a + 1 + n);
	int pos = n / 2, ans = 0;
	p[0] = 0;
	for(int i = n; i >= 1; i--) {
		if(p[i]) continue;
		while(a[i] - a[pos] < z || p[pos] == 1) {pos--;}
		if(pos >= 1) ans++, p[pos--] = 1;
	}
	printf("%d\n", ans);
	return 0;
 }