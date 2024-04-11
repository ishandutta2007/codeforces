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
#define MOD 1000000007
#define MAXN 100005
int n = 0, a[MAXN];
string s;
signed main()
{
    cin >> s;
    For(i, 1, s.size()) {
    	if(s[i-1] == 'a') a[++n] = 1;
    	else if(s[i-1] == 'b') a[++n] = 0;
	}
	int ans = 1, num = 1;
	For(i, 1, n) {
		if(a[i] == 0 && num != 0) {
			ans = (ans * num) % MOD;
			num = 1;
		} 
		if(a[i]) num++;
	} 
	cout << (ans*num)%MOD-1 << endl;
    return 0;
}