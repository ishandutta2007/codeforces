#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) ;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num;
}

signed main()
{
	int a = read(), b = read(), c = read();
	int ans = 2 * c;
	if(a > b) swap(a, b);
	if(b >= a + 1) cout << ans + a + a + 1 << endl;
	else cout << ans + 2 * a << endl;
	return 0;
}