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
#define MAXN 500005
int n, k;
signed main()
{
	n = read(), k = read();
	string a, b;
	cin >> a >> b;
	int nowpoint = 1, ans = 0;
	for(int i = 0; i < n; i++) {
		nowpoint <<= 1;
		if(a[i] == 'b') nowpoint--;
		if(b[i] == 'a') nowpoint--;
		nowpoint = max(nowpoint, 0ll);
		nowpoint = min(nowpoint, k+5);
		ans += min(nowpoint, k);
	}
	cout << ans << endl;
    return 0;
}