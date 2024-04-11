#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(int i = (k); i <= (j); i++)
#define INF (1 << 30) - 1
#define ll long long
#define int long long 
using namespace std;
inline int read()
{
    int num = 0, flag = 1;
    char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 100005
int a[MAXN], num[MAXN];
signed main()
{
    int n = read(), k = read();
    For(i, 1, n) a[i] = read(), num[a[i]]++;
    sort(a + 1, a + 1 + n);
    int ans = 0, maxi = (n + 1) / 2;
    For(i, 1, k) {
        while(num[i] >= 2) {
            ans += 2;
            num[i] -= 2;
            maxi--;
        }
    }
    For(i, 1, k) {
        if(num[i] && maxi) {
            ans++;
            maxi--;
        }
    }
    cout << ans << endl;
    return 0;
}