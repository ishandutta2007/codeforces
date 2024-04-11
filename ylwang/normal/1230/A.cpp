#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
int a1, a2, a3, a4;
signed main()
{
	cin >> a1 >> a2 >> a3 >> a4;
	if(a1 == a2 + a3 + a4) printf("YES");
	else if(a2 == a1 + a3 + a4) printf("YES");
	else if(a3 == a2 + a1 + a4) printf("YES");
	else if(a4 == a2 + a3 + a1) printf("YES");
	else if(a1 + a2 == a3 + a4) printf("YES");
	else if(a1 + a3 == a2 + a4) printf("YES");
	else if(a1 + a4 == a2 + a3) printf("YES");
	else printf("NO");
    return 0;
}