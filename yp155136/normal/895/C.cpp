#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

typedef long long LL;
const int N = 100005;
const int K = 19;

int p[K] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int a[N];
int mask[N];

int get_mask(int num)
{
    int ret=0;
    for (int i=0;K>i;i++)
    {
        while (num%p[i]==0)
        {
            ret ^= (1<<i);
            num /= p[i];
        }
    }
    return ret;
}

long long cnt[2][(1<<K)];
bool hhave[2][(1<<K)];
vector<int> have_mask[2];

LL _[76];

vector<int> masks;

const LL mod = 1e9 + 7;

LL ppow(LL a,LL n,LL mod)
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
        n>>=1;
    }
    return ret;
}

LL f[N],revf[N];

void build()
{
    f[0] = revf[0] = 1;
    for (int i=1;N>i;i++)
    {
        f[i] = f[i-1]*i;
        f[i] %= mod;
        revf[i] = ppow(f[i],mod-2,mod);
    }
}

LL C(LL n,LL m)
{
    return f[n] * revf[m] % mod * revf[n-m] % mod;
}


LL gao(LL x)
{
    LL ret=0;
    for (int i=2;x>=i;i+=2)
    {
        ret += C(x,i);
        ret %= mod;
    }
    return ret;
}

int main ()
{
    build();
    //cout << C(7,4)<<endl;
    int n;
    scanf("%d",&n);
    masks.push_back(0);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        mask[i] = get_mask(a[i]);
        if (mask[i] >= (1<<11))
        {
            mask[i] = -1;
            _[ a[i] ]++;
        }
        else
        {
            masks.push_back(mask[i]);
        }
    }
    long long ans=0;
    #define SZ(x) ((int)(x).size())
    for (int i=1;SZ(masks)>i;i++)
    {
        int now=(i%2);
        int last = 1-now;
        int nowmask = masks[i];
        //cout << "nowmask = "<<nowmask<<endl;
        have_mask[now] = have_mask[last];
        for (LL i:have_mask[last])
        {
            cnt[now][i] = cnt[last][i];
        }
        vector<int> add_last;
        for (LL i:have_mask[last])
        {
            cnt[ now ][ (i^nowmask) ] += cnt[last][i];
            cnt[ now ][ (i^nowmask) ] %= mod;
            if(!hhave[now][ (i^nowmask) ])
            {
                have_mask[now].push_back( (i^nowmask) );
                hhave[now][ (i^nowmask) ] = 1;
                hhave[last][ (i^nowmask) ] = 1;
                add_last.push_back((i^nowmask));
            }
        }
        cnt[now][nowmask]++;
        if (!hhave[now][(nowmask)])
        {
            have_mask[now].push_back(nowmask);
            hhave[now][ (nowmask) ] = 1;
            hhave[last][ (nowmask) ] = 1;
            add_last.push_back((nowmask));
        }
        for (int i:add_last)
        {
            //cout << "last = "<<last<<" , i = "<<i<<endl;
            have_mask[last].push_back(i);
        }
        for (LL i:have_mask[now])
        {
            //cout << "i = "<<i<<endl;
            cnt[now][i] %= mod;
        }
    }
    LL ans1 = cnt[ (SZ(masks)-1)%2 ][0]%mod;
    //cout << "ans1 = "<<ans1<<endl;
    for (int i=11;K>i;i++)
    {
        //cout << "_ = "<<_[ p[i] ]<<" , p = "<<p[i]<<endl;
        ans1 = ans1 + ans1*gao(_[ p[i] ]) + gao( _[ p[i] ] );
        ans1 %= mod;
    }
    printf("%lld\n",ans1);
    //printf("%lld\n",cnt[n%2][0]);
}