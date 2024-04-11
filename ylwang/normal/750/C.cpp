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
#define MAXN 300005
int c[MAXN], d[MAXN], n;
int sum[MAXN];
int mxr = (1 << 30), mnr = -(1 << 30);
int main()
{
	n = read();
	For(i, 1, n) c[i] = read(), d[i] = read();
	For(i, 1, n) {
		sum[i] = sum[i-1] + c[i];
		if(d[i] == 1) {
			mnr = max(mnr, 1900-sum[i-1]);
		} else {
			mxr = min(mxr, 1899-sum[i-1]);
		}
	}
//	cout << mxr << ' ' << mnr << endl;
	if(mxr == (1 << 30)) {
		printf("Infinity");
	} else if(mnr > mxr) {
		printf("Impossible");
	} else {
		cout << mxr + sum[n] << endl;
	}
	return 0;
}