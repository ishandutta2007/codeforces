#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF 2147483647
#define eps 1e-4
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 10005
int a[MAXN], b[MAXN];
bool cmp(int a, int b) {return a > b;}
signed main()
{
    int n = read(), m = read(), r = read();
    For(i, 1, n) a[i] = read();
	For(i, 1, m) b[i] = read(); 
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m, cmp);
	if(a[1] > b[1]) {
		printf("%d\n", r);
		return 0;
	} else {
		int num = r / a[1];
		r %= a[1];
		cout << num * b[1] + r << endl;
	}
	
    return 0;
}