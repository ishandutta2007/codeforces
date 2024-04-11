#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long
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
int n, b;
struct Node {
	int val, num;
};
vector < Node > g;
inline int calc(int val, int num ) {
	int qwq = 1, ans = 0;
	while(qwq <= n) {
		if(LLONG_MAX / qwq < val) break;
		qwq *= val;
		ans += n / qwq;
	}
	return ans / num;
}
signed main()
{
    n = read(), b = read();
    int maxi = 0; int gg = sqrt(b);
    int ans = (1ll << 62);
    For(i, 2, gg) {
    	if(b % i == 0) {
    		int num = 0, sum = 0;
    		while(b % i == 0) {
    			b /= i; num++;
			}
			g.push_back((Node) {i, num});
		}
	}
	if(b != 1) g.push_back((Node) {b, 1});
	for(int i = 0; i < g.size(); i++) {
		ans = min(ans, calc(g[i].val, g[i].num));
	}
	cout << ans << endl;
    return 0;
}