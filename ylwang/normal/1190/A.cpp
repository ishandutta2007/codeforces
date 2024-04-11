#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define int long long
#define reaD() read()
 
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 100005 // 
int a[MAXN], n, m, k;
 
signed main()
{
	n = read(), m = read(), k = read();
	For(i, 1, m) a[i] = read();
	int ans = 0, pos = 0;
	For(i, 1, m) { 
		int div = (a[i] - pos) / k, nownum = 1;  
		if((a[i] - pos) % k == 0) div--;
		while(a[i + 1] <= (div + 1) * k + pos) {
			if(i >= n) break;
			i++, nownum++;
		}
		ans++, pos += nownum;
	}
	cout << ans << endl;
    return 0;
}