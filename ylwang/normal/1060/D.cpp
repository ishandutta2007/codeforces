#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
using namespace std;
inline int read()
{
    int num = 0;
    char c=' ';
    bool flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
//D1e5
//iLiRiLiRi<=1e9
//
#define N 100005
#define ll long long
ll a[N], b[N];
int main()
{
	ll n = read();
	For(i, 1, n) {
		scanf("%lld %lld", &a[i], &b[i]); 
	} 
	sort(a + 1, a + 1 + n); 
	sort(b + 1, b + 1 + n);
	ll ans = 0; 
	For(i, 1, n) {
		if(a[i] > b[i]) ans += a[i];
		else ans += b[i];
	}
	cout << ans + n << endl; 
    return 0;
}