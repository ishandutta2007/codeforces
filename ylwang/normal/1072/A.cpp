#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define ll long long
using namespace std;
inline int read()
{
    int num=0;
    char c=' ';
    int flag=1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}

int main()
{
	int n = read(), m = read(), k = read();
	int ans = 0;
	For(i, 1, k) {
		if(n == 1 || m == 1) {
			ans += n * m;
			break;
		}
		ans += (n + m) * 2 - 4;
		n -= 4 , m -= 4;
		
	}
	cout << ans << endl;
	return 0;
}