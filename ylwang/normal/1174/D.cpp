#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define int long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 500005
int a[MAXN], n, k;
int sum[MAXN];
bool used[MAXN];
signed main()
{
	n = read(), k = reaD();
	int m = (1 << n) - 1;
	if(k > m) {
		cout << m << endl;
		For(i, 1, m) sum[i] = i;
		For(i, 1, m)
			printf("%d ", sum[i] ^ sum[i-1]); 
	} else {
		int cnt = 0;
		used[k] = 1;
		For(i, 1, m) {
			if(!used[i]) {
				sum[++cnt] = i;
				used[i ^ k] = used[i] = 1;
			}
		}
//		For(i, 1, cnt) cout << sum[i] << endl;
		cout << cnt << endl;
		For(i, 1, cnt)
			printf("%d ", sum[i] ^ sum[i-1]); 
	}
    return 0;
}