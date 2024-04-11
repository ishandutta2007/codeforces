#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
#define eps 1e-4
#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 100005
int a[MAXN];
signed main()
{
    int n = read();
    For(i, 1, n)
    	a[i] = read();
    int Ver = 0, Edg = 0;
    For(i, 1, n) {
        Ver += a[i] * (n - a[i] + 1);
    }
    For(i, 1, n-1) {
        Edg += min(a[i], a[i+1]) * (n - max(a[i], a[i+1]) + 1);
    }
    cout << Ver - Edg << endl;
    return 0;
}