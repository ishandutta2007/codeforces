#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;

LL ppow(LL a,LL n,LL mod)
{
    LL ret=1,now=a;
    while (n)
    {
        if(n&1)
        {
            ret *= now;
            ret %= mod;
        }
        now *= now;
        now %= mod;
        n >>= 1;
    }
    return ret;
}

int main ()
{
    LL n,m,k;
    cin >> n >>m >>k;
    if (n>1 && m>1 && k==1) cout << ppow( ppow(2,n-1,mod),m-1,mod ) <<endl;
    else if (n>1 && m>1 && k==-1)
    {
        if (n%2 != m%2) cout << 0 << endl;
        else cout << ppow( ppow(2,n-1,mod),m-1,mod ) <<endl;
    }
    else
    {
        if (n==1 && m==1)
        {
            cout << 1 << endl;
        }
        else if (k == 1)
        {
            cout << 1 << endl;
        }
        else if(k==-1)
        {
            int mx = max(n,m);
            if (mx%2==1) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}