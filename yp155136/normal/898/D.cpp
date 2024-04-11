#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;

int a[N];

struct BIT
{
    int a[N];
    int n;
    void init(int n)
    {
        memset(a,0,sizeof(a));
        this->n = n;
    }
    void update(int pos,int val)
    {
        for (int i=pos;n>=i;i+=i&(-i))
        {
            a[i] += val;
        }
    }
    int query(int pos)
    {
        int ret = 0;
        for (int i=pos;i>0;i-=i&(-i))
        {
            ret += a[i];
        }
        return ret;
    }
    int queryLR(int L,int R)
    {
        return query(R) - query(L-1);
    }
} bit;

int main ()
{
    int n,m,k;
    cin >> n >> m >> k;
    int mm=1000000;
    bit.init(mm);
    for (int i=0;n>i;i++)
    {
        int x;
        cin >> x;
        bit.update(x,1);
        a[x] = 1;
    }
    int ans=0;
    for (int i=1;mm>=i;i++)
    {
        int j=i+m-1;
        if (j>mm) break;
        if (bit.queryLR(i,j) >= k)
        {
            int need_minus = bit.queryLR(i,j) - k + 1;
            for (int kk=j;;kk--)
            {
                if (a[kk])
                {
                    bit.update(kk,-1);
                    a[kk] = 0;
                    need_minus--;
                    ans++;
                }
                if (!need_minus) break;
            }
        }
    }
    cout << ans<<endl;
}