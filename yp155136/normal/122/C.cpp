#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int main ()
{
    vector<LL> v;
    for (int sz=1;9>=sz;sz++)
    {
        for (int i=0;(1<<sz)>i;i++)
        {
            LL now=0;
            for (int j=0;sz>j;j++)
            {
                if (((1<<j)&i) != 0)
                {
                    now *= 10;
                    now += 4;
                }
                else
                {
                    now *= 10;
                    now += 7;
                }
            }
            v.push_back(now);
        }
    }
    v.push_back(4444444444LL);
    sort(v.begin(),v.end());
    /*
    for (LL i:v) cout << i<<' ';
    cout<<endl;
    */
    //cout << "v.size() = "<<v.size()<<endl;
    LL ans=0;
    LL l,r;
    cin >> l >> r;
    while (l <= r)
    {
        //cout << "l = "<<l<<" , r = "<<r<<endl;
        LL now=l;
        LL tmp=*lower_bound(v.begin(),v.end(),now);
        LL L = l;
        LL R = min(r*1LL,tmp);
        ans += (R-L+1)*tmp;
        l = tmp+1;
    }
    printf("%lld\n",ans);
}