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
int n;
char s[1000005];
signed main()
{
    char c;
    int tot = 0;
    while(cin >> c) {
    	if(s[n] != c) s[++n] = c;
    	else tot++, n--;
	}
	if(tot & 1) printf("YES\n");
	else printf("NO\n");
    return 0;
}