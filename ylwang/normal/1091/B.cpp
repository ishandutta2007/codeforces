// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 200005
int a[MAXN], b[MAXN], n, ans = 0;
signed main()
{
	int n = read();
	int ansx = 0, ansy = 0;
	For(i, 1, n*2) {
		ansx += read(), ansy += read();
	}
	cout << ansx / n << ' ' << ansy / n << endl;
    return 0;
}