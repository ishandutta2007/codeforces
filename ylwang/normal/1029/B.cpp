#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
using namespace std;
inline int read()
{
    int num = 0;
    char c=' ';
    bool flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define N 200005
int a[N];
int main()
{
	int n = read();
	For(i, 1, n) {
		a[i] = read();
	}
	int ans = 0;
	int sum = 1;
	For(i, 2, n) {
		if(a[i-1] * 2 >= a[i]) {
			sum++;
		} else {
			ans = max(ans, sum);
			sum = 1;
		}
	}
	ans = max(ans, sum);
	cout << ans << endl;

    return 0;
}