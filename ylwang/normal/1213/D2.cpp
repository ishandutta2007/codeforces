#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define int long long
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005
int n, k;
//struct Node {
//	int val, cnt;
//	bool operator < (const Node b) const {
//		if(val == b.val) return cnt < b.cnt;
//		else return val < b.val;
//	}
//};
//vector < Node > a;
vector < int > a[MAXN];
signed main()
{
	n = read(), k = read();
	For(i, 1, n) {
		int x = read(), cnt = 0;
		while(x) {
			a[x].push_back(cnt);
			x /= 2; cnt++;
		}
		a[0].push_back(cnt);
	}
	int ans = (1 << 30);
	For(i, 0, 200000) {
		if(a[i].size() < k) continue;
		else {
			int sum = 0;
			sort(a[i].begin(), a[i].end());
			For(j, 0, k-1)
				sum += a[i][j];
			ans = min(ans, sum);
		}
	}
	cout << ans << endl;
    return 0;
}