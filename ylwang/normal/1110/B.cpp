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
int a[MAXN];
int dis[MAXN];
bool cmp(int a, int b) {
	return a > b;
}
int main()
{
	int n = read(), m = read(), k = read(); 
	For(i, 1, n) {
		a[i] = read();
	}
	For(i, 1, n-1) {
		dis[i] = a[i+1] - a[i] - 1;
	}
	sort(dis + 1, dis + n, cmp);
	long long ans = a[n] - a[1] + 1;
	For(i, 1, k-1) {
		ans -= dis[i];		
	}
	cout << ans << endl;
	return 0;
}