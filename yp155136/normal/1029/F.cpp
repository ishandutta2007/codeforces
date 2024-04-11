#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

typedef pair<LL,LL> pii;

vector<pii> va,vb;

LL gee(LL L)
{
    LL ret = (1LL<<62);
    auto iter = lower_bound(va.begin(),va.end(),make_pair(L,(1LL<<60)));
    --iter;
    ret = min(ret,iter->second);
    iter = lower_bound(vb.begin(),vb.end(),make_pair(L,(1LL<<60)));
    --iter;
    ret = min(ret,iter->second);
    return ret;
}

int main ()
{
    LL a,b;
    cin >>a>>b;
    LL ans = (1LL<<62);
    //vector<pii> va,vb;
    for (LL i=1;i*i<=a;++i)
    {
        if (a%i==0)
        {
            va.push_back(make_pair(i,a/i));
        }
    }
    for (LL i=1;i*i<=b;++i)
    {
        if (b%i==0)
        {
            vb.push_back(make_pair(i,b/i));
        }
    }
    LL tmp = a+b;
    for (LL i=1;i*i<=tmp;++i)
    {
        if (tmp%i ==0)
        {
            LL l=i,r = tmp/i;
            //cout << "l = " << l << " ,r = " << r << " ,gee = " << gee(l) << endl;
            if (gee(l) <= r)
            {
                ans = min(ans,l+l+r+r);
            }
        }
    }
    printf("%lld\n",ans);
}