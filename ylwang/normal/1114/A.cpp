
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
 
signed main()
{
    int a = read(), b = read(), c = read();
    int x = read(), y = read(), z = read();
    if(a <= x&& b <= x + y - a&& c <= x + y + z - a - b) {
    	printf("YES\n");
	} else printf("NO\n");
    return 0;
}