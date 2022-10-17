#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long
#define eps 1e-4
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 100005
int s[MAXN], d[MAXN];
signed main()
{
    int n = read(), t = read();
    For(i, 1, n) s[i] = read(), d[i] = read();
    int anst = (1 << 30), ans = 0;
    For(i, 1, n) {
    	int S = s[i];
    	while(S < t) S += d[i];
    	if(anst > (S - t)) anst = (S-t), ans = i;
	}
	cout << ans << endl;
    return 0;
}