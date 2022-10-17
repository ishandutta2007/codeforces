#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
#define Pair pair<int,int>
using namespace std;
inline int read()
{
    int num=0,flag=1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
typedef unsigned long long ull;
int a[26];
int main()
{
	int p, x, y;
	while (~scanf("%d%d%d", &p, &x, &y)) {
		bool flag = 0;
		int ans = 0;
		for (int i = x; i >= y; i -= 50) {
			int s = (i / 50) % 475;
			For(j, 1, 25) {
				s = (s * 96 + 42) % 475;
				a[j] = s + 26;
				if (a[j] == p && i >= y)
				{
					flag = 1;
					break;
				}
			}
		}
		if (!flag) {
			int cur = x;
			while (!flag) {
				int s = (cur / 50) % 475;
				for (int i = 1; i <= 25; i++)
				{
					s = (s * 96 + 42) % 475;
					a[i] = s + 26;
					if (a[i] == p)
					{
						flag = 1;
						ans = (cur + 50 - x) / 100;
						break;
					}
				}
				cur += 50;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}