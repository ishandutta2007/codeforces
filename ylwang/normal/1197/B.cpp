#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define reaD() read()
using namespace std;
#define int long long //
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 1000005 //
 
int n, a[MAXN];
 
signed main() 
{
	n = read();
	For(i, 1, n) a[i] = read();
	int pos = 1;
	For(i, 1, n) {
		if(a[i] > a[pos]) pos = i;
	}
	For(i, 1, pos-1) {
		if(a[i] > a[i+1]) {
			puts("NO"); exit(0);
		}
	}
	For(i, pos+1, n) {
		if(a[i-1] < a[i]) {
			puts("NO"); exit(0);
		}
	}
	puts("YES"); exit(0);
    return 0;
}