#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define int long long
using namespace std;
inline int read()
{
    int num=0;
    char c=' ';
    bool flag=1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
vector < pair<int, int> > ya;
//vector < pair<int, int> > yb; 
main()
{
	int a, b;
	cin >> a >> b;
	int g = sqrt(a);
	For(i, 1, g+1) {
		if(!(a % i)) {
			ya.push_back({i, a / i});
		}
	}
	g = sqrt(b);
	For(i, 1, g+1) {
		if(!(b % i) ) {
			ya.push_back({i, b / i});
		}
	}
	int la = ya.size();
	for(int i = sqrt(a+b); i >= 1; i--) {
		if(!((a + b) % i)) {
			For(j, 0, la-1) {
//				cout << j <<endl;
				if(i >= ya[j].first && (a + b) / i >= ya[j].second) {
					printf("%lld\n", 2 * (i + (a + b) / i));
					return 0;
				}
			}
		}
	}
	return 0;
}