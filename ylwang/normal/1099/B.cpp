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
int main()
{
	int n = read(), ans = (1 << 30);
	int m = sqrt(n);
	if(m * m == n) cout << 2 * m << endl;
	else cout << 2 * m + 1 + (m * (m + 1) < n) << endl;
	return 0;
}