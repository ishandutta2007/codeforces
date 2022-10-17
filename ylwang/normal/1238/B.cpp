#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
#define int long long
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 100005
int a[MAXN], m, R;
signed main()
{
	int T = read();
	while(T--) {
		cin >> m >> R;
		For(i, 1, m) a[i] = read();
		sort(a + 1, a + 1 + m);
		int n = unique(a + 1, a + 1 + m) - a - 1;
		int l = 1, r = n;
		for(int i = 1; i <= n; i++) {
			r = n - i; 
			while(l <= r && a[l] - i * R <= 0)
				l++;
//			cout << l << ' ' << r << ' ' << a[l] << endl;
			if(l > r) {
				printf("%lld\n", i);
				break;
			}
		}
	} 
    return 0;
}