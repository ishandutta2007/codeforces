#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define pb push_back
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(register int i = (k); i >= (j); i--)
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define int long long
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 1000005
int n, k;
int a[1000005];
signed main()
{
	cin >> n >> k;
	if(k < n * (n + 1) / 2) {
		printf("-1\n");
		return 0;
	}
	For(i, 1, n) a[i] = i;
	
	int sum = n * (n + 1) / 2;
	int del = k - sum, ans = sum;
	for(int i = n; i >= (n+2)/2; i--) {
		if(i - (n-i+1) <= del) {
			del -= (i - (n - i + 1));
			swap(a[i], a[n-i+1]);
		} else {
			int pos = i - del;
			swap(a[i], a[pos]);
			del = 0;
			break;
		}
	}
	cout << k - del << endl;
	For(i, 1, n) printf("%d ", i);printf("\n");
	For(i, 1, n) printf("%d ", a[i]);
    return 0;
}