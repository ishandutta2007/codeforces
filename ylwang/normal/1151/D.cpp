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
#define MAXN 100005
int n;
struct Node {
	int x, y;
	bool operator < (const Node b) const {return x-y > b.x-b.y;}
}a[MAXN];
signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) {
		a[i].x = read(), a[i].y = read();
	}
	sort(a + 1, a + 1 + n);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += a[i].x * (i - 1) + a[i].y * (n - i);
	}
	cout << ans << endl;
    return 0;
}
/*

*/