#pragma GCC optimize(3)
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define INF (1 << 30) - 1
#define ull unsigned long long
#define reaD() read()
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}

int main()
{
	int Q = read();
	while(Q--) {
		int l1 = read(), r1 = read(), l2 = read(), r2 = read();
		if(l1 > l2) {
			swap(l1, l2);
			swap(r1, r2);
			cout << r2 << ' ' << l1 << endl;
		}
		else cout << l1 << ' ' << r2 << endl;
	}
	return 0;
}