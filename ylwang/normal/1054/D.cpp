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
int a[MAXN], sum = 0;
map < int , int > mp;
signed main()
{
	n = read(), k = read();
	int mx = (1 << k) - 1;
	For(i, 1, n) a[i] = read();
	mp[0] = 1;
	int ans = 0;
	For(i, 1, n) {
		sum ^= a[i];
		int nowa = sum, nowb = sum ^ mx;
		if(mp[nowa] < mp[nowb]) {
			ans += mp[nowa]++;
		} else {
			sum ^= mx;
			ans += mp[nowb]++;
		}
	}
	cout << (n*(n+1))/2-ans << endl;
    return 0;
}