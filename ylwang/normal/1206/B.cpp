#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
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
#define int long long
#define MAXN 100005 
int a[MAXN], n;
int ans = 0, cnt, num0 = 0;
signed main()
{
	n = read();
	For(i, 1, n) scanf("%I64d", &a[i]);
	For(i, 1, n) {
		if(a[i] < 0) {
			ans += -1-a[i];
			a[i] = -1;
			cnt++;
		} else if(a[i] > 0) {
			ans += a[i]-1;
			a[i] = 1;
		} else {
			num0++;
		}
	}
//	cout << ans << endl;
	if(cnt & 1) {
		if(num0 > 0) {
			cout << ans + num0 << endl;
		} else {
			cout << ans + 2 << endl;
		}
	} else {
		cout << ans + num0 << endl;
	}
    return 0;
}