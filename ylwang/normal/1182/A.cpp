#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
#define int long long
#define ll long long
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
	int n = read();
	if(n & 1) {
		cout << 0 << endl;
	} else {
		int ans = 1;
		For(i, 1, n/2) {
			ans *= 2;
		}
		cout << ans << endl;
	}
    return 0;
}