#include<bits/stdc++.h>
#define ll long long
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
using namespace std;
inline int gcd(int x,int y){while(x^=y^=x^=y%=x);return y;}
inline int read()
{
    int num = 0;
    char c=' ';
    int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
struct node {
	int s, e;
}a[100005];
bool cmp(node a, node b) {
	return a.s < b.s;
}
int main()
{
    int n = read(), l = read(), A = read(); 
	For(i, 1, n) {
		a[i].s = read();
		int val = read();
		a[i].e = a[i].s + val;
	}
	sort(a + 1, a + 1 + n, cmp);
	long long ans = 0;
	For(i, 2, n) {
		ans += (a[i].s - a[i-1].e) / A;
	}
	cout << ans + (l - a[n].e) / A + (a[1].s - 0) / A << endl;
    return 0;
}