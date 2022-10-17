#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
using namespace std;
inline int read()
{
    int num=0,flag=1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 100005
int a[MAXN], b[MAXN];
int g[MAXN], g2[MAXN];
int main()
{
	int n = read();
	For(i, 1, n) {
		a[i] = read();
	}
	For(i, 1, n) {
		g[i] = a[i] - a[i-1];
	}
	For(i, 1, n) {
		b[i] = read();
	}
	if(a[1] != b[1] || a[n] != b[n]) {
		printf("No\n");
		return 0;
	}
	For(i, 1, n) {
		g2[i] = b[i] - b[i-1];
	}
	sort(g+1, g+1+n);
	sort(g2+1, g2+1+n);
	For(i, 1, n) {
		if(g[i] != g2[i]) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}