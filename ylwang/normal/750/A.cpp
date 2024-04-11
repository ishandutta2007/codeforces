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
	int n = read(), k = read();
	For(i, 1, n) {
		if(i * (i + 1) * 2.5 + k > 240) {
			cout << i-1 << endl;
			return 0;
		}
	}
	cout << n;
	return 0;
}