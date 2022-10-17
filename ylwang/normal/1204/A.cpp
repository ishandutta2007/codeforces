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
 
signed main()
{
	string s; cin >> s;
	int n = s.size();
	bool flag = 1;
	for(int i = n-1; i >= 1; i --)  {
		if(s[i] != '0') {
			flag = 0;
		}
	}
	if(!flag || (n % 2 == 0) ) {
		cout <<(n+1)/2<< endl;
	} else {
		cout << (n-1) / 2 << endl;
	}
    return 0;
}