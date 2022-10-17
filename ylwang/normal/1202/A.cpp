#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define reaD() read()
using namespace std;
#define int long long //
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 1005
int a[MAXN], n, k;
signed main()
{
	int T = read();
	while(T--) {
		string s1, s2;
		cin >> s1 >> s2;
		int n1 = s1.size(), n2 = s2.size();
		int p1 = n1 - 1, p2 = n2 - 1;
		for (; p1 >= 0; p1--)
			if (s1[p1] == '1')
				break;
		for (; p2 >= 0; p2--)
			if (s2[p2] == '1')
				break;
		for (int i = p1; i >= 0; i--) {
			if (i + (n2 - p2) - 1 < n1  && !(s1[i] == '0') ) {
				printf("%d\n", n1 - (i + n2 - p2));
				break;
			}
		}
	} 
    return 0;
}