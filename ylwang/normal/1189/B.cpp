#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647/3
#define ll long long
using namespace std;
inline int read()
{
    int num=0;char c=' ';
    for(;c>'9'||c<'0';c=getchar());
    for(;c>='0'&&c<='9';num=(num*10+c-48),c=getchar());
    return num;
}
#define MAXN 100005
int a[MAXN];
int main()
{
	int n = read();
	For(i, 1, n) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	if(a[n-1] + a[n-2] <= a[n]) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if(n & 1) {
		for(int i = n; i >= 1; i -= 2) {
			printf("%d ", a[i]);
		}
		for(int i = 2; i <= n; i += 2) {
			printf("%d ", a[i]);
		}
	} else {
		for(int i = n; i >= 2; i -= 2) {
			printf("%d ", a[i]);
		}
		for(int i = 1; i <= n; i += 2) {
			printf("%d ", a[i]);
		}
	}
	
	return 0;
}