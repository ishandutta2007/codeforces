#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long
#define int long long
#define eps 1e-4
using namespace std;
inline int read() {
	int num = 0;char c=' ';int flag = 1;
	for(; c>'9'||c<'0'; c=getchar()) if(c=='-') flag = -1;
	for(; c>='0'&&c<='9'; num=(num<<1)+(num<<3)+c-48,c=getchar());
	return num * flag;
}
#define MAXN 100005
int n, a[MAXN], sum = 0;
signed main()
{
	n = read();
	For(i, 1, n) a[i] = read(), sum += a[i];
	sort(a + 1, a + 1 + n);
	if((sum & 1) || a[n] > sum / 2) printf("NO");
	else printf("YES");
	
	return 0;
}