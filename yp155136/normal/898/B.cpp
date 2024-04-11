#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int extgcd(int a,int b,int &x,int &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        int d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
        return d;
    }
}

int main ()
{
    int n,a,b;
    cin >> n >> a >> b;
    if (n%__gcd(a,b) != 0)
    {
        puts("NO");
        return 0;
    }
    int x,y;
    int ret=extgcd(a,b,x,y);
    long long ans1=x*1LL*(n/ret),ans2 = y*1LL*(n/ret);
    while (ans1 < 0)
    {
        ans1 += b;
        ans2 -= a;
    }
    while (ans2 < 0)
    {
        ans2 += a;
        ans1 -= b;
    }
    if (ans1 < 0 || ans2 < 0) puts("NO");
    else
    {
        puts("YES");
        cout << ans1<<' '<<ans2<<endl;
    }
}