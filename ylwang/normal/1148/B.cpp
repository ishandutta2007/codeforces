#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
//#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) ;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num;
}
#define MAXN 400005
int a[MAXN], b[MAXN];//
signed main()
{
	int n = read(), m = read(), ta = read(), tb = read(), k = read();
	For(i, 1, n) a[i] = read();
	For(i, 1, m) b[i] = read();
	if(k >= n || k >= m) {
		printf("-1\n");
		return 0;
	}
		
	int ans = 0, p = 0;
	For(i, 0, k) {
	    while(a[i+1] + ta > b[p] && p <= m) ++p;
	    if(p + k - i > m) {
	        ans = -1; 
			break;
	    }
	    ans = max(ans, b[p+k-i] + tb);
	}
	cout << ans << endl;
	return 0;
}