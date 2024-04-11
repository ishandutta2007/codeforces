#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
#define int long long
using namespace std;
inline int read()
{
    int num=0,flag=1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
signed main()
{
	int n = read(), k = read();
	int ans = 0;
	int tot = (n) * (n + 1) / 2;
	if(tot == k) {
		cout << 0 << endl;
		return 0;
	}
	while(1) {
		tot -= n; n--; tot--; ans++;
		if(tot == k) {
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}