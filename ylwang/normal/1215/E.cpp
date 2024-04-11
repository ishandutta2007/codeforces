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
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define MAXN 400005
int a[MAXN], n;
//int sum[MAXN];
int S[MAXN], p[25][25];
int f[10000005];
signed main()
{
	cin >> n;
	int m = 0;
	For(i, 1, n) a[i] = read()-1, m = max(m, a[i]);
	For(i, 1, n) {
		For(j, 0, m)
			if(a[i] != j)
				p[j][a[i]] += S[j];
		S[a[i]]++;
	}
	memset(f, 60, sizeof(f));
	f[0] = 0;
	For(i, 0, (1 << (m+1)) - 1) {
//		cout << i << en
		For(j, 0, m) {
			if(!(i & (1 << j))) {
				ll s = f[i];
				For(k, 0, m) if(i & (1 << k))
					s += p[j][k];
				f[i | (1 << j)] = min(f[i | (1 << j)], s);
			}
		}
	}
	cout << f[(1 << (m+1)) - 1] << endl;
	return 0;
	
}