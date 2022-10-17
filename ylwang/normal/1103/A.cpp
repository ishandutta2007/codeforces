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
#define MAXN 1005
int n;
string s;

signed main()
{
    cin >> s; n = s.size(); s = ' ' + s;
    int nownum1 = 0, nownum2 = 1;
    For(i, 1, n) {
    	if(s[i] == '0') {
    		++nownum1;
    		printf("%d %d\n", 1, (nownum1 % 4) == 0 ? 4 : nownum1 % 4);
		} else {
			++nownum2, ++nownum2;
			printf("%d %d\n", 4, (nownum2 % 4) == 0 ? 4 : nownum2 % 4);
		}//
	}
    return 0;
}