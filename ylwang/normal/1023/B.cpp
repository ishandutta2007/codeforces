#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long

#define int long long

using namespace std;
inline int read() {
    int num = 0, flag = 1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
int n, m;
signed main()
{
	n = read(), m = read();
	if(n + n - 1 < m) {
		puts("0");
		return 0;
	}
	if(m < n + 1) {
		printf("%lld\n", (m-1)/2);
		return 0;
	}
	int mini = m - n;
	cout << (n - mini + 1) / 2 << endl;
    return 0;
}