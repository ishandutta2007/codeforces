#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647

using namespace std;

inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
inline int calc(char a, char b) {
	if(a > b) swap(a, b);
	return min(b - a, a + 26 - b);
}
signed main()
{
	int n = read();
	string s; cin >> s;
	s = ' ' + s;
	int ans = (1 << 30);
	for(int i = 1; i <= n-3; i++) {
		ans = min(ans, calc(s[i], 'A') + calc(s[i+1], 'C') + calc(s[i+2], 'T') + calc(s[i+3], 'G'));
	}
	cout << ans << endl;
    return 0;
}
/*

*/