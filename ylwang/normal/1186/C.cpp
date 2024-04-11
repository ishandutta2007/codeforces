#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
string a, b;
int sum[1000005], tot = 0;
signed main()
{
	ios::sync_with_stdio(0);
	cin >> a >> b;
	int n = a.size(), m = b.size();
	a = ' ' + a, b =  ' ' + b;
	For(i, 1, n) {
		sum[i] = sum[i-1] + a[i]-'0';
	}
    For(i, 1, m) {
    	tot = tot + b[i] - '0';
	}
	int ans = 0;
    For(l, 1, n-m+1) {
    	int r = l+m-1;
    	if(!((sum[r] - sum[l-1] - tot) & 1)) 
			ans++;
    	
	}
    cout << ans << endl;
    return 0;
}