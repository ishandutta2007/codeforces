#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define int long long 
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 200005 // 
int a[MAXN], ans = 0;
map < int , int > qwq;
map < int , int > flag;
signed main()
{
	int n = read();
	For(i, 1, n) 
		a[i] = read();
	For(i, 1, n)
		ans += a[i], qwq[a[i]]++;
	if(n == 1) {
		if(ans % 2 == 0) {
			printf("cslnb\n");
		} else {
			printf("sjfnb\n");
		}
		return 0;
	}
	int num = 0, pos =0 ;
	for (auto x :qwq) {
        if (x.second == 2) {
            num++;
            pos = x.first;
        } else if (x.second >= 3) {
            num = 100000000;
        }
    }
	if(qwq[0] >= 2) num = 100000000;
	if(num >= 2) {
		printf("cslnb\n");
		return 0;
	} else if(num == 1) {
		if(qwq[pos - 1] == 1) {
			printf("cslnb\n");
			return 0;
		}
	}
	if((ans - n * (n - 1) / 2) % 2 == 0) {
		printf("cslnb\n");
	}else {
		printf("sjfnb\n");
	}
    return 0;
}