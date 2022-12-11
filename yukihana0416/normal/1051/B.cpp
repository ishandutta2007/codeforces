#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int MOD = (int) 1e9 + 7;
const int maxn = (int) 1e5 + 20;

void work()
{
    LL l, r;
    cin >>l >>r;
    cout <<"YES" <<endl;
    for(LL i = l; i < r; i += 2)
    {
        cout <<i <<" " <<i + 1 <<endl;
    }
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
    work();
    return 0;
}