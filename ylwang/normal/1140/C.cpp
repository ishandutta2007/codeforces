#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 300005
int n, k;
struct Node{
	int x, y;
	bool operator < (const Node b) const {return y > b.y;}
}a[MAXN];
priority_queue < int, vector < int >, greater<int> > q;
int sum;
signed main()
{
	n = read(), k = read();
	For(i, 1, n) a[i].x = read(), a[i].y = read();
	sort(a + 1, a + 1 + n);
	int ans = 0;
	For(i, 1, n) {
		ans = max(ans, a[i].y * (sum+a[i].x));
		if(k > 1) {
			if(q.size() == k-1) {
				if(q.top() < a[i].x) {
					sum = sum - q.top() + a[i].x;
					q.push(a[i].x); q.pop();
				}
			} else {
				sum += a[i].x;
				q.push(a[i].x);
			}
		}
		
	}
	cout << ans << endl;
    return 0;
}