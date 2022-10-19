#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(long long i = (k); i <= (j); i++)
#define INF 2147483647
using namespace std;
inline long long read()
{
    long long num = 0;
    char c=' ';
    bool flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define ll long long
ll calc(ll x) {
	ll ans = 0;
	while (x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}
int main()
{
	ll x = 0;
	ll n = read();
	while ((x * 10 + 9) <= n)
		x = x * 10 + 9;
	cout << calc(x) + calc(n - x) << endl;
    return 0;
}