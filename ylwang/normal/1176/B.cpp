#pragma GCC optimize(3)
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
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 205
int a[MAXN], n, num[3];

signed main()
{
	int T = read();
	while(T--) {
		num[0] = num[1] = num[2] = 0;
		cin >> n;
		For(i, 1, n) a[i] = read() % 3;
		For(i, 1, n) num[a[i]]++;
		if(num[1] > num[2]) swap(num[1], num[2]);
		int ans = num[0] + num[1];
		printf("%d\n", ans + (num[2]-num[1]) / 3);
	}
    return 0;
}