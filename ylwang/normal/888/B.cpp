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
#define MAXN 1005
int n;
string a;
int main()
{
	cin >> n >> a;
	a = ' ' + a;
	int nl = 0, nr = 0, nu = 0, nd = 0;
	For(i, 1, n) {
		if(a[i] == 'U') nu++;
		if(a[i] == 'L') nl++;
		if(a[i] == 'R') nr++;
		if(a[i] == 'D') nd++;
	}
	cout << 2 * (min(nl, nr) + min(nu, nd));
	return 0;
}