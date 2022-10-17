#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647/3
#define ll long long
#define int long long
using namespace std;
inline int read()
{
    int num=0;char c=' ';
    for(;c>'9'||c<'0';c=getchar());
    for(;c>='0'&&c<='9';num=(num*10+c-48),c=getchar());
    return num;
}

signed main()
{
	int n; cin >> n;
	if(n < 5) {
		printf("NO\n");
		return 0;
	}
	For(x, 1, n) {
		if(x * x >= n) break;
		if((n - x * x - 1 - x) % (2 * x) == 0 && (n - x * x - 1 - x) >= 0) {
			cout << x << ' ' << (n - x * x - 1 - x) / 2 / x << endl; 
			return 0;
		} 
	}
	printf("NO\n");
	return 0;
}