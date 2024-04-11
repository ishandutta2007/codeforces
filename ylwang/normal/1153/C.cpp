#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long
#define eps 1e-4
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 500005
string s;
int sum[MAXN], cnt = 0;
signed main()
{
	ios::sync_with_stdio(0);
    int n; cin >> n;
    cin >> s; s = ' ' + s;
    For(i, 1, n) if(s[i] == '(') cnt++;
    if(cnt > n / 2) {
    	printf(":(\n");
    	return 0;
	}
	For(i, 1, n) {
		if(s[i] == '?') {
			if(cnt < n / 2) s[i] = '(', cnt++;
			else s[i] = ')';
		}
	}
	For(i, 1, n) {
    	sum[i] = sum[i-1];
    	if(s[i] == '(') sum[i]++;
    	else if(s[i] == ')') sum[i]--;
    	if(sum[i] <= 0 && i != n) {
    		printf(":(\n");
    		return 0;
		}
	}
	if(sum[n] != 0) {
		printf(":(\n");
    	return 0;
	}
	For(i, 1, n) cout << s[i];
    return 0;
}