#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;
const LL mod = 1000000007;

LL ppow(LL a,LL n)
{
    LL ret=1,now=a;
    while (n)
    {
        if (n&1)
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

LL Val(LL x)
{
    return (x%mod+mod)%mod;
}

vector<LL> prime_factor;

#define SZ(x) ((int)(x).size())

LL ans=0;

LL y;

LL kirino;

LL dfs(int now_id,LL pre,LL u)
{
    //cout << "now_id = "<<now_id << endl;
    //cout <<"SZ = "<<SZ(prime_factor)<<endl;
    if (now_id == SZ(prime_factor))
    {
        ans += u * ppow(2,kirino/pre-1);
        ans = Val(ans);
    }
    else
    {
        dfs(now_id+1,pre*prime_factor[now_id],u*-1);
        dfs(now_id+1,pre,u);
    }
}

int main ()
{
    LL x;
    cin >> x >> y;
    if (y%x != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    y /= x;
    kirino = y;
    if (y == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for(LL i=2;i*i <= y;i++)
    {
        if (y%i==0)
        {
            prime_factor.push_back(i);
            while (y%i==0) y/=i;
        }
    }
    if (y != 1)
    {
        prime_factor.push_back(y);
    }
    dfs(0,1,1);
    printf("%lld\n",ans);
}