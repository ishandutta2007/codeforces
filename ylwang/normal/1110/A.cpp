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
	int b = read(), k = read();
	if(b & 1) {
		int ans=0, a;
		For(i, 1, k)  {
			a = read();
			ans += (a&1);
		}
		printf("%s\n", (ans&1) ? "odd": "even");
	} else {
		int a;
		For(i, 1, k) {
			a = read();
		}
		printf("%s\n", (a&1) ? "odd": "even");
	}
	return 0;
}