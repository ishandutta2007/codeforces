#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
//#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) ;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num;
}
#define MAXN 300005
int a[MAXN], pos[MAXN];
int ans[MAXN << 3][2], am = 0;
void Swap(int i, int j) {
	ans[++am][0] = i;
	ans[am][1] = j;
	pos[a[i]] = j;
	pos[a[j]] = i;
	swap(a[i], a[j]);
}
signed main()
{
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read(), pos[a[i]] = i;
	for(int i = 1; i <= n; i++) {
		int j = pos[i];
		if(i == j) continue;
		int x = i, y = j;
		if(x > y) swap(x, y);
		if(y - x >= n / 2) Swap(x, y);
		else if(x > n / 2) {
			Swap(1, x);
			Swap(1, y);
			Swap(1, x);
		} else if(y <= n / 2) {
			Swap(y, n);
			Swap(x, n);
			Swap(y, n);
		} else {
			Swap(1, y);
	        Swap(x, n);
	        Swap(1, n);
	        Swap(1, y);
	        Swap(x, n);
		}
	}
	cout << am << endl;
	For(i, 1, am) {
		printf("%d %d\n", ans[i][0], ans[i][1]);
	}
	return 0;
}