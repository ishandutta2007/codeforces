#include <iostream>
using namespace std;
int n, a[10001];
int ans;
int main()
{
    cin >> n;
    for (register int i = 1;i <= n;i ++) cin >> a[i];
    ans = n;
    for (int i = 1;i <= n;++ i)
    {
        if(!a[i])
        {
            if(!a[i - 1] || !a[i + 1])
            {
                ans --;
            }
        }
    }
    cout << ans;
}