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
int n, m;
map < int, int > used;
int sum[MAXN];
signed main()
{
	int T = read();
	while(T--) {
		n = read(), m = read();
		used.clear();
		int sum = 0, len = 0, num = 0;
		for(len = 0; ; len++) {
			num = (num + m) % 10;
			if(used[num]) break;
			sum += num;
			used[num] = 1;
		}
		int tot = n / m + 1;
		int ans = tot / len * sum;
		tot %= len;
//		cout << ans << endl;
//		cout << tot << endl;
		for(num = 0; tot;) {
			ans += num; 
			num = (num + m) % 10;
			tot--;
		}
		cout << ans << endl;
	}
    return 0;
}