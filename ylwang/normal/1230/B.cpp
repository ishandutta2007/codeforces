#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005
int n, k, a[MAXN];
signed main()
{
	cin >> n >> k;
	For(i, 1, n) scanf("%1d", &a[i]);
	if(n == 1 && k == 1) {
		cout << 0 << endl;
		return 0;
	}
	if(k == 0){
		For(i, 1, n) printf("%d", a[i]);
		return 0;
	}
	int num = 0;
	if(a[1] != 1) {
		a[1] = 1;
		num++;
	}
	For(i, 2, n) {
		if(num >= k) break;
		if(a[i] != 0) {
			a[i] = 0;
			num++;
		}
	}
	For(i, 1, n) printf("%d", a[i]);
    return 0;
}