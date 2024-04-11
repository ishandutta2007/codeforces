#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
#define int long long
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
int n, k;
int solve(int v) {
	int ans = 1;
	For(i, 1, v) ans *= (n - i + 1);
	For(i, 1, v) ans /= i; 
	if(v == 0) return 1;
	if(v == 1) return 0;
	if(v == 2) return ans;
	if(v == 3) return 2*ans;
	if(v == 4) return 9*ans;
}
signed main()
{
	n = read(), k = read();
	int ans = 0;
	For(i, 0, k) ans += solve(i);
	cout << ans << endl;

	return 0;
}