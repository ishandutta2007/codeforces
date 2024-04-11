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
    int num=0,flag=1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 300005
#define mod 998244353
#define x first
#define y second
pair < int, int > d[MAXN];
map < int , int > a, b;
map < pair < int, int >, int > qwq;
int fac[MAXN] = {1};
signed  main()
{
	int n = read();
	For(i, 1, n) {
		d[i].x = read(), d[i].y = read();
		a[d[i].x] ++; b[d[i].y] ++; qwq[d[i]] ++;
	}
	sort(d+1, d+1+n);
	For(i, 1, n) fac[i] = fac[i-1] * i % mod;
	int ans = fac[n], tmp = 1;
	for(auto i : a) 
		tmp = tmp * fac[i.y] % mod;
	ans = (ans - tmp) % mod;
	tmp = 1;
	for(auto i : b)
		tmp = tmp * fac[i.y] % mod;
	ans = (ans - tmp + mod) % mod;
	tmp = 1;
	for(auto i : qwq) 
		tmp = tmp * fac[i.y] % mod;
	For(i, 1, n-1) if(d[i+1].y < d[i].y) tmp = 0;
	ans = ((ans + tmp) % mod + mod) % mod;
	cout << ans << endl;
	return 0;
}

/*
a ^ b = ans1 ^ ans2
*/