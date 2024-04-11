#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
#define ll long long
using namespace std;
inline int read()
{
    int num=0,flag=1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}

int main()
{
	int T = read();
	while(T--) {
		int b = read(), p = read(), f = read();
		int h = read(), c = read();
		if(h < c) {
			swap(p, f);
			swap(h, c);
		}
		int maxi = b / 2;
		if(maxi < p) {
			printf("%d\n", maxi * h);
		} else if(p + f > maxi) {
			printf("%d\n", p * h + (maxi-p) * c);
		} else {
			printf("%d\n", p * h + f * c);
		}
	}
	return 0;
}